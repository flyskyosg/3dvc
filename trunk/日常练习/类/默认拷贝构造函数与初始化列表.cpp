#include<iostream>      //Ĭ�Ͽ������캯��

using namespace std;

class test
{
	int a,
		b,
		c;
public:
    
	test(int x,int y,int z):a(x),b(y),c(z)
	{}


	test(test & t):a(t.a),b(t.b),c(t.c)  //Ĭ�Ͽ������캯���������ó�ʼ���б����Ҳ������������ã��������������ĵݹ�
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