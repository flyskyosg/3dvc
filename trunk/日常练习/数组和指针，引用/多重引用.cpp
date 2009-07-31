#include<iostream>  //函数参数传递中的引用的引用 (多重引用)

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


//函数参数的引用的引用--不同作用域 
void g(xiao & a )   //第一次引用 
{
	f();
	t(a);           //第二次引用 ,但是作用于不同 
}

//普通变量的引用的引用（包括类） 

void n(int & a ,xiao & b)
{
     cout<<a<<endl;
}

void m(int & a,xiao & b)
{

     n(a,b);              //通过函数参数的引用的引用 --相同作用域 
                        
     int & e=a;           //普通对象的引用的引用1          
     xiao & d=b;
     cout<<e<<endl;

	 int & c=e;           //普通对象的引用的引用2       
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
