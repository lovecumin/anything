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
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->size == max)
	{
		cout << "ͨѶ¼�Ƿ��Ѿ����ˣ�" << endl;
		return ;
	}
	else//�����ϵ��
	{
		//����
		string name;//
		cout << "����������" << endl;
		cin >> name;
		abs->personarray[abs->size].name = name;

		//�Ա�
		cout << "�������Ա����֣�" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;
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
				cout << "������������������" << endl;
			}
		}
		//���
		int age = 0;
		cout << "����������" << endl;
		cin >> age;
		abs->personarray[abs->size].age = age;
		//�绰

		string phone = "";
		cout << "������绰" << endl;
		cin >> phone;
		abs->personarray[abs->size].phone = phone;

		//סַ
		string add = "";

		cout << "�������ַ" << endl;
		cin >> add;
		abs->personarray[abs->size].addr = add;

		abs->size++;
		cout << "��ӳɹ�" << endl;
		system("pause");//�����������
		system("cls");//����
	}
}
void showPerson(adderssbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0;i < abs->size;i++)
		{
			cout << "������" << abs->personarray[i].name << "\t";
			cout << "�Ա�" << (abs->personarray[i].sex==1?"��":"Ů") << "\t";
			cout << "�绰��" << abs->personarray[i].phone << "\t";
			cout << "���䣺" << abs->personarray[i].age << "\t";
			cout << "סַ��" << abs->personarray[i].addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//�����ϵ���Ƿ���ڣ�������ڣ���������λ�ã������ڷ���-1
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
	string name;//����Ҫ����
	cout << "��������Ҫɾ������" << endl;
	cin >> name;
	
	int ret = isExist(abs,name);
	if (ret!= -1)
	{
		for (int i = ret;i < abs->size;i++)
		{
			abs->personarray[i] = abs->personarray[i + 1];//����ǰ�ƣ���һ����ϵ�����ݸ���ǰһ����
		}
		abs->size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
		cout << "���޴���" << endl;
	system("pause");
	system("cls");
}
void findperson(adderssbooks* abs)
{
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin>>name;
	int ret = isExist(abs,name);
	if (ret != -1)
	{
			cout << "������" << abs->personarray[ret].name << "\t";
			cout << "�Ա�" << (abs->personarray[ret].sex==1?"��":"Ů") << "\t";
			cout << "�绰��" << abs->personarray[ret].phone << "\t";
			cout << "���䣺" << abs->personarray[ret].age << "\t";
			cout << "סַ��" << abs->personarray[ret].addr << endl;
	}
	else
		cout << "���޴���" << endl;
	system("pause");
	system("cls");
}

void modifperson(adderssbooks* abs)
{
	cout<< "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personarray[ret].name = name;
		
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
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
				cout<<"�����������������" << endl;
			}
		}

		cout <<"����������" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[ret].age = age;

		cout << "������绰" << endl;
		string phone ;
		cin >> phone;
		abs->personarray[ret].phone = phone;

		cout << "������סַ" << endl;
		string add;
		cin >> add;
		abs->personarray[ret].addr = add;
		
		cout<<"�޸ĳɹ�!" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void cleanPerson(adderssbooks* abs)
{
	
	abs->size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}


void showMenu()
{
	cout << "******* 1.�����ϵ�� ********" << endl;
	cout << "******* 2.��ʾ��ϵ�� ********" << endl;
	cout << "******* 3.ɾ����ϵ�� ********" << endl;
	cout << "******* 4.������ϵ�� ********" << endl;
	cout << "******* 5.�޸���ϵ�� ********" << endl;
	cout << "******* 6.�����ϵ�� ********" << endl;
	cout << "******* 0.�˳�����   ********" << endl;
}

int main()
{
	int input = 0;
	adderssbooks abs;
	abs.size = 0;//Ҫ���嵽ѭ����ǰ�棬abs.size����ÿһ�ζ�Ϊ0
	while (true)
	{
		showMenu();
		cout << "������ѡ��" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			addPerson(&abs);//���õ�ַ���ݣ������޸�ʵ��
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
	/*	{
			cout << "������Ҫɾ���˵�����" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "�ҵ���" << endl;
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
			cout << "******* 6.�����ϵ�� ********" << endl;
			break;
		case 0:
			cout << " �˳�ͨѶ¼ ����ӭ�´�ʹ��" << endl;
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
