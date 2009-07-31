#include<iostream>      //函数重载的时产生未定义行为

using namespace std;

void disp(long a)
{
	cout<<0<<endl;
}

void disp(char);
int main()
{
	disp(10);      //这里在匹配的时候会不知道调用char 还是调用 long 而产生未定义行为，解决办法是增加disp(int)函数或者进行类型转换
	return 0;
}


void disp(char a)
{
	cout<<1<<endl;
}