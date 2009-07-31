#include<iostream.h>
class xiao    //作为基类使用//               //私有>保护>公有//
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
class da :private xiao    //私有继承//
{
	int w;xiao m;           //派生类当中 定义的基类的子对象//
public:
	da(int i,int j,int k,int l):xiao(i,j,k), m(i,j,k) //单继承的构造函数，//
	{
		w=l;
	}
	void output()
	{	
		disp();//积累的私有成员只能通过调用基类的成员函数来调用或用域类名和域运算符来调用//
		            
		cout<<y<<endl<<z<<endl<<w<<endl;  // 原来是保护和共有属性的成员在私有继承后变为派生类的私有成员，基类的私有成员始终之能被基类自己的成原函数访问//  
		m.disp1();
	}
};


class da1 :public xiao      //公有继承// //共有继承的基类的成员时，被继承的成员保持其在基类当中的属性不变，原来基类当中的私有成原仍然只能被其成原函数访问//
{
    int w;xiao m;           //派生类当中定义的基类的子对象//
public:
	da1(int i,int j,int k,int l):xiao(i,j,k), m(i,j,k) //单继承的构造函数//
	{
		w=l;                
	}
	void output()
	{	
		disp();                   //调用基类的成员函数//
		cout<<y<<endl<<z<<endl<<w<<endl;     
		m.disp1();               //基类的子对像调用成员函数//
	}
};

class da2 :protected xiao    //保护继承，和私有继承性质基本一致，只是保护继承来的成员在派生类中是作为保护成员的，原来是共有的成员变为派生类的保护的成员//
{
	int w;xiao m;           //派生类当中 定义的基类的子对象//
public:
	da2(int i,int j,int k,int l):xiao(i,j,k), m(i,j,k) //单继承的构造函数，//
	{
		w=l;
	}
	void output()
	{	
		disp();         //积累的私有成员只能通过调用基类的成员函数来调用或用域类名和域运算符来调用//
		            
		cout<<y<<endl<<z<<endl<<w<<endl;     
		m.disp1();
	}
};

void main()
{
   da x(10,20,30,40);da1 x1(10,20,30,40);da2 x2(10,20,30,40);
   x.output();x1.output();x2.output();
}
	





	