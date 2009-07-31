#include<iostream>      //函数的作用域

using namespace std;

void disp(double a)
{
	cout<<0<<endl;
}


int main()
{
	void disp(int);    //在局部作用域内声明的和在全局声明的同名（重载）函数在局部作用域内局部作用于内有效,如果需要使用全局的，需要使用域运算符
	::disp(10.0);
	return 0;
}


void disp(int a)
{
	cout<<1<<endl;
}