#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
#define max 100
struct  person
{
	string name;
	int sex;
	int age;
	string phone;
	string addr;
};
struct adderssbooks
{
	struct person personarray[max];
	int size;
};

void addPerson(adderssbooks* abs)
{
	//判断通讯录是否满了
	if (abs->size == max)
	{
		cout << "通讯录是否已经满了！" << endl;
		return ;
	}
	else//添加联系人
	{
		//姓名
		string name;//
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personarray[abs->size].name = name;

		//性别
		cout << "请输入性别（数字）" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
		while (1)
		{
			int sex = 0;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->size].sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入" << endl;
			}
		}
		//年纪
		int age = 0;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personarray[abs->size].age = age;
		//电话

		string phone = "";
		cout << "请输入电话" << endl;
		cin >> phone;
		abs->personarray[abs->size].phone = phone;

		//住址
		string add = "";

		cout << "请输入地址" << endl;
		cin >> add;
		abs->personarray[abs->size].addr = add;

		abs->size++;
		cout << "添加成功" << endl;
		system("pause");//按任意键继续
		system("cls");//清屏
	}
}
void showPerson(adderssbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		for (int i = 0;i < abs->size;i++)
		{
			cout << "姓名：" << abs->personarray[i].name << "\t";
			cout << "性别：" << (abs->personarray[i].sex==1?"男":"女") << "\t";
			cout << "电话：" << abs->personarray[i].phone << "\t";
			cout << "年龄：" << abs->personarray[i].age << "\t";
			cout << "住址：" << abs->personarray[i].addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//检测联系人是否存在，如果存在，返回所在位置，不存在返回-1
int isExist(adderssbooks* abs,string name)
{
	for (int i = 0;i < abs->size;i++)
	{
		if (abs->personarray[i].name == name)
		{
			return i;
		}	
	}
	return -1;
}
void deleperson(adderssbooks* abs)
{
	string name;//这里要定义
	cout << "输入你想要删除的人" << endl;
	cin >> name;
	
	int ret = isExist(abs,name);
	if (ret!= -1)
	{
		for (int i = ret;i < abs->size;i++)
		{
			abs->personarray[i] = abs->personarray[i + 1];//数据前移，后一个联系人数据覆盖前一个的
		}
		abs->size--;
		cout << "删除成功" << endl;
	}
	else
		cout << "查无此人" << endl;
	system("pause");
	system("cls");
}
void findperson(adderssbooks* abs)
{
	cout << "请输入要查找的联系人" << endl;
	string name;
	cin>>name;
	int ret = isExist(abs,name);
	if (ret != -1)
	{
			cout << "姓名：" << abs->personarray[ret].name << "\t";
			cout << "性别：" << (abs->personarray[ret].sex==1?"男":"女") << "\t";
			cout << "电话：" << abs->personarray[ret].phone << "\t";
			cout << "年龄：" << abs->personarray[ret].age << "\t";
			cout << "住址：" << abs->personarray[ret].addr << endl;
	}
	else
		cout << "查无此人" << endl;
	system("pause");
	system("cls");
}

void modifperson(adderssbooks* abs)
{
	cout<< "请输入要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personarray[ret].name = name;
		
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int  sex = 0;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[ret].sex == sex;
				break;
			}
			else
			{
				cout<<"输入有误请从新输入" << endl;
			}
		}

		cout <<"请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[ret].age = age;

		cout << "请输入电话" << endl;
		string phone ;
		cin >> phone;
		abs->personarray[ret].phone = phone;

		cout << "请输入住址" << endl;
		string add;
		cin >> add;
		abs->personarray[ret].addr = add;
		
		cout<<"修改成功!" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void cleanPerson(adderssbooks* abs)
{
	
	abs->size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}


void showMenu()
{
	cout << "******* 1.添加联系人 ********" << endl;
	cout << "******* 2.显示联系人 ********" << endl;
	cout << "******* 3.删除联系人 ********" << endl;
	cout << "******* 4.查找联系人 ********" << endl;
	cout << "******* 5.修改联系人 ********" << endl;
	cout << "******* 6.清空联系人 ********" << endl;
	cout << "******* 0.退出程序   ********" << endl;
}

int main()
{
	int input = 0;
	adderssbooks abs;
	abs.size = 0;//要定义到循环的前面，abs.size不能每一次都为0
	while (true)
	{
		showMenu();
		cout << "请做出选择" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			addPerson(&abs);//利用地址传递，可以修改实参
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
	/*	{
			cout << "请输入要删除人的姓名" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "找到了" << endl;
			}
		}*/
			deleperson(&abs);
			break;
		case 4:
			findperson(&abs);
			break;
		case 5:
			modifperson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			cout << "******* 6.清空联系人 ********" << endl;
			break;
		case 0:
			cout << " 退出通讯录 ，欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
