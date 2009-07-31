#include<iostream>                //宏定义的高级应用
#define name(a,b) a##b                
//宏定义的连接
#define n 10
using namespace std;

void name(s,s)(long a )	   //这里相当于ss(long a);	  
{
	cout<<0<<endl;
}

void disp(char a  ,#ifndef n  int b #endif )    //函数参数中的宏定义
{
	cout<<1<<endl;
}

int main()
{
	
    ss(10);
	return 0;
}

