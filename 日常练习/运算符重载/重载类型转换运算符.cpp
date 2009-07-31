#include<iostream>      //重载类型转换运算符

using namespace std;

class test
{
	int a,
		b,
		c;
public:
    
	test(int x,int y,int z):a(x),b(y),c(z)
	{}


	test(test & t):a(t.a),b(t.b),c(t.c)  //默认拷贝构造函数都可以用初始化列表
	{}

	void disp()
	{
		cout<<a<<b<<c<<endl; //重载类型转换运算符 
	}

    operator int()
	{
		return a+b+c;
	}



};


int main()
{
	
	test b(1,2,3);
	test c(b);
	test a=b;

	b.disp();
	a.disp();
	c.disp();

    //重载类型转换运算符
	cout<<a+b<<endl;
	cout<<a+10<<endl;
	cout<<10+a<<endl;
	cout<<int(a)<<endl;
}