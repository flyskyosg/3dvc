#include<iostream>             //模板的参数类型

using namespace std;

template<class T,int i=0>             
class xiao
{
	T a;
	public:
		xiao(T x)
		{a=x;}

};


template<class T ,class U=xiao<T> >     //模板参数类型为另一个模板类型
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

class zhong
{
	int a;
public:
	zhong()
	{}


};



int main()
{
	zhong y;
	char z='a';
	xiao<int> a(10);        //基本类型
	xiao<zhong> b(y);       //自定义类型
    xiao<char *> c(&z);     //指针类型
    xiao<int,10-5> d(5);    //常量表达式    这个是时候要求模板参数中的类型表是基本类型参见xiao的定义



	return 0;
}
