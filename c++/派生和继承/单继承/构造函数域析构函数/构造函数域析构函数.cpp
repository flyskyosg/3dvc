#include<iostream.h>
class xiao
{
	int x;
public:
	xiao(int i)
	{
		x=i;
		cout<<"��ʱ���û���Ĺ��캯��"<<endl;
	}
	void disp()
	{
		cout<<x<<endl;
	}
	~xiao(){cout<<"��ʱ���û������������"<<endl;}
};
class da:public xiao
{
	int y;
public:
	da(int i,int j):xiao(j)
	{
		cout<<"��ʱ����������Ĺ��캯��"<<endl;
		y=i;
	}
	void disp()
	{
		xiao::disp();       //ע��˴�������ĳ�Ա�����к�������ĳ�Ա������ͬ����ʱ��Ҫʹ���������������//
		cout<<y<<endl;
	}
    ~da(){cout<<"��ʱ�������������������"<<endl;}
};
void main()
{
	da a(10,20);
	a.disp();
}