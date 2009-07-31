#include<iostream>              //运行时类型信息 
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
    cout<<"普通rtti"<<endl;
    cout<<typeid(b).name()<<endl; 
     
     
    A * q=& b;                
    q->disp();
    cout<<"多态下的rtti1"<<endl;
    cout<<typeid(*q).name()<<endl;
	
   
     
    A & p=b;
    p.disp();
    cout<<"多态下的rtti2"<<endl;
    cout<<typeid(p).name()<<endl;
    
    cout<<"运行时类型信息检查"<<endl;
    if(typeid(p)!=typeid(*q)) cout<<"匹配成功"<<endl;
    else cout<<"匹配失败"<<endl;
    
    
    
    system("pause");
	return 0;
	
}
