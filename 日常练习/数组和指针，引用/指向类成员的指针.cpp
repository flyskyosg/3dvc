#include<iostream>                      //ָ���Ա��ָ�� 
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
    static int a;                       //��̬��Ա 
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
           cout<<"a="<<a<<endl;               //�����a�Ǵ�b�̳й����ģ���������ֵ���ֲ��� 
    }
};




int main()
{
	

    
    //ָ������Ա��ָ�룬��������ָ���캯��������������ָ��
    cout<<"ָ������Ա��ָ��"<<endl; 
    D d,*d2=new D;
    void (D::* o)()=& D::disp;               //ָ���Ա������ָ�� ,ָ��ĺ�������Ϊ���� 
    (d.*o)();                                //ͨ����ͨ�������� 
    (d2->*o)();                              //ͨ��ָ���������ָ����� 
    
    
    void (*u)()=D::disp1;                    //���Ա�ľ�̬��Ա��������ͨ����ָ��ָ��
    u(); 
    
    void(B:: *n)()=&B::disp;                 //ֻ�ܰ�ָ�����ĳ�Աָ�븳ֵ��ָ��������ĳ�Ա��ָ�룬��֮���ܣ���������͵ĸ����෴ 
    void(D:: *m)()=n;
    
    
    //ָ�����ݳ�Ա��ָ�� ָ������ݳ�Ա����Ϊ���� 
    D d1;
    int D::* j =& D::b; 
    cout<<"ָ�����ݳ�Ա��ָ��"<<endl;
    cout<<d1.*j<<endl;                      //ͨ����ͨ��Ա����      
    cout<<d2->*j<<endl;                     //ͨ��ָ��������ָ����� 
    
    int * k=&D::a;                          //��ָͨ������������ľ�̬���ݳ�Ա 
    cout<<"a="<<*k<<endl; 
    
    int C::*l=&C::b;
    j=l;j=l;                               //ͬ��Ա����һ������������ݳ�Ա��ָ�����������������ݳ�Ա��ָ�븳ֵ�����Ƿ�֮������ 
    C c;
    cout<<c.*l<<d1.*j<<endl;                
    
    
    
    
    
    system("pause");
	return 0;
	
}
