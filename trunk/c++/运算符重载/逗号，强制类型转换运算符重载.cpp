#include<iostream.h>   //������
#include<malloc.h>
class xiao
{
	int a,b;
public:
	xiao(int x,int y)
	{
		a=x;b=y;
	}
	xiao(){}
	xiao operator +(xiao j)
	{
		return xiao(a+j.a,b+j.b);
	}
	xiao operator ,(xiao y)  //�������������
	{
		return  y;
	}

	 void mm(int x,int y)
	 {
		 a=x;b=y;
	 }

    operator char ()   //ǿ������ת�����������
	{
		return char(a+b);
	}





	void disp()
	{
		cout<<a<<" "<<b<<" "<<'\n';
	}
};

void main()
{
	xiao a(1,2),b(3,4);xiao c;
	c=a+b;
	c.disp();
	(a,a+b,b).disp();
	xiao * p=(xiao *)malloc(sizeof(xiao));
	p->mm(100,200);
	p->disp();
	cout<<char(*p);
}
	