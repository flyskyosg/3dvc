#include<iostream.h>
class base
{
	int x;
public:
	base(int i){x=i;}
	virtual void disp()                     //在基类中，虚函数可以不止有一个，可以有许多个//
	{
		cout<<"x="<<x<<endl;
	}
	
	
};
class xiao:public base                //这里必须是公有继承，为了实现子类型//
{
	int y;
public:xiao(int i,int j):base(i)
	   {
		   y=j;
	   }
	   void disp()
	   {
	   	   base::disp();
		   cout<<"y="<<y<<endl;
	   }
};
void f(base *p)                //这里定义的基类的指针，也可以定义基类的引用//
{
	(*p).disp();
}
void f(base &p)
{
	p.disp();
}
void main()
{

	xiao a0(20,30);	base a(10),*b=&a0,&c=a0;base d(100);
	f(&a0);
	f(a0);
	(*b).disp();
	(*b).base::disp();  //这里可以通过加上base::与运算符来解除多态，指定调用哪个类的函数。
    c.disp();

	d.disp();
	f(d);
	f(&d);

}
