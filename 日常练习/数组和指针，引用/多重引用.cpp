#include<iostream>  //�������������е����õ����� (��������)

using namespace std;

class xiao
{
   int a;
   public: 
           xiao(){a=0;} 
	friend void f()
	{
		      xiao a0;
              cout<<a0.a<<endl;
    }
	friend void t(xiao & b)
	{
             cout<<b.a<<endl;
    }
};


//�������������õ�����--��ͬ������ 
void g(xiao & a )   //��һ������ 
{
	f();
	t(a);           //�ڶ������� ,���������ڲ�ͬ 
}

//��ͨ���������õ����ã������ࣩ 

void n(int & a ,xiao & b)
{
     cout<<a<<endl;
}

void m(int & a,xiao & b)
{

     n(a,b);              //ͨ���������������õ����� --��ͬ������ 
                        
     int & e=a;           //��ͨ��������õ�����1          
     xiao & d=b;
     cout<<e<<endl;

	 int & c=e;           //��ͨ��������õ�����2       
	 cout<<c<<endl;
     
	 c=30;
	 cout<<"a="<<a<<endl;


     
     
 }
      



int main()
{
	xiao a;
	g(a);
	system("pause");

	int c=20;
	m(c,a);
	cout<<"c="<<c<<endl;
	return 0;
}
