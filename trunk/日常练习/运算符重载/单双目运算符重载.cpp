#include<iostream>

using namespace std;
class xiao
{
	
public:
	int x,y;
	explicit xiao(int i,int j)
	{
		x=i;y=j;
		cout<<"���á�";
	}
	xiao()
	{}
	void disp()
	{
		cout<<x<<y<<endl;
	}
	friend  xiao operator /(xiao a,xiao b);//���������Ϊ��Ե����ʱ����Ҫ�Ĳ�����ʵ�ʵĲ�����һ�µģ�����Ϊ��Ա����ʱ����Ҫ�Ĳ�����ʵ�ʵĲ�����һ����//
	xiao  operator *(xiao b)
	{     int p,q;
		p=x*b.x;
		q=y*b.y;
		return xiao(p,q);
	}
	xiao & operator --()       //��Ŀ����������������غ���ʱû�в���ʱ�����ú�����//ע�⣬��Ϊǰ++���������������Ǳ������������Ϊ��ֵ�������������Զ������͵�ʱ�����ǰ++��--���ص�ʱ�� Ҫ���ظ��� �͵����� 
	{
		--x;--y;
		return *this;
	}
    xiao operator --(int ) //�в���ʱ������������ʹ�ã�//
	{   
		int a,b;
		a=x;b=y;
		x--;y--;
		return xiao(a,b);
	
	}

    
};
xiao operator / (xiao a,xiao b)
{
    int p;int q;
	p=(a.x)/(b.x);
	q=(a.y)/(b.y);
	return  xiao(p,q);  //��ʱ����ʽ�ĵ����˹��캯�������Դ��������п���
}


int main()
{
	xiao a(10,10),b(5,5);
	xiao c,d;
	c=a/b;
    c.disp();
	c=a.operator *( b);
	c.disp();
	d=--a;
	d.disp();
	d=b--;
	d.disp();
	
   



	
}
