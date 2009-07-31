#include<iostream.h>
class xiao    //作为基类使用//
{
private:      
	int x;
protected:
	int y;
public:
	int z;
    xiao(int i,int j,int k)
	{
		x=i;y=j;z=k;
	}
	void disp()
	{
		cout<<x<<endl;
	}
	void disp1()
	{
		cout<<x<<y<<z<<endl;
	}
};
class xiao1
{
	int v;
public:
	xiao1 (int i)
	{v=i;}
	void disp2()
	{
		cout<<v<<endl;
	}
};

class da :private xiao ,private xiao1   //私有继承//
{
	int w;xiao m;  xiao1 n;         //派生类当中 定义的基类的子对象//
public:
	da(int i,int j,int k,int l,int b):xiao(i,j,k),xiao1(b),m(i,j,k),n(b)     //单继承的构造函数，//
	{
		w=l;
	}
	void output()
	{	
		disp();	
		disp2();                       //积累的私有成员只能通过调用基类的成员函数来调用或用域类名和域运算符来调用//
	    cout<<y<<endl<<z<<endl<<w<<endl;     
		m.disp1();
	
		
	}
};



void main()
{
   da x(10,20,30,40,50);
   x.output();
}
	





	