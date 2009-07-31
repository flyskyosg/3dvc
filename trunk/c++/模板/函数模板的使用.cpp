#include<iostream>
#include<string>

using namespace std;


template <class t,class r>     //类型参数表可以是两个也可以使多个//                      
t max(t a,r b )
{
	return a>b?a:b;
}


template <class t>
t max(t a,t b, t c)                      //和参数为2个的函数模板重载//
{
	return (a>b?a>c?a:c:b>c?b:c);
}


template <typename T ,int m>
void alloc(T * &  n)
{
     n=new T [m];
     cout<<"分配"<<m<<"个空间成功"<<endl; 
     
}


void max(int a)                        //一般函数和函数模板重载//
{
	cout<<a*a<<endl;
}int main()
{
	int a=10,b=20,e=30;
	double c=10.23,d=12.32,f=23.21;
	char g='a',h='b';               //字符型数据在比较的时候是比较其asc码值//
	cout<<max(a,b)<<endl;
	cout<<max(c,d)<<endl;
	cout<<max(a,b,e)<<endl;
	cout<<max(c,d,f)<<endl;
	cout<<max(g,h)<<endl;
	max(a);
	
	int * n;
	alloc<int,10>(n); 
	
	system("pause");
	return 0;
}
