//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//#include <string>
//class CPU
//{
//public:
//	virtual void calculate() = 0;
//};
//class videocard
//{
//public:
//	virtual void display() = 0;
//};
//class memory
//{
//public:
//	virtual void storage() = 0;
//};
//
////电脑类 需要调用各个零件的接口
//class computer
//{
//public:
//	computer(CPU* cpu, videocard* videocard, memory* mem)
//	{ 
//		m_cpu = cpu;
//		m_videocard = videocard;
//		m_memory = mem;
//	}
//
//	//使用接口指针，提供供应函数
//	void work()
//	{
//		//让零件工作起来，调用接口
//		m_cpu->calculate();
//		m_videocard->display();
//		m_memory->storage();
//	}
//
//	//释放指针
//	~computer()
//	{
//		if (m_cpu != NULL)
//		{
//			delete m_cpu;
//			m_cpu = NULL;
//		}
//		if (m_videocard != NULL)
//		{
//			delete m_videocard;
//			m_videocard = NULL;
//		}
//		if (m_memory != NULL)
//		{
//			delete m_memory;
//			m_memory = NULL;
//		}
//	}
//private:
//	CPU* m_cpu;
//	videocard* m_videocard;
//	memory* m_memory;
//};
//
//class IntelCPU : public  CPU
//{
//public:
//	void caculate()
//	{
//		cout << "intel的cpu工作起来了" << endl;
//	}
//};
//class Intelvideocard : public  videocard
//{
//public:
//	void dispaly()
//	{
//		cout << "intel的显卡工作起来了" << endl;
//	}
//};
//class Intelmemory : public  memory
//{
//public:
//	void storage()
//	{
//		cout << "intel的内存卡工作起来了" << endl;
//	}
//};
//
//class LenovoCPU : public  CPU
//{
//public:
//	virtual void caculate()
//	{
//		cout << " Lenovo的cpu工作起来了" << endl;
//	}
//};
//class  Lenovovideocard : public  videocard
//{
//public:
//	virtual void dispaly()
//	{
//		cout << " Lenovo的显卡工作起来了" << endl;
//	}
//};
//class  Lenovomemory : public  memory
//{
//public:
//	virtual void storage()
//	{
//		cout << " Lenovo的内存卡工作起来了" << endl;
//	}
//};
//
////测试函数
//void test1()
//{
//	//第一台电脑零件   （提供析构函数释放电脑的零件）
//	CPU* cpu01 = new IntelCPU;//父类的指针指向子类的对象
//	videocard* intelcard = new Intelvideocard;
//	memory* intelmem = new Intelmemory;
//
//	//创建第一台电脑
//	computer* computer1 = new computer(cpu01, intelcard, intelmem);
//	computer1->work();
//	delete computer1;
//}
//
//
//int main()
//{
//	test1();
//
//	system("pause");
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>
class CPU
{
public:
	virtual void Calculator() = 0;
};
class Videocard
{
public:
	virtual void Display() = 0;
};
class MemoryBank
{
public:
	virtual void Storage() = 0;
};

//电脑类 需要调用各个零件的接口
class Computer
{
public:
	Computer(CPU* cpu, Videocard* video, MemoryBank* memory)
	{
		m_cpu = cpu;
		m_videocard = video;
		m_memory = memory;
	}

	//使用接口指针，提供供应函数
	void work()
	{
		//让零件工作起来，调用接口
		m_cpu->Calculator();
		m_videocard->Display();
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
		if (m_videocard != NULL)
		{
			delete m_videocard;
			m_videocard = NULL;
		}
		if (m_memory != NULL)
		{
			delete m_memory;
			m_memory = NULL;
		}
	}
private:
	CPU* m_cpu;
	Videocard* m_videocard;
	MemoryBank* m_memory;
};

class IntelCPU : public  CPU
{
public:
	void Caculator()
	{
		cout << "intel的cpu工作起来了" << endl;
	}
};
class Intelvideocard : public  Videocard
{
public:
	void Dispaly()
	{
		cout << "intel的显卡工作起来了" << endl;
	}
};
class Intelmemory : public  MemoryBank
{
public:
	void Storage()
	{
		cout << "intel的内存卡工作起来了" << endl;
	}
};

class LenovoCPU : public  CPU
{
public:
	void caculate()
	{
		cout << " Lenovo的cpu工作起来了" << endl;
	}
};
class  Lenovovideocard : public  Videocard
{
public:
	void dispaly()
	{
		cout << " Lenovo的显卡工作起来了" << endl;
	}
};
class  Lenovomemory : public  MemoryBank
{
public:
	void storage()
	{
		cout << " Lenovo的内存卡工作起来了" << endl;
	}
};

//测试函数
void test1()
{
	//第一台电脑零件   （提供析构函数释放电脑的零件）
	//CPU* cpu01 = new IntelCPU;//父类的指针指向子类的对象
	CPU* cpu01 = new IntelCPU;
	Videocard* video01 = new Intelvideocard;
	MemoryBank* memory01 = new Intelmemory;

	//创建第一台电脑
	Computer* computer1 = new Computer(cpu01, video01, memory01);
	computer1->work();
	delete computer1;

	Computer* computer02 = new Computer(new Lenovomemory, new Intelmemory, new Intelmemory);
	computer02->work();
	delete computer02;
}


int main()
{
	test1();

	system("pause");
	return 0;
}
