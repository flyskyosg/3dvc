#include<iostream>              //继承与静态成员 

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
      static int a;                    //静态成员 
public: 
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
	void disp()
	{
        //A::disp();
		cout<<"C"<<endl;
	}
};


class D:public B,public C
{
public:
	void disp()
	{
         A::disp();
         B::disp();
         C::disp();    
		 cout<<"D"<<endl;
	}
};


int main()
{
	
	B b;
	b.disp();
	b.disp1();               //静态成员 函数 
     
    A * q=& b;
    q->disp();
   
	D d;
    d.disp();
    d.disp1();               //d从b中继承了静态成员以及静态成员 函数 
    
    A & p=d;
    p.disp();
    
    system("pause");
	return 0;
	
}
