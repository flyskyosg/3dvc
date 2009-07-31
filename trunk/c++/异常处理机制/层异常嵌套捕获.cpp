#include<iostream>     //标准库中的异常处理以多层异常嵌套捕获
#include<string>
#include<exception>
using namespace std;

void disp2();
void disp1()
{
	try
	{
	
	disp2();
	}
	catch(char)
	{
		cout<<"char"<<endl;
	}
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
	catch(double )         //将异常挨个逐级匹配,仅仅进行精确匹配，不进行类型的转换
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

	try 
	{

	int * p =new int [100000000];  //导致异常
	}
	catch(bad_alloc)               //  在exception中定义
	{
		cout<<"bad aloc"<<endl;
	}
	string s="success";
	cout<<s+string("hello")<<endl;
	cout<<s+"hello"<<endl;
	return 0;
}
