#include<iostream.h>
class xiao
{
	int x;
public:static int y;
	xiao(int i)
	{
		x=i;y++;
	}
	void disp()
	{
		cout<<"x="<<x<<endl;
	
		cout<<"y="<<y<<endl;
	}
};int xiao:: y=0;
class da:public xiao
{
	int z;
public:
	da(int i,int j):xiao(j)
	{
		z=i;
	}
	void disp()            //��������������кͻ���ͬ���ĳ�Ա������������ɳ�ͻ��������ĳ�Ա�������̳й����Ժ�ͻ����������ͬ������������ͻ�����Ҫ����ͬ�������Ҫͬ���Ҳ����أ�����ʹ�õ�ʱ��Ҫ���������������//   
	{
		
		y++;            //y�ǻ����е�һ����̬�������������൱����Ȼʱ����ʹ�õ�//
		xiao::disp();
		cout<<z<<endl;
	}
};
void main()
{
	da a(10,20);
	a.disp();
}