#include<iostream.h>
class xiao
{
	int x,y;
public:
	xiao(int i,int j)   
	{
		x=i;y=j;
	}
	void disp()
	{
		cout<<x<<y<<endl;
	}
	bool operator >(xiao b)                         //�Զ���������Ϊ����ģ������Ͳ���ʱ��Ҫ������������أ�//
	{
		return  x>b.x&&y>b.y;
	}
};
template <class t>
t max(t a,t b);
void main()
{
	xiao a(10,10),b(12,12);
	int c(100),d(200);
    cout<<max(c,d)<<endl;
	max(a,b).disp();
}
template <class t>
t max(t a,t b)
{
	return a>b? a:b;
}




