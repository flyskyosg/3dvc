#include<iostream.h>
class xiao
{
	int x;
public:
	xiao(int i)
	{
		x=i;
		cout<<"此时调用基类的构造函数"<<endl;
	}
	void disp()
	{
		cout<<x<<endl;
	}
	~xiao(){cout<<"此时调用基类的析构函数"<<endl;}
};
class da:public xiao
{
	int y;
public:
	da(int i,int j):xiao(j)
	{
		cout<<"此时调用派生类的构造函数"<<endl;
		y=i;
	}
	void disp()
	{
		xiao::disp();       //注意此处当基类的成员函数有和派生类的成员函数有同名的时候，要使用类名加域运算符//
		cout<<y<<endl;
	}
    ~da(){cout<<"此时调用派生类的析构函数"<<endl;}
};
void main()
{
	da a(10,20);
	a.disp();
}