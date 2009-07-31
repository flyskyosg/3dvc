#include<iostream>                //函数指针

using namespace std;

void disp(long a )		  
{
	cout<<0<<endl;
}

void disp(char);
int main()
{
	
    void (*p)(long)=disp;        //如果程序中有重载函数则当初始化函数指针的时候，会根据这些函数指针的定义去匹配重载的函数
	void (*q)(char)=&disp;       //函数名称即是函数的入口地址，可以使用这两种方式来初始化函数指针
	p(10);                       //那么在使用函数指针的时候也有这两种的方式
	(*q)('a');
	return 0;
}


void disp(char a)
{
	cout<<1<<endl;
}