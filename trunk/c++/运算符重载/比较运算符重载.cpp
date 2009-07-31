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
    bool operator >(xiao a)
	{
		return( x>a.x&&y>a.y);
	}
    bool operator <(xiao a)
	{
		return( x<a.x&&y<a.y ? 1:0  );
	}
  

};
void main()
{
	xiao a(10,10),b(10,10);
	int m;
	m=a>b;
	cout<<m<<endl;
	m=b<a;
	cout<<m<<endl;
}
