#include<iostream.h>
class xiao 
{
private:int x;
protected:int y;
public:int z;
	xiao(int i)
	{
		z=y=x=i;
	}
	void disp()
    {
		cout<<x<<endl<<y<<endl<<z<<endl;
	}
};
class da:public xiao             //不管是直接继承还是间接继承，父类都是通过在派生类中建立隐含无名子对象的方式实用的，也就是说在派生类中出现的父类的成员是在该隐含无名子对象的成员,当然也可以定义显示的父类的子对象，
                                  //如果父类的构造函数无参数，则在派生类中的构造函数不需要队父类传递参数，反之有参数时，就要传递参数//
{
	int w;
public:
	da(int i,int j):xiao(i)
	{
		w=j;
	}
	void disp()
	{
	    cout<<w<<endl;
	}
	
};
class shi:public da
{
	int r;
public:
	shi(int i,int j,int k):da(j,k)
	{
		r=i;
	}
	void disp()
	{
		xiao::disp();
		da::disp();
		cout<<r<<endl;
	}
};
void main()
{
	shi a(10,20,30);
	a.disp();
}

