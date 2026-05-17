const MODES = {
  work:       { label: '工作', minutes: 25, color: '#C65A4A' },
  shortBreak: { label: '短休', minutes: 5,  color: '#D9D2CC' },
  longBreak:  { label: '长休', minutes: 15, color: '#D9D2CC' },
};

const RING_RADIUS = 90;
const CIRCUMFERENCE = 2 * Math.PI * RING_RADIUS;
const LONG_BREAK_INTERVAL = 4;

let currentMode   = 'work';
let timeLeft      = MODES.work.minutes * 60;
let totalTime     = MODES.work.minutes * 60;
let timerId       = null;
let isRunning     = false;
let pomodoroCount = 0;
let endTimestamp  = null;  // 目标时间戳，消除 setInterval 累积漂移

const timeDisplay  = document.getElementById('timeDisplay');
const sessionInfo  = document.getElementById('sessionInfo');
const btnStart     = document.getElementById('btnStart');
const btnReset     = document.getElementById('btnReset');
const modeBtns     = document.querySelectorAll('.mode-btn');
const ringProgress = document.querySelector('.ring-progress');

function getModeSeconds(mode) {
  return MODES[mode].minutes * 60;
}

// 复用 AudioContext，避免每次提示音都新建
let audioCtx = null;
function getAudioContext() {
  if (!audioCtx) {
    audioCtx = new window.AudioContext();
  }
  return audioCtx;
}

function playAlarm() {
  const ctx = getAudioContext();
  const notes = [880, 660, 880, 660, 880, 660, 880, 1320];

  notes.forEach((freq, i) => {
    const osc = ctx.createOscillator();
    const gain = ctx.createGain();
    osc.type = 'sine';
    osc.frequency.value = freq;
    gain.gain.setValueAtTime(0.3, ctx.currentTime + i * 0.18);
    gain.gain.exponentialRampToValueAtTime(0.001, ctx.currentTime + i * 0.18 + 0.25);
    osc.connect(gain);
    gain.connect(ctx.destination);
    osc.start(ctx.currentTime + i * 0.18);
    osc.stop(ctx.currentTime + i * 0.18 + 0.25);
  });
}

function notify(title, body) {
  if (Notification.permission === 'granted') {
    new Notification(title, { body });
  } else if (Notification.permission === 'default') {
    Notification.requestPermission().then(p => {
      if (p === 'granted') new Notification(title, { body });
    });
  }
}

function formatTime(seconds) {
  const m = Math.floor(seconds / 60);
  const s = seconds % 60;
  return `${String(m).padStart(2, '0')}:${String(s).padStart(2, '0')}`;
}

function updateDisplay() {
  const text = formatTime(timeLeft);
  timeDisplay.textContent = text;
  document.title = `${text} - 番茄钟`;

  const offset = CIRCUMFERENCE * (1 - timeLeft / totalTime);
  ringProgress.style.strokeDashoffset = offset;
}

function updateSessionInfo() {
  sessionInfo.textContent = `番茄 #${pomodoroCount + 1}`;
}

function setMode(mode) {
  currentMode = mode;
  stopTimer();
  timeLeft  = getModeSeconds(mode);
  totalTime = getModeSeconds(mode);

  ringProgress.classList.toggle('break-mode', mode !== 'work');
  updateDisplay();
  updateButtonState();

  modeBtns.forEach(b => b.classList.toggle('active', b.dataset.mode === mode));
}

function stopTimer() {
  clearInterval(timerId);
  timerId = null;
  isRunning = false;
  endTimestamp = null;
}

function updateButtonState() {
  if (isRunning) {
    btnStart.textContent = '暂停';
    btnStart.classList.add('pause-state');
  } else {
    btnStart.textContent = '开始';
    btnStart.classList.remove('pause-state');
  }
}

function tick() {
  const now = Date.now();
  const remaining = Math.max(0, Math.round((endTimestamp - now) / 1000));

  if (remaining !== timeLeft) {
    timeLeft = remaining;
    updateDisplay();
  }

  if (remaining <= 0) {
    stopTimer();
    updateButtonState();
    playAlarm();

    if (currentMode === 'work') {
      pomodoroCount++;
      updateSessionInfo();
      notify('🍅 番茄完成！', `已累计完成 ${pomodoroCount} 个番茄，休息一下吧！`);
      const nextMode = pomodoroCount % LONG_BREAK_INTERVAL === 0 ? 'longBreak' : 'shortBreak';
      setMode(nextMode);
    } else {
      notify('休息结束', '开始新的番茄吧！');
      setMode('work');
    }
  }
}

function toggleTimer() {
  if (isRunning) {
    stopTimer();
    updateButtonState();
    return;
  }

  isRunning = true;
  // 以当前时间为基准，计算目标结束时间戳，消除 setInterval 累积漂移
  endTimestamp = Date.now() + timeLeft * 1000;
  updateButtonState();
  updateDisplay();
  timerId = setInterval(tick, 200);  // 200ms 精度足够，比 1000ms 更及时归零
}

function resetTimer() {
  stopTimer();
  timeLeft  = getModeSeconds(currentMode);
  totalTime = getModeSeconds(currentMode);
  updateDisplay();
  updateButtonState();
}

btnStart.addEventListener('click', toggleTimer);
btnReset.addEventListener('click', resetTimer);

modeBtns.forEach(btn => {
  btn.addEventListener('click', () => setMode(btn.dataset.mode));
});

document.addEventListener('keydown', e => {
  if (e.code === 'Space') {
    e.preventDefault();
    toggleTimer();
  }
});

updateDisplay();
updateSessionInfo();
