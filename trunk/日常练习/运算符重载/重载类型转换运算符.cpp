#include<iostream>      //��������ת�������

using namespace std;

class test
{
	int a,
		b,
		c;
public:
    
	test(int x,int y,int z):a(x),b(y),c(z)
	{}


	test(test & t):a(t.a),b(t.b),c(t.c)  //Ĭ�Ͽ������캯���������ó�ʼ���б�
	{}

	void disp()
	{
		cout<<a<<b<<c<<endl; //��������ת������� 
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

    //��������ת�������
	cout<<a+b<<endl;
	cout<<a+10<<endl;
	cout<<10+a<<endl;
	cout<<int(a)<<endl;
}