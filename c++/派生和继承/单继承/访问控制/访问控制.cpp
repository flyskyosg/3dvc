#include<iostream.h>
class xiao
{
private:int x;
protected:int y;
public:	int z;


	xiao(int a,int b,int c)
	{
		x=a;y=b;z=c;
	}
	void disp()
	{
		cout<<x<<endl<<y<<endl<<z<<endl;
	}
};
class da :private xiao
{
	int w;int y;    //在派生类当中定义于基类相同名字的数据成员，使用时派生类的成原将覆盖基类的同名成员，如果要使用基类的同名数据成员，用类名和域预算符结合就可以使用//
     
public:xiao:: z,xiao:: disp;   //用访问说明来恢复被继承的数据在原来基类当中的属性,这里回复为原来在基类中的public属性，注意数据成员和含成员函数的格式不一样，成员函数不需要加上参数列表，//
    da(int i,int j,int k):xiao(i,i,i)
	{
		w=k;y=k;
	}
	void output()
	{
		cout<<y<<endl<<xiao::y<<endl;  //这里的y是派生类中的y,后边加上xiao::是基类的y//
		disp();
	}
};
void main()
{
	da x(10,20,30);
	x.output();
}





