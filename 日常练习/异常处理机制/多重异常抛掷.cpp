#include<iostream.h>          //多重异常抛掷
class base
{
	int x;
public:
	base(){cout<<"调用构造函数1"<<endl;}
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
void f()
{
	int i;
	cout<<"请输入数据:";cin>>i;
	if(i<0) throw i;
	base b(i);
	cout<<"请输入数据:";cin>>i;
    
    base c(i);
}
void main()
{
	try
	{
		f();
	}
	catch(int )
	{
		cout<<"输入错误."<<endl;
	}
	catch(...)
	{}
	
}
	
