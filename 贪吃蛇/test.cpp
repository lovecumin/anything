#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#define up 'w'
#define down 's'
#define left 'a'
#define right 'd'
#define stop 'p'
#define add_speed 'j'
#define down_speed 'l'

constexpr auto i_min = 35;                                     //������Ϸ��ʼ�߿��ȷ�� 
constexpr auto i_max = 85;
constexpr auto j_min = 17;
constexpr auto j_max = 23;

struct snake {
	int x;
	int y;
	struct snake* next;                                         //Ϊʹ��������׼��
};   //�ߵĽṹ��

const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);         //��׼����ľ��
struct snake* tail, * head, * food_1;
int i = 0;                                                     //��������ɼ�
int max;                                                       //�ɼ������ֵ
int sleeptime = 200;                                           //ͨ��sleeptime�������ٶ�
char click = 1;                                                //������̵�����
int rand_color = 3;                                            //������������������ʳ�����ɫ��������
int last_color = 3;                                            //������һ�β��������

void color(int i);                                              //ͨ������������ı��������ɫ
void gotoxy(int x, int y);                                      //������Ƶ�(x,y)��
void start_play();                                              //��ʼ��Ϸ
void square(int i_min1, int i_max1, int j_min1, int j_max1);    //����һ�����ο�
void game_over(int k);                                          //��Ϸ����
void make_map();                                                //���ص�ͼ
void text();                                                    //�����ı�
void init_snake();                                              //��ʼ���ߵ�����
void food();                                                    //��ʼ��ʳ��
void file_scanf();                                              //����save.txt����ɼ������ֵ
void file_printf();                                             //�����ֵд��save.txt
void gotodelete(int i, int y);                                  //��մ������������
void change_body(int a, int b);                                 //�ı�������λ��
void gotoprint(int x, int y);                                   //��ӡ��
void MovingBody();                                              //�ƶ���
void ClickControl();                                            //�õ����̵�����
void eating();                                                  //���߳Ե�����ʱ
int judge();                                                    //�ж����Ƿ�ײ������
void refresh();                                                 //ˢ�³ɼ����ٶ�

void file_printf()
{
	FILE* fp;
	fopen_s(&fp, "./save.txt", "w+");                                 //����Ḳ��֮ǰ��ֵ
	if (fp != NULL)
		fprintf(fp, "%d", i);
	fclose(fp);
}

void game_over(int k)
{
	int j;
	file_scanf();                                                    //����save.txt����ɼ������ֵ
	system("cls");
	square(20, 100, 5, 20);
	gotoxy(55, 8);
	color(7);
	printf("(���n��)\n");
	color(6);
	gotoxy(44, 11);
	if (k == 0)                                                         //�ж���Ϸ������ԭ��
		printf("�ÿ�ϧѽ����ײǽ�ˣ���Ϸ����\n");
	else
		printf("�ÿ�ϧѽ����ײ���Լ��ˣ���Ϸ����\n");
	gotoxy(54, 14);
	color(10);
	printf("��ĵ÷���%d", i);
	gotoxy(38, 17);
	if (i < max)                                                      //�жϳɼ��Ƿ�������ֵ
		printf("��^_^������Ŭ���ɣ�������߷ֻ���%d", max - i);
	else
	{
		printf("��^_^��̫�����˰ɣ���ˢ���˼�¼,������߷���%d", i);
		file_printf();                                                 //�ɼ��������ֵ�����ɼ�д���ļ�
	}
	gotoxy(40, 22);
	printf("[1]����һ��\t\t\t[2]��·��");
	gotoxy(52, 24);
	printf("��ѡ��[1 2]:[ ]");
	gotoxy(65, 24);
	scanf_s("%d", &j);
	switch (j)                                                         //��ѡ������ж�
	{
	case 1:
		system("cls");
		i = 0;                                                         //Ϊ������׼�������ɼ����ٶȱ�ɳ�ʼֵ
		sleeptime = 200;
		make_map();
		ClickControl();
		break;
	case 2:
		gotoxy(65, 25);
		printf("�����˳���Ϸ...");
		Sleep(500);
		system("cls");
		exit(0);
	}
}

void change_body(int a, int b)
{
	snake* p;
	p = head;
	int x, y, x1, y1;
	x = a;
	y = b;
	p = p->next;
	while (p->next != NULL)                                            //���⽫head������ƶ�����ǰһ����λ����
	{
		x1 = p->x;
		y1 = p->y;
		p->x = x;
		p->y = y;
		x = x1;
		y = y1;
		p = p->next;
	}
}

void eating()
{
	snake* now, * p;
	if (food_1->x == head->x && food_1->y == head->y)                        //�ж����Ƿ�Ե�ʳ��
	{
		food();
		now = (snake*)malloc(sizeof(snake));
		p = head;
		while (p->next->next != NULL)
			p = p->next;
		now->next = p->next;
		p->next = now; //��һ��β��
		i += 10;                                                              //���Ե�����ʱ���ɼ�+10���ٶ�����
		if (sleeptime >= 40)
			sleeptime -= 10;
		refresh();                                                          //�Գɼ����ٶȽ���ˢ��
	}
}

void gotodelete(int i, int y)
{
	gotoxy(i, y);
	printf("  ");
}

void MovingBody()
{
	int a = head->x, b = head->y;
	snake* p = head;
	while (p->next != NULL)                                                   //ͨ������պ��ӡʵ�ֶ���Ч��
	{
		gotodelete(p->x, p->y);
		p = p->next;
	}
	switch (click)                                                      //�԰��µļ��̽����ж�
	{
	case up:
		head->y -= 1;
		change_body(a, b);
		break;
	case down:
		head->y += 1;
		change_body(a, b);
		break;
	case left:
		head->x -= 2;
		change_body(a, b);
		break;
	case right:
		head->x += 2;
		change_body(a, b);
		break;
	case stop:
		break;
	case add_speed:                                                       //ͨ���ı�sleeptime���ﵽ����
		if (sleeptime >= 50)
		{
			sleeptime -= 10;
			i += 5;
		}
		refresh();
		break;
	case down_speed:
		if (sleeptime <= 200)
		{
			sleeptime += 10;
			i -= 5;
		}
		refresh();
		break;
	}
	p = head;
	eating();                                                              //�����Ƿ�Ե�����
	while (p->next != NULL)                                                //��ӡ��
	{
		gotoprint(p->x, p->y);
		p = p->next;
	}
	p = head;
	gotoxy(0, 28);                                                         //������Ĺ����(0,28)��
	Sleep(sleeptime);
}

int judge()
{
	int i_min2 = 0, i_max2 = 56, j_min2 = 0, j_max2 = 26;
	snake* q;
	q = head->next;
	while (q->next != NULL)
	{
		if (head->x == q->x && head->y == q->y)
		{
			game_over(1);                                                   //1����ײ���Լ���
			return 1;
		}
		q = q->next;
	}
	if (head->x == i_min2 || head->x == i_max2 || head->y == j_min2 || head->y == j_max2)
	{
		game_over(0);                                                      //2����ײ��ǽ��
		return 1;
	}
	else
		return 0;
}

void ClickControl()
{
	click = 'p';                                                        //Ϊ������׼��
	while (judge() == 0)                                                  //�ж��Ƿ�ײ������
	{
		if (_kbhit())                                                   //�ж��Ƿ��м��̰���
		{
			click = _getch();
		}
		MovingBody();
	}

}

void food()
{
	srand((unsigned)time(NULL));
	struct snake* q;
	food_1 = (snake*)malloc(sizeof(snake));
	do
	{
		food_1->x = rand() % 52 + 2;
	} while ((food_1->x % 2) != 0);                                   //ʳ��������֣�ʳ���x������2~53����Ϊż��
	food_1->y = rand() % 24 + 1;
	q = head;
	while (q != NULL)
	{
		if (q->x == food_1->x && q->y == food_1->y)                   //�ж�ʳ���ǲ������ߵ�������
		{
			free(food_1);
			food();
		}
		q = q->next;
	}
	last_color = rand_color;                                          //ͨ�������ʵ���߳Ը�ʲô��ɫ��ʳ��ͱ�ʲô��ɫ
	srand((unsigned)time(NULL));
	color(rand_color = rand() % 10 + 1);                                //�������1~10����ɫ
	gotoxy(food_1->x, food_1->y);                                     //��ӡʳ��
	printf("��");
}

void gotoprint(int x, int y)
{
	color(last_color);
	gotoxy(x, y);
	printf("��");
}

void init_snake()
{
	int i, k, j;
	srand((unsigned)time(NULL));                                      //���²��֣������ڲ��������
	tail = (snake*)malloc(sizeof(snake));
	do
	{
		k = rand() % 46 + 2;
	} while ((k % 2) != 0);											  //��ͷx������2~47����Ϊż��
	j = rand() % 22 + 1;                                               //��ͷy������2~47
	tail->x = k;
	tail->y = j;                                                      //ʵ��̰���ߵ��������
	tail->next = NULL;
	for (i = 1; i < 5; i++)                                           //�����ĸ�������
	{
		head = (snake*)malloc(sizeof(snake));
		head->next = tail;
		head->x = k + i * 2;
		head->y = j;
		tail = head;
	}
	while (tail->next != NULL)                                        //��ӡ��
	{
		gotoprint(tail->x, tail->y);
		tail = tail->next;
	}
	food();                                                           //����ʳ��
}

void square(int i_min1, int i_max1, int j_min1, int j_max1)
{
	int i, j;
	color(3);
	for (j = j_min1; j <= j_max1; j++)
	{
		for (i = i_min1; i <= i_max1; i++)
		{
			gotoxy(i, j);
			if (j == j_min1 || j == j_max1)
				printf("-");
			else if (i == i_min1 || i == i_max1)
				printf("|");
		}
		printf("\n");
	}
}

void refresh()
{
	color(i / 10);
	gotoxy(76, 10);
	printf("   �ǰ�÷�:%d(^_^;)��", i);
	gotoxy(76, 12);
	printf("  �ǰ�ٶ�:%d(��_��;)��", (21 - sleeptime / 10));
}

void file_scanf()
{
	FILE* fp;
	fopen_s(&fp, "./save.txt", "r+");
	if (fp != NULL)                                                   //�ж��ļ����Ƿ�ɹ�
		fscanf_s(fp, "%d", &max);
	fclose(fp);
}

void text()
{
	file_scanf();
	color(3);
	gotoxy(60, 4);
	printf("\t\t\t\t( ^��^)");
	gotoxy(76, 7);
	printf("   ����߷ּ�¼:%d��", max);                              //��ӡ��߷�
	color(6);
	refresh();                                                        //��Ϊ�ɼ����ٶȻ�仯����Ҫ����ı�ʱˢ��
	gotoxy(76, 14);
	color(9);
	printf("\t   С��ʾ");                                            //��ӡһЩ��ʾ
	square(65, 115, 15, 28);
	gotoxy(66, 17);
	printf("tip1: ����ײǽ������ҧ���Լ�");
	gotoxy(66, 19);
	printf("tip2: ��Ӣ�ĵ�w.s.a.d�ֱ�����ߵ��ƶ�");
	gotoxy(66, 21);
	printf("tip3: ���ո����ͣ��Ϸ,��Ҫ�ٴΰ�w.s.a.d�ſ��Զ�");
	gotoxy(66, 23);
	printf("top4: ��j����l����,��Ҫ�ٴΰ�w.s.a.d�ſ��Զ�");
	gotoxy(66, 25);
	printf("top5:  ��ʼʱ�ߵ�ͷ���ұ�");
	gotoxy(66, 27);
	printf("���ڼ�������ԭ����Ϸ������һЩbug�����");
	gotoxy(66, 29);
}

void make_map()
{
	color(3);
	int i, j, i_min2 = 0, i_max2 = 56, j_min2 = 0, j_max2 = 26;
	for (j = j_min2; j <= j_max2; j++)                                 //���ص�ͼ
	{
		for (i = i_min2; i <= i_max2; i += 2)
		{
			gotoxy(i, j);
			if (j == j_min2 || j == j_max2)
				printf("��");
			else
			{
				if (i == i_min2 || i == i_max2)
					printf("��");
			}
		}
		printf("\n");
	}
	text();                                                          //��������
	init_snake();                                                    //��ʼ������
}

void color(int i) //3 Ϊ��ɫ 4 Ϊ��ɫ
{
	SetConsoleTextAttribute(handle, i);                           //�ı��������ɫ
}

void gotoxy(int x, int y)
{
	COORD c;                                                     //COORD��һ���ṹ��
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(handle, c);                         //���ù���λ��
}

void start_play()
{
	int i, j;
	gotoxy(i_min + 20, j_min - 2);                                //������Ϸ��ʼ�Ľ���
	color(4);
	printf("̰ �� �� �� Ϸ");
	gotoxy(i_min + 5, j_min + 2);
	printf("[1]��ʼ��Ϸ\t\t  [2]��Ϸ˵��");
	gotoxy(i_min + 5, j_min + 4);
	printf("[3]�˳���Ϸ");
	color(3);
	square(i_min, i_max, j_min, j_max);                           //������ο�
	gotoxy(i_min, j_max + 1);
	printf("��ѡ��[1 2 3]:[ ]");
	gotoxy(i_min + 15, j_max + 1);
	scanf_s("%d", &i);
	switch (i)                                                     //��ѡ������ж�
	{
	case 1:
		system("cls");                                        //����
		make_map();
		ClickControl();
		break;
	case 2:
		system("cls");
		text();
		gotoxy(20, 12);
		printf("[1]������Ϸ   [2]�˳���Ϸ");
		gotoxy(20, 14);
		printf("��ѡ��[1 2]:[ ]");
		gotoxy(33, 14);
		scanf_s("%d", &i);
		if (i == 1)
		{
			system("cls");
			make_map();
			ClickControl();
			break;
		}                                                      //���iΪ2�������case3��
	case 3:
		printf("�����˳���Ϸ...");
		Sleep(500);                                            //�����ӳ�Ч����ʹ��ҿ������ӡ������
		system("cls");
		exit(0);
	default:
		gotoxy(i_min + 15, j_max + 2);
		printf("������1~3֮�����������");
		Sleep(300);
		system("cls");
		start_play();
	}
}

int main(void)
{
	start_play();
	return 0;
}



#include<iostream>
#include<string>
using namespace std;

//һ�����ࣨPoint��
class Point
{

public:
	//����x����
	void setX(int x)
	{
		p_x = x;
	}

	//��ȡx����
	int getX()
	{
		return p_x;
	}

	//����y����
	void setY(int y)
	{
		p_y = y;
	}

	//��ȡy����
	int getY()
	{
		return p_y;
	}

private:
	int p_x;
	int p_y;
};

//���һ��Բ��Circle
class Circle
{

public:
	//���ð뾶R
	void setR(int r)
	{
		R = r;
	}

	//��ȡ�뾶R
	int getR()
	{
		return R;
	}

	//����Բ��
	void setCenter(Point center)
	{
		c_center = center;
	}

	//��ȡԲ��
	Point getCenter()//c_center��Piont�������
	{
		return c_center;
	}


private:
	int R;
	//�����п�������һ���� ��Ϊ�����еĳ�Ա--��ṹ������
	Point c_center;

};

//�жϵ��Բ�Ĺ�ϵ
void isInCircle(Circle& c, Point& p)
{
	if ((p.getX() - c.getCenter().getX()) * (p.getX() - c.getCenter().getX()) + (p.getY() - c.getCenter().getY()) * (p.getY() - c.getCenter().getY()) == c.getR() * c.getR())
		cout << "����Բ��" << endl;
	else if ((p.getX() - c.getCenter().getX()) * (p.getX() - c.getCenter().getX()) + (p.getY() - c.getCenter().getY()) * (p.getY() - c.getCenter().getY()) > c.getR() * c.getR())
		cout << "����Բ��" << endl;
	else
		cout << "����Բ��" << endl;
}

int main()
{
	//���������õ�P1
	Point P1;
	P1.setX(10);
	P1.setY(9);

	//���������õ�P2--Բ��
	Point P2;
	P2.setX(10);
	P2.setY(0);

	//����ԲC1
	Circle C1;
	C1.setR(10);
	C1.setCenter(P2);

	isInCircle(C1, P1);

	system("pause");
	return 0;
}
