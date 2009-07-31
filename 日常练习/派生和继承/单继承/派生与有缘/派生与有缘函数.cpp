#include<iostream.h>
class xiao
{
private:int x;
protected:int y;
public:int z;
	xiao(int i,int j,int k)
	{
		x=i;y=j;z=k;
	}
	void disp()
	{
		cout<<"x="<<x<<endl;
	    cout<<"y="<<y<<endl;
    }
};
class da:private xiao
{
	int w;
protected:int v;
public:
	da(int i,int j,int k,int l,int b):xiao(i,j,k)
	{
		w=l;v=b;
	}
	
	friend void f(da &p);
    friend class  mid;
};
class mid
{
	da o;
public:
	mid(int i,int j,int k,int l,int b):o(i,j,k,l,b)
	{
	
	}
	void disp()
	{
		
		cout<<"o.w="<<o.w<<endl;
		cout<<"o.v"<<o.v<<endl;
		cout<<"o.z="<<o.z<<endl;
		o.disp();
	}
};
void f(da &p)  //派生类的有缘函数除了能访问派生类的私有和保护成员外，还只能访问派生类的父类的公有成员，父类的中的私有和保护成员是不能被派生类的有缘访问的//
{              
	
	cout<<"p.w="<<p.w<<endl<<"p.v"<<p.v<<endl<<"p.z="<<p.z<<endl;
	p.disp();  //如果要访问，只能通过有缘来调用派生类中从父类继承过来的父类的成员函数来访问,disp()是派生类da从xiao中继承来的xiao的公有成员函数//

}
void main()
{
	da x(1,2,3,4,5);
	mid y(1,2,3,4,5);
	f(x);
	y.disp();
}




