#include<iostream.h>       
class xiao
{
	int a;
public:
	xiao(int i)
	{
		a=i;
	}
	xiao(){}
	void disp()
	{
		cout<<"a="<<a<<endl;
	}
};
class da:public xiao
{
	int b;
public:
	da(int i,int j):xiao(j)
	{
		b=i;
	}
	da(){}
	void disp()
	{
		xiao::disp();
		cout<<"b="<<b<<endl;
	}
};
void f(xiao &a)                    
{
	a.disp();
}
void main()
{
	xiao a(10),b;
	da c(10,20);
	c.disp(); 
    c.xiao::disp();          // 分支原则，在派生类当中，如果有和父类同名且参数一样的函数，在派生类的子对象调用该函数时，以派生类中的函数为准，如果要使用父类中的同名函数，要使用父类名加域运算符//
	b=c;                     //赋值兼容性原则，da是xiao的派生类，那么在所有用到类xiao的子对象的时候，都可泳类xiao 的派生类da去代替，包括指针，赋值，及引用，//
	a.disp();b.disp();
	f(c);
	xiao *p=&c;
	p->disp();
}

