#include<iostream>
#include<string>
using namespace std;


//���������
class CPU
{
public:
	virtual void Calculator() = 0;

};

class VideoCard //�Կ�
{
public:
	virtual void Display() = 0;

};

class MemoryBank
{
public:
	virtual void Storage() = 0;

};


//������ :��Ҫ���ø�������Ľӿ�
class Computer
{
public:
	//����ָ��
	Computer(CPU* cpu, VideoCard* video, MemoryBank* memory)
	{
		m_cpu = cpu;
		m_video = video;
		m_memory = memory;
	}

	//ʹ�ýӿ�ָ�룬�ṩ�����ĺ���
	void Work()
	{
		m_cpu->Calculator();
		m_video->Display();
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

//���������
//1��Intel����
class IntelCPU :public CPU
{
public:
	void Calculator()
	{
		cout << "Intel��CPU�ڼ���" << endl;
	}
};


class IntelVideoCard :public VideoCard
{
public:
	void Display()
	{
		cout << "Intel���Կ�����ʾ" << endl;
	}
};

class IntelMemoryBank :public MemoryBank
{
public:
	void Storage()
	{
		cout << "Intel���ڴ��ڴ洢" << endl;
	}
};


//2��Lenovo����
class LenovoCPU :public CPU
{
public:
	void Calculator()
	{
		cout << "Lenovo��CPU�ڼ���" << endl;
	}
};


class LenovoVideoCard :public VideoCard
{
public:
	void Display()
	{
		cout << "Lenovo���Կ�����ʾ" << endl;
	}
};

class LenovoMemoryBank :public MemoryBank
{
public:
	void Storage()
	{
		cout << "Lenovo���ڴ��ڴ洢" << endl;
	}
};





//���Ժ���
void test01()
{
	//��һ̨���Ե����
	CPU* cpu01 = new IntelCPU;
	VideoCard* video01 = new IntelVideoCard;
	MemoryBank* memory01 = new IntelMemoryBank;

	//������һ̨����
	//ʹ��new�������󣬱���׼��һ��ָ��������
	Computer* computer01 = new Computer(cpu01, video01, memory01);
	computer01->Work();
	delete computer01;


	//�����ڶ�̨����
	Computer* computer02 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemoryBank);
	computer02->Work();
	delete computer02;


	//��������̨����
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