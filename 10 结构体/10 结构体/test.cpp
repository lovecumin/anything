//#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
struct student 
{
	
	string name;
	int age;
	int score;
}s3;

int main()
{
	////通过学生类型创建具体的学生
	////第一种方式 struct student s1
	//struct student s1;//这里的  struct  可以省略
	//s1.age = 18;
	//s1.name = "战三";
	//s1.score = 80;
	//cout << s1.age << s1.name<<s1.score<<endl;

	////struct student s1={....}
	///*student s1 = { "sfda",12,84 };
	//cout << s1.age << s1.name << s1.score << endl;*/  
	////这里会报错，因为s1前面定义过了，所以不能再用s1了，要更换成别的变量
	//student s2 = { "sfda",12,84 };
	//cout << s2.age << s2.name << s2.score << endl;

	////定义结构体的时候顺便创建一个结构体变量
	//s3.name = "asdga";
	//s3.age = 45;
	//s3.score = 98;
	//cout << s3.age << s3.name << s3.score << endl;



	////结构体数组
	//student stuarr[3] =
	//{
	//	{"obb",18,100},
	//	{"size",18,87},
	//	{"adfa",23,67}
	//};
	//stuarr[2].name = "phil";
	//stuarr[2].age = 21;
	//stuarr[2].score = 88;
	//for (int i = 0;i < 3;i++)
	//{
	//	cout <<"name "<< stuarr[i].name 
	//		<< " age: "<<stuarr[i].age 
	//		<<" score "<< stuarr[i].score << endl;
	//}

	//通过结构体指针访问结构体变量
	student s = {"appluo",18,100};
	student* p = &s;
	cout << p->age << p->name << p->score << endl;


	system("pause");
	return 0;
}