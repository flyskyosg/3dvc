#include<iostream>    
#include<string>
using namespace std;

void disp2();
void disp1()
{
	
	disp2();
}

void disp2()
{
	
	throw 10.0;
	//throw 'a'; 同上
}

int main()
{
	try
	{
		disp1();
		//disp2();
	}
	catch(int )         //将异常挨个逐级匹配,仅仅进行精确匹配，不进行类型的转换
	{
		cout<<endl;
	}
	catch(string s)      //通过数据来传递异常的状态
	{
		cout<<s<<endl;
	}
	catch(...)           //捕获所有类型的异常
	{
		cout<<"catch"<<endl;
	}
	return 0;
}
