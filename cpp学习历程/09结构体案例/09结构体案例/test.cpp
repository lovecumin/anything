#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//struct student
//{
//	string name;
//	int age;
//	int score;
//};
//struct teacher
//{
//	int id;
//	string name;
//	int age;
//	struct student stu;
//};
//void prints(student s)
//{
//	cout << s.name << s.age << s.score << endl;
//}
//void prints1(student* s)
//{
//	s->score = 602;//利用地址进行传参时，不仅会修改形参，实参也会发生相应的修改
//	cout << s->name << s->age << s->score << endl;
//
//
//}
//void prints1(const student* s)//加入const 进行参数保护，不能修改结构体s了。
//{
//	//s->score = 602;//前面加了const修饰以后，这里就不能修改了
//	cout << s->name << s->age << s->score << endl;
//
//}
//int main()
//{
//	////结构体嵌套结构体
//	//teacher t;
//	//t.age = 50;
//	//t.id = 1213156;
//	//t.name = "aff";
//	//t.stu.age = 18;
//	//t.stu.name = "buff";
//	//t.stu.score = 98;
//	//cout << " 老师姓名 " << t.name << " 老师id " <<t.id << " 老师年龄 " << t.age 
//	//	<< " 学生姓名 " << t.stu.name << " 学生分数 " << t.stu.score << 
//	//	" 学生年龄 " <<t.stu.age << endl;
//	//system("pause");
//
//	//结构体做函数参数
//	student s = { "tim",28,600 };
//	prints(s);
//	prints1(&s);
//	cout << s.name << s.age << s.score << endl;
//	return 0;
//}


#include<iostream>
#include<string>
#include<time.h>
using namespace std;
struct stu
{
	string name;
	int score;
};
struct teacher
{
	string name;
	stu sarr[5];
};
void tea_inf(teacher arr[], int sz)
{
	string nameseed = "abcde";
	//给老师赋值
	for (int i = 0;i < sz;i++)
	{
		arr[i].name = "teacher_";
		arr[i].name += nameseed[i];
		//通过循环给每名老师所带的学生赋值
		for (int j = 0;j < 5;j++)
		{
			arr[i].sarr[j].name = "student_";
			arr[i].sarr[j].name += nameseed[j];
			int random = rand() % 61 + 40;
			arr[i].sarr[j].score = random;
		}
	}
}
void printinfo(teacher arr[],int sz)
{
	for (int i = 0;i < sz;i++)
	{
		cout << "老师的姓名： " << arr[i].name << endl;
		for (int j = 0;j < 5;j++)
		{
			cout << "\t学生姓名： " << arr[i].sarr[j].name << " 学生分数： " << arr[i].sarr[j].score << endl;
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	struct teacher arr[3];
	int sz = sizeof(arr) / sizeof(arr[0]);
	tea_inf(arr, sz);
	printinfo(arr,sz);
	system("pause");
	return 0;

}
