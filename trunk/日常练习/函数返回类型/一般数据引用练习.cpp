#include<iostream.h>
class xiao
{
	int x;
public:
	xiao (int i)
	{
		x=i;
	}
	void disp()
	{
		cout<<x<<endl;
	}
	friend void sum(int &,int *&,xiao &);
};
void sum(int &c,int *&p,xiao &b)
{
c=100;*p=200;cout<<b.x<<endl;
}

void main()
{ 
    int a=10,*p=&a;xiao b=10;
	int &c=a,*&q=p;xiao &d=b;//*&是对指针的引用//
	cout<<a<<" "<<c<<endl;
	cout<<*p<<" "<<*q<<endl;
	b.disp();d.disp();
	sum(a,p,b);
	cout<<a<<endl;

}
