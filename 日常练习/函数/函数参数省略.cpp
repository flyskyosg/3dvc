#include<iostream>            //函数参数省略

using namespace std;

void disp(long a ...)		  //函数的参数不明确时可以用省略号代替
{
	cout<<0<<endl;
}

void disp(char);
int main()
{
	
	disp(char(10),int(20));   //在函数参数不明确的情况下可以加上很多个参数，编译器会进行精确匹配
	return 0;
}


void disp(char a)
{
	cout<<1<<endl;
}