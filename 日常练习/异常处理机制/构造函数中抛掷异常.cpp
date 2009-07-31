#include<iostream.h>
class base
{
	int x;
public:
	base(){cout<<"调用构造函数1"<<endl;} //构造函数中抛掷异常
	base(int i)
	{
		cout<<"调用构造函数2"<<endl; 
		if(i<0) throw i;
		x=i;

	}
	~base(){cout<<"调用析构函数"<<endl;}
	void disp()
	{
		cout<<"x="<<x<<endl;
	}
};
void main()
{
	try
	{
		base a,b(1),c(-1);
	}
	catch(int )
	{
		cout<<"输入错误."<<endl;
	}
	catch(...)
	{}
	
}
	
