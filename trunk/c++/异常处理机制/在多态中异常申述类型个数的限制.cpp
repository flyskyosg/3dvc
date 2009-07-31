#include<iostream>

using namespace std;

//异常的多态

class base_bad
{
public:
	virtual ~base_bad()
	{cout<<"base_bad"<<endl; }
};

class bad1:public base_bad
{
public:
	~bad1()
	{cout<<"base_bad1"<<endl; }
};


class bad2:public bad1
{
public:
	~bad2()
	{cout<<"base_bad2"<<endl; }
};


//异常描述的包含机制


class base
{
public:
	virtual void disp() throw(base_bad,int)=0;
};

typedef void (* p)() ;//;throw(base_bad,int);       //在定义含有异常的申述的函数的指针的时候，不需要加上异常的 申述的描述， 



class base1:public base
{
public:
    void disp() throw(base_bad,int)           //基类的虚函数的如果含有异常的 申述的话，哪么派生类中的虚函数要对他进行覆盖实现多态时， 
	{  cout<<"base1"<<endl;   }               //派生类中的函数的异常的的类型不能多于积累的申述的个数 
};

class base2:public base1                    ////基类的虚函数的如果含有异常的 申述的话，哪么派生类中的虚函数要对他进行覆盖实现多态时，                                    //派生类中的函数的异常的的类型不能多于积累的申述的个数 
{             
public:
    void disp() throw(base_bad)             //派生类中的函数的异常的的类型不能多于积累的申述的个数
	{  cout<<"base2"<<endl;   }
};



//主函数 

int main()
{


	
	return 0;
	
}
