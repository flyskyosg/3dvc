#include<iostream.h>
class base 
{
public:
	virtual void dispx()=0;
	virtual void dispy()=0;
};
class xiao:public base //共有继承//
{
	int x,y;
public:
	xiao(int i,int j )
	{
		x=i;y=j;
	}
	void dispx()     //函数的定义方式必须一致//
	{
		cout<<"x="<<x<<endl;
	}
	void dispy()
	{
		cout<<"y="<<y<<endl;
	}
};
class da:public base
{
	int x,y;
public:
	da(int i,int j )
	{
		x=i;y=j;
	}
	void dispx()
	{
		cout<<"x="<<x<<endl;
	}
	void dispy()
	{
		cout<<"y="<<y<<endl;
	}
};
void fxiao(base &p)
{
	p.dispx();
	p.dispy();
}
void fda(base *p)
{
	(*p).dispx();
	p->dispy();
}
void main()
{
	xiao a(10,20);da a0(30,40);
	base *b=&a,&c=a0;
	b->dispx();
	b->dispy();
	fxiao(a);
	c.dispx();
    c.dispy();
	fda(&a0);
}
