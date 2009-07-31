#include<iostream>                      //指向成员的指针 
#include<typeinfo> 
using namespace std;



class A
{
public:
	virtual void disp()
	{
            cout<<"A"<<endl;
    } 
};

class B:public virtual  A
{
                     
public: 
    static int a;                       //静态成员 
	void disp()
	{
        //A::disp();
		cout<<"B"<<endl;
	}
	
	static void disp1()                //静态成员函数 
     {
           cout<<a<<endl;
     }

};

int B:: a=10;                          //静态成员初始化                   

class C: public virtual A
{
     
public:
    int b;
	void disp()
	{
        //A::disp();
		cout<<"C"<<endl;
	}
};


class D:public B,public C
{
      
public:
    int b;
    
	void disp()
	{
         A::disp();
         B::disp();
         C::disp();    
		 cout<<"D"<<endl;
	}
	static void disp1()
	{
           cout<<"a="<<a<<endl;               //这里的a是从b继承过来的，而且他的值保持不变 
    }
};




int main()
{
	

    
    //指向函数成员的指针，不可以有指向构造函数和析构函数的指针
    cout<<"指向函数成员的指针"<<endl; 
    D d,*d2=new D;
    void (D::* o)()=& D::disp;               //指向成员函数的指针 ,指向的函数必须为共有 
    (d.*o)();                                //通过普通类对象调用 
    (d2->*o)();                              //通过指向该类对象的指针调用 
    
    
    void (*u)()=D::disp1;                    //类成员的静态成员可以用普通函数指针指向；
    u(); 
    
    void(B:: *n)()=&B::disp;                 //只能把指向基类的成员指针赋值给指向派生类的成员的指针，反之不能，这和子类型的概念相反 
    void(D:: *m)()=n;
    
    
    //指向数据成员的指针 指向的数据成员必须为共有 
    D d1;
    int D::* j =& D::b; 
    cout<<"指向数据成员的指针"<<endl;
    cout<<d1.*j<<endl;                      //通过普通成员调用      
    cout<<d2->*j<<endl;                     //通过指向类对象的指针调用 
    
    int * k=&D::a;                          //普通指针用来处理类的静态数据成员 
    cout<<"a="<<*k<<endl; 
    
    int C::*l=&C::b;
    j=l;j=l;                               //同成员函数一样，基类的数据成员的指针可以象派生类的数据成员的指针赋值，但是反之不成立 
    C c;
    cout<<c.*l<<d1.*j<<endl;                
    
    
    
    
    
    system("pause");
	return 0;
	
}
