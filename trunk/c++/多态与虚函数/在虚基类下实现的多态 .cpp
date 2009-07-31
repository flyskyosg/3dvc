#include<iostream>              //在虚基类下实现的多态 

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
	void disp()
	{
        //A::disp();
		cout<<"B"<<endl;
	}
};

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
	
    A * q=& b;
    q->disp();
   
	D d;
    d.disp();
    A & p=d;
    p.disp();
    
    system("pause");
	return 0;
	
}
