#include<iostream.h>
class base
{
	int x;
public:
	base(int i){x=i;}
	virtual void disp()                     //�ڻ����У��麯�����Բ�ֹ��һ��������������//
	{
		cout<<"x="<<x<<endl;
	}
	
	
};
class xiao:public base                //��������ǹ��м̳У�Ϊ��ʵ��������//
{
	int y;
public:xiao(int i,int j):base(i)
	   {
		   y=j;
	   }
	   void disp()
	   {
	   	   base::disp();
		   cout<<"y="<<y<<endl;
	   }
};
void f(base *p)                //���ﶨ��Ļ����ָ�룬Ҳ���Զ�����������//
{
	(*p).disp();
}
void f(base &p)
{
	p.disp();
}
void main()
{

	xiao a0(20,30);	base a(10),*b=&a0,&c=a0;base d(100);
	f(&a0);
	f(a0);
	(*b).disp();
	(*b).base::disp();  //�������ͨ������base::��������������̬��ָ�������ĸ���ĺ�����
    c.disp();

	d.disp();
	f(d);
	f(&d);

}
