#pragma once
#include<iostream>
using namespace std;

#include<string>
template<class t1, class t2>
class person
{
public:
	person(t1 name, t2 age);
	void showperson();

	t1 name;
	t2 age;
};

template<class t1, class t2>
person<t1, t2>::person(t1 name, t2 age)
{
	this->name = name;
	this->age = age;
}
template<class t1, class t2>
void person<t1, t2>::showperson()
{
	cout << "name: " << this->name << endl;
}