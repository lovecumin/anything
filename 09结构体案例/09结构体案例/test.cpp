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
//	s->score = 602;//���õ�ַ���д���ʱ���������޸��βΣ�ʵ��Ҳ�ᷢ����Ӧ���޸�
//	cout << s->name << s->age << s->score << endl;
//
//
//}
//void prints1(const student* s)//����const ���в��������������޸Ľṹ��s�ˡ�
//{
//	//s->score = 602;//ǰ�����const�����Ժ�����Ͳ����޸���
//	cout << s->name << s->age << s->score << endl;
//
//}
//int main()
//{
//	////�ṹ��Ƕ�׽ṹ��
//	//teacher t;
//	//t.age = 50;
//	//t.id = 1213156;
//	//t.name = "aff";
//	//t.stu.age = 18;
//	//t.stu.name = "buff";
//	//t.stu.score = 98;
//	//cout << " ��ʦ���� " << t.name << " ��ʦid " <<t.id << " ��ʦ���� " << t.age 
//	//	<< " ѧ������ " << t.stu.name << " ѧ������ " << t.stu.score << 
//	//	" ѧ������ " <<t.stu.age << endl;
//	//system("pause");
//
//	//�ṹ������������
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
	//����ʦ��ֵ
	for (int i = 0;i < sz;i++)
	{
		arr[i].name = "teacher_";
		arr[i].name += nameseed[i];
		//ͨ��ѭ����ÿ����ʦ������ѧ����ֵ
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
		cout << "��ʦ�������� " << arr[i].name << endl;
		for (int j = 0;j < 5;j++)
		{
			cout << "\tѧ�������� " << arr[i].sarr[j].name << " ѧ�������� " << arr[i].sarr[j].score << endl;
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
