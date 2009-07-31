#include<iostream>      //默认拷贝构造函数

using namespace std;

class test
{
	int a,
		b,
		c;
public:
    
	test(int x,int y,int z):a(x),b(y),c(z)
	{}


	test(test & t):a(t.a),b(t.b),c(t.c)  //默认拷贝构造函数都可以用初始化列表，而且参数必须是引用，否则会陷入无穷的递归
	{}

	void disp()
	{
		cout<<a<<b<<c<<endl;
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
}