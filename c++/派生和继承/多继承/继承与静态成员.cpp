#include<iostream>              //�̳��뾲̬��Ա 

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
      static int a;                    //��̬��Ա 
public: 
	void disp()
	{
        //A::disp();
		cout<<"B"<<endl;
	}
	
	static void disp1()                //��̬��Ա���� 
     {
           cout<<a<<endl;
     }

};

int B:: a=10;                          //��̬��Ա��ʼ��                   

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
	b.disp1();               //��̬��Ա ���� 
     
    A * q=& b;
    q->disp();
   
	D d;
    d.disp();
    d.disp1();               //d��b�м̳��˾�̬��Ա�Լ���̬��Ա ���� 
    
    A & p=d;
    p.disp();
    
    system("pause");
	return 0;
	
}
