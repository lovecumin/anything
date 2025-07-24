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
////������ ��Ҫ���ø�������Ľӿ�
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
//	//ʹ�ýӿ�ָ�룬�ṩ��Ӧ����
//	void work()
//	{
//		//������������������ýӿ�
//		m_cpu->calculate();
//		m_videocard->display();
//		m_memory->storage();
//	}
//
//	//�ͷ�ָ��
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
//		cout << "intel��cpu����������" << endl;
//	}
//};
//class Intelvideocard : public  videocard
//{
//public:
//	void dispaly()
//	{
//		cout << "intel���Կ�����������" << endl;
//	}
//};
//class Intelmemory : public  memory
//{
//public:
//	void storage()
//	{
//		cout << "intel���ڴ濨����������" << endl;
//	}
//};
//
//class LenovoCPU : public  CPU
//{
//public:
//	virtual void caculate()
//	{
//		cout << " Lenovo��cpu����������" << endl;
//	}
//};
//class  Lenovovideocard : public  videocard
//{
//public:
//	virtual void dispaly()
//	{
//		cout << " Lenovo���Կ�����������" << endl;
//	}
//};
//class  Lenovomemory : public  memory
//{
//public:
//	virtual void storage()
//	{
//		cout << " Lenovo���ڴ濨����������" << endl;
//	}
//};
//
////���Ժ���
//void test1()
//{
//	//��һ̨�������   ���ṩ���������ͷŵ��Ե������
//	CPU* cpu01 = new IntelCPU;//�����ָ��ָ������Ķ���
//	videocard* intelcard = new Intelvideocard;
//	memory* intelmem = new Intelmemory;
//
//	//������һ̨����
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

//������ ��Ҫ���ø�������Ľӿ�
class Computer
{
public:
	Computer(CPU* cpu, Videocard* video, MemoryBank* memory)
	{
		m_cpu = cpu;
		m_videocard = video;
		m_memory = memory;
	}

	//ʹ�ýӿ�ָ�룬�ṩ��Ӧ����
	void work()
	{
		//������������������ýӿ�
		m_cpu->Calculator();
		m_videocard->Display();
		m_memory->Storage();
	}

	//�ͷ�ָ��
	~Computer()
	{
		cout << "computer ��������" << endl << endl;
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
		cout << "intel��cpu����������" << endl;
	}
};
class Intelvideocard : public  Videocard
{
public:
	void Dispaly()
	{
		cout << "intel���Կ�����������" << endl;
	}
};
class Intelmemory : public  MemoryBank
{
public:
	void Storage()
	{
		cout << "intel���ڴ濨����������" << endl;
	}
};

class LenovoCPU : public  CPU
{
public:
	void caculate()
	{
		cout << " Lenovo��cpu����������" << endl;
	}
};
class  Lenovovideocard : public  Videocard
{
public:
	void dispaly()
	{
		cout << " Lenovo���Կ�����������" << endl;
	}
};
class  Lenovomemory : public  MemoryBank
{
public:
	void storage()
	{
		cout << " Lenovo���ڴ濨����������" << endl;
	}
};

//���Ժ���
void test1()
{
	//��һ̨�������   ���ṩ���������ͷŵ��Ե������
	//CPU* cpu01 = new IntelCPU;//�����ָ��ָ������Ķ���
	CPU* cpu01 = new IntelCPU;
	Videocard* video01 = new Intelvideocard;
	MemoryBank* memory01 = new Intelmemory;

	//������һ̨����
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
