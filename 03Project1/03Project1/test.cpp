#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	
	float a = 10.3f;
	double b = 10.3;
	cout << a << endl;
	cout << b << endl;
	float f2 = 3e2;
	float f3 = 3e-2;
	cout << f2 << endl;
	cout <<f3 << endl; 

	//字符 注意是单引号
	char ch = 'a';//a-97  A-65
	cout << "char字符所占变量的内存是" << sizeof(char) << endl;
	cout << "字符变量对应的ASCII编码是" << (int)ch << endl;//字符前面加强转（int）就能得到ASCII码值
	
	// \t水平制表符，占用8个字节  \t可以使得下面三行的 hello2024！对齐输出
	cout << "aaaa\thello 2024!" << endl;
	cout << "aa\thello 2024!" << endl;
	cout << "aaaaaa\thello 2024!" << endl;
	system("pause");
	return 0;
}

	//命名规则；
	//标识符不能是关键字
	//标识符只能由字母、数字、下划线组成，不能以数字开头
	//标识符中区分大小写

//sizeof(数据类型/变量)

//单精度   float 单精度后面的数字通常会加一个字母 f    占4字节
//双精度 double  占8字节
//默认情况下，输出一个小数，会显示6位有效数字