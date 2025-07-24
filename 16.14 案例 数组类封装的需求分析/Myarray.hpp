#pragma once
#include<iostream>
using namespace std;
template <class T>
class myarray
{
public:
	//有参构造 参数 容量
	myarray(int capacity)
	{
		//cout << "myarray 的有参构造" << endl;
		this->m_capacity = capacity;
		this->m_size = 0;
		pAddress = new T[this->m_capacity];
	}
	//拷贝构造（防止浅拷贝的问题）
	myarray(const myarray& arr)
	{
		//cout << "myarray 的拷贝构造" << endl;
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		//this->pAddress = arr.pAddress;
		//浅拷贝就是以上代码，但是this->pAddress = arr.pAddress; 这行代码会导致堆区数据重复释放，所以要进行深拷贝

		//深拷贝，重新在堆区开辟一块空间
		this->pAddress = new T[this->m_capacity];//传进来有多大数组就开辟一个多大的数组

		//将arr原来存在的数据拷贝进来
		for (int i = 0;i < this->m_size;i++)
		{
			this->pAddress[i] = arr.pAddress[i];//数值传递
		}
	}
	//operator=防止浅拷贝问题
	myarray& operator=(const myarray& arr)
	{
		//cout << "myarray 的operator=调用" << endl;
		//先判断原来堆区是否有数据，如果有，先释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		//深拷贝
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[arr.m_capacity];
		//将arr原来存在的数据拷贝进来
		for (int i = 0;i < this->m_size;i++)
		{
			this->pAddress[i] = arr.pAddress[i];//数值传递
		}
		return *this;  //因为上面的的返回类型是 myarray&  所以这里要有一个返回自身
	}

	//尾插法
	void push_back(const T& val)
	{
		//判断容量是否等于大小
		if (this->m_capacity == this->m_size)//如果指针数组已经满了，就无法在尾部插入数据
		{
			return;
		}
		this->pAddress[this->m_size] = val;//在数组末尾插入数据
		this->m_size++;//更新数组大小
	}

	//尾删法
	void pop_back()
	{
		//最后一个数据无法访问，就实现了尾删
		if (this->m_size == 0)
		{
			return;//如果数组为0
		}
		this->m_size--;
	}

	//通过下标方式访问数组中的元素  重载[]  arr[0]
	//void operator[](int index)
	T& operator[](int index)//返回的参数作为左值存在，所以要加上引用
	{
		return this->pAddress[index];//返回数组中的第0号，说以函数的返回类型应该设置为 T
	}

	//返回数组容量
	int getsize()
	{
		return this->m_size;
	}
	//返回数组大小
	 int getCapacity()
	{
		return this->m_capacity;
	}
	//析构函数
	~myarray()
	{
		if (this->pAddress != NULL)
		{
			//cout << "myarray 的析构函数" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;    //指针指向堆区开辟的真实数组
	int m_capacity;
	int m_size;
};