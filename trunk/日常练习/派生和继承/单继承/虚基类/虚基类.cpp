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
	D(int i,int j,int k,int l,int m):B(i,j),C1(i,j,k),C2(i,j,l) //在派生类的构造函数中，先调虚基，在调一般基类，//
	{
		cout<<"D."<<endl;
		d=m;
	}
	void output()
	{
		dispa();
		disp();            //在定义d的对像的时候，其调用构造函数的顺序是与一般的多继承不同的，因为存在虚基类，所以先调用虚基类，在调用一般的基类//
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
	//在c1和c2中都有从B继承来的disp();但是因为B被声明为虚基类，所以在c1和c2中只含有指向B的指针，两个指针指向的地址相同，所以在d继承c1和c2的时候，仅含有一个指向b的指针，这个时候就不会存在二义性的冲突//
     
	
}


































