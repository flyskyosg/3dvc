#include<iostream.h>
class xiao
{
	int x;
public:static int y;
	xiao(int i)
	{
		x=i;y++;
	}
	void disp()
	{
		cout<<"x="<<x<<endl;
	
		cout<<"y="<<y<<endl;
	}
};int xiao:: y=0;
class da:public xiao
{
	int z;
public:
	da(int i,int j):xiao(j)
	{
		z=i;
	}
	void disp()            //在派生当中如果有和基类同名的成员函数，容易造成冲突，当基类的成员函数被继承过来以后就会于派生类的同名函数发生冲突，因此要避免同名，如果要同名且不重载，则在使用的时候要加类名和域运算符//   
	{
		
		y++;            //y是基类中的一个静态变量，在派生类当中仍然时可以使用的//
		xiao::disp();
		cout<<z<<endl;
	}
};
void main()
{
	da a(10,20);
	a.disp();
}