#include<iostream>             //模板默认参数

using namespace std;

template<class T>              //给模板设定默认参数为基本类型（也可以设置为自定义类型比如类）
class xiao
{
	T a;
	public:
		xiao(T x):a(x)
		{}
	void disp()
	{
		cout<<a<<endl;
	}
};


template<class T ,class U=xiao<T> >     //给模板设定默认参数为模板类型,但是要注意这里的后一个参数的模板类型要来自于前边的类型
class da
{
   T b;
   U a;
   public:
	   da(T y,U x):b(y),a(x)
	   {}
   void disp()
   {
	   cout<<b<<endl;
	   a.disp();
   }
};


int main()
{
	xiao<double> b(20);
	xiao<int> b1(20.0);//2222
	
	da<double> a(10,b);
	da<int> a1(10,b1) ;  //因为模板不能进行标准的参数转换，所以在使用其他的类模板作为自己的类型参数时，要注意类型一致,如果用b进行初始化就会出错
	a.disp();
	a1.disp();
	return 0;
}
