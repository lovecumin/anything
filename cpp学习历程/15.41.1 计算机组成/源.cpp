#include<iostream>
#include<string>
using namespace std;


//抽象零件类
class CPU
{
public:
	virtual void Calculator() = 0;

};

class VideoCard //显卡
{
public:
	virtual void Display() = 0;

};

class MemoryBank
{
public:
	virtual void Storage() = 0;

};


//电脑类 :需要调用各个零件的接口
class Computer
{
public:
	//接收指针
	Computer(CPU* cpu, VideoCard* video, MemoryBank* memory)
	{
		m_cpu = cpu;
		m_video = video;
		m_memory = memory;
	}

	//使用接口指针，提供工作的函数
	void Work()
	{
		m_cpu->Calculator();
		m_video->Display();
		m_memory->Storage();
	}

	//释放指针
	~Computer()
	{
		cout << "computer 析构函数" << endl << endl;
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_video != NULL)
		{
			delete m_video;
			m_video = NULL;
		}
		if (m_memory != NULL)
		{
			delete m_memory;
			m_memory = NULL;
		}
	}

private:
	CPU* m_cpu;
	VideoCard* m_video;
	MemoryBank* m_memory;

};

//零件的子类
//1、Intel厂商
class IntelCPU :public CPU
{
public:
	void Calculator()
	{
		cout << "Intel的CPU在计算" << endl;
	}
};


class IntelVideoCard :public VideoCard
{
public:
	void Display()
	{
		cout << "Intel的显卡在显示" << endl;
	}
};

class IntelMemoryBank :public MemoryBank
{
public:
	void Storage()
	{
		cout << "Intel的内存在存储" << endl;
	}
};


//2、Lenovo厂商
class LenovoCPU :public CPU
{
public:
	void Calculator()
	{
		cout << "Lenovo的CPU在计算" << endl;
	}
};


class LenovoVideoCard :public VideoCard
{
public:
	void Display()
	{
		cout << "Lenovo的显卡在显示" << endl;
	}
};

class LenovoMemoryBank :public MemoryBank
{
public:
	void Storage()
	{
		cout << "Lenovo的内存在存储" << endl;
	}
};





//测试函数
void test01()
{
	//第一台电脑的零件
	CPU* cpu01 = new IntelCPU;
	VideoCard* video01 = new IntelVideoCard;
	MemoryBank* memory01 = new IntelMemoryBank;

	//创建第一台电脑
	//使用new创建对象，必须准备一个指针来接收
	Computer* computer01 = new Computer(cpu01, video01, memory01);
	computer01->Work();
	delete computer01;


	//创建第二台电脑
	Computer* computer02 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemoryBank);
	computer02->Work();
	delete computer02;


	//创建第三台电脑
	Computer* computer03 = new Computer(new LenovoCPU, new IntelVideoCard, new IntelMemoryBank);
	computer03->Work();
	delete computer03;



}

int main()
{
	test01();
	system("pause");
	return 0;
}