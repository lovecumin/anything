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
	////ͨ��ѧ�����ʹ��������ѧ��
	////��һ�ַ�ʽ struct student s1
	//struct student s1;//�����  struct  ����ʡ��
	//s1.age = 18;
	//s1.name = "ս��";
	//s1.score = 80;
	//cout << s1.age << s1.name<<s1.score<<endl;

	////struct student s1={....}
	///*student s1 = { "sfda",12,84 };
	//cout << s1.age << s1.name << s1.score << endl;*/  
	////����ᱨ����Ϊs1ǰ�涨����ˣ����Բ�������s1�ˣ�Ҫ�����ɱ�ı���
	//student s2 = { "sfda",12,84 };
	//cout << s2.age << s2.name << s2.score << endl;

	////����ṹ���ʱ��˳�㴴��һ���ṹ�����
	//s3.name = "asdga";
	//s3.age = 45;
	//s3.score = 98;
	//cout << s3.age << s3.name << s3.score << endl;



	////�ṹ������
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

	//ͨ���ṹ��ָ����ʽṹ�����
	student s = {"appluo",18,100};
	student* p = &s;
	cout << p->age << p->name << p->score << endl;


	system("pause");
	return 0;
}