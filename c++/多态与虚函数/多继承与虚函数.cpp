#include<iostream.h>
class base
{
	int x,y;
public:
	base(int i,int j)
	{
		x=i;y=j;
	}
	virtual void dispx()
	{
        cout<<"x="<<x<<endl;
		
	}
	virtual void dispy()
	{
		cout<<"y="<<y<<endl;
	}
};
class base1
{
	int x1,y1;
public:
	base1(int k,int l)
	{
		x1=k,y1=l;
		
	}
	virtual void dispx()
	{
		cout<<"x1="<<x1<<endl;
	}
	void dispy()
	{
		cout<<"y1="<<y1<<endl;
	}
};
class xiao:public base ,public base1
{
	int x2,y2;
public:
	xiao(int i,int j,int k,int l,int m,int n):base(i,j),base1(k,l)
	{
		x2=m;y2=n;
	}
	void dispx()
	{
		cout<<"x2="<<x2<<endl;
	}
	void dispy()
	{
		cout<<"y2="<<y2<<endl;
	}

};
void f(base &p)
{
	p.dispx();
	p.dispy();
}
void f(base1 *q)
{
	(*q).dispx();
	q->dispy();
}
void main()
{	
	xiao a(1,2,3,4,5,6);
	base *p=&a;base1 &q=a;
	base b(10,20);base1 b1(30,40);
	
	f(a);
	p->dispx();
	p->dispy();
	
	f(&a);
	q.dispx();
	q.dispy();

    f(b);
	b.dispx();
	b.dispy();
	
	f(&b1);
	b1.dispx();
	b1.dispy();
}


















