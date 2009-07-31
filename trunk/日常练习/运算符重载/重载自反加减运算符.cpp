#include<iostream.h>
class xiao
{
	int x,y;
public:
	xiao(int i,int j)
	{
		x=i;y=j;
	}
	xiao()
	{}
	void disp()
	{
		cout<<x<<y;
	}
	friend xiao operator +=(xiao a ,xiao b)
	{
		a.x+=b.x;
		a.y+=b.y;
		return  xiao(a.x,a.y);
	}
	xiao operator -=(xiao b)
	{
		x-=b.x;y-=b.y;
		return *this;
	}
};
void main()
{
	xiao a(-10,-10),b(-20,-20),c,d;
	c=a+=b;
	d=a-=b;
	c.disp();
	d.disp();
}