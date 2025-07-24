#pragma once
#include<iostream>
using namespace std;
template <class T>
class myarray
{
public:
	//�вι��� ���� ����
	myarray(int capacity)
	{
		//cout << "myarray ���вι���" << endl;
		this->m_capacity = capacity;
		this->m_size = 0;
		pAddress = new T[this->m_capacity];
	}
	//�������죨��ֹǳ���������⣩
	myarray(const myarray& arr)
	{
		//cout << "myarray �Ŀ�������" << endl;
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		//this->pAddress = arr.pAddress;
		//ǳ�����������ϴ��룬����this->pAddress = arr.pAddress; ���д���ᵼ�¶��������ظ��ͷţ�����Ҫ�������

		//����������ڶ�������һ��ռ�
		this->pAddress = new T[this->m_capacity];//�������ж������Ϳ���һ����������

		//��arrԭ�����ڵ����ݿ�������
		for (int i = 0;i < this->m_size;i++)
		{
			this->pAddress[i] = arr.pAddress[i];//��ֵ����
		}
	}
	//operator=��ֹǳ��������
	myarray& operator=(const myarray& arr)
	{
		//cout << "myarray ��operator=����" << endl;
		//���ж�ԭ�������Ƿ������ݣ�����У����ͷ�
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		//���
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[arr.m_capacity];
		//��arrԭ�����ڵ����ݿ�������
		for (int i = 0;i < this->m_size;i++)
		{
			this->pAddress[i] = arr.pAddress[i];//��ֵ����
		}
		return *this;  //��Ϊ����ĵķ��������� myarray&  ��������Ҫ��һ����������
	}

	//β�巨
	void push_back(const T& val)
	{
		//�ж������Ƿ���ڴ�С
		if (this->m_capacity == this->m_size)//���ָ�������Ѿ����ˣ����޷���β����������
		{
			return;
		}
		this->pAddress[this->m_size] = val;//������ĩβ��������
		this->m_size++;//���������С
	}

	//βɾ��
	void pop_back()
	{
		//���һ�������޷����ʣ���ʵ����βɾ
		if (this->m_size == 0)
		{
			return;//�������Ϊ0
		}
		this->m_size--;
	}

	//ͨ���±귽ʽ���������е�Ԫ��  ����[]  arr[0]
	//void operator[](int index)
	T& operator[](int index)//���صĲ�����Ϊ��ֵ���ڣ�����Ҫ��������
	{
		return this->pAddress[index];//���������еĵ�0�ţ�˵�Ժ����ķ�������Ӧ������Ϊ T
	}

	//������������
	int getsize()
	{
		return this->m_size;
	}
	//���������С
	 int getCapacity()
	{
		return this->m_capacity;
	}
	//��������
	~myarray()
	{
		if (this->pAddress != NULL)
		{
			//cout << "myarray ����������" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;    //ָ��ָ��������ٵ���ʵ����
	int m_capacity;
	int m_size;
};