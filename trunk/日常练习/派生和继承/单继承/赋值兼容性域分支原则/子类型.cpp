#include<iostream.h>       
class xiao
{
	int a;
public:
	xiao(int i)
	{
		a=i;
	}
	xiao(){}
	void disp()
	{
		cout<<"a="<<a<<endl;
	}
};
class da:public xiao
{
	int b;
public:
	da(int i,int j):xiao(j)
	{
		b=i;
	}
	da(){}
	void disp()
	{
		xiao::disp();
		cout<<"b="<<b<<endl;
	}
};
void f(xiao &a)                    
{
	a.disp();
}
void main()
{
	xiao a(10),b;
	da c(10,20);
	c.disp(); 
    c.xiao::disp();          // ��֧ԭ���������൱�У�����к͸���ͬ���Ҳ���һ���ĺ���������������Ӷ�����øú���ʱ�����������еĺ���Ϊ׼�����Ҫʹ�ø����е�ͬ��������Ҫʹ�ø��������������//
	b=c;                     //��ֵ������ԭ��da��xiao�������࣬��ô�������õ���xiao���Ӷ����ʱ�򣬶���Ӿ��xiao ��������daȥ���棬����ָ�룬��ֵ�������ã�//
	a.disp();b.disp();
	f(c);
	xiao *p=&c;
	p->disp();
}

