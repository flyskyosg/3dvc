#include<iostream.h>
class A
{
	int a;
public:
	A(int i)
	{
		a=i;
		cout<<"A."<<endl;
	}
	~A(){cout<<"A."<<endl;}
void dispa()
{
	cout<<"a="<<a<<endl;
}
};
class B: public A
{
	int b;
public:
	B(int i,int j):A(i)
	{
		cout<<"B."<<endl;
		b=j;
	}
	void disp()
	{
		cout<<"B."<<b<<endl;
	}
	~B(){cout<<"B."<<endl;}
   
};
class C1:virtual public B
{
	int c1;
public:
	C1(int i,int j,int k):B(i,j)
		{
           cout<<"C1."<<endl;
		   c1=k;
		}
	void dispc1()
	{
		
		cout<<"c1="<<c1<<endl;
		disp();
	}
	~C1(){cout<<"C1."<<endl;}
	
};
class C2:virtual public	B
{
	int  c2;
public:
	C2(int i,int j,int k):B(i,j)
	{
		cout<<"C2."<<endl;
		c2=k;
	}
	void dispc2()
	{
		cout<<"c2="<<c2<<endl;
		disp();
	}
	~C2(){cout<<"C2."<<endl;}

};
class D:public C1,public C2
{
	int d;
public:
	D(int i,int j,int k,int l,int m):B(i,j),C1(i,j,k),C2(i,j,l) //��������Ĺ��캯���У��ȵ�������ڵ�һ����࣬//
	{
		cout<<"D."<<endl;
		d=m;
	}
	void output()
	{
		dispa();
		disp();            //�ڶ���d�Ķ����ʱ������ù��캯����˳������һ��Ķ�̳в�ͬ�ģ���Ϊ��������࣬�����ȵ�������࣬�ڵ���һ��Ļ���//
		dispc1();
		dispc2();
		cout<<"d="<<d<<endl;
	}
	~D(){cout<<"D."<<endl;}
};
void main()
{
	D d(10,20,30,40,50);
    d.output();               
	//��c1��c2�ж��д�B�̳�����disp();������ΪB������Ϊ����࣬������c1��c2��ֻ����ָ��B��ָ�룬����ָ��ָ��ĵ�ַ��ͬ��������d�̳�c1��c2��ʱ�򣬽�����һ��ָ��b��ָ�룬���ʱ��Ͳ�����ڶ����Եĳ�ͻ//
     
	
}


































