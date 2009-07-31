#include<iostream>            //
#include<cstdlib>
using namespace std;

class exe
{
	int a;
};
int a;

void disp()
{
	cout<<"stop"<<endl;
}

int main()
{
	
	cout<<"come on"<<endl;
    atexit(disp);              //允许设置程序在终止前执行的操作。atexit的类型为void()；不可以有参数不可以有返回类型
	exit(1);                   //直接终止程序 
	//abort();                 //强行终止程序
	cout<<"baby"<<endl;

	return 0;



}
