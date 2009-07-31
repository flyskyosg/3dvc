#include<iostream.h>
class xiao
{
	int i;
public:
	xiao(int o)
	{
		i=o;
	}
	void  disp()
	{
		cout<<i<<endl;
	}
	friend int  sum( xiao & );friend  void sum1(xiao);
};
int sum( xiao & n)
{
  return(n.i*n.i);
  
}
void sum1(xiao n)
{
n.disp();
}
void main()
{
   xiao a=10;xiao u=sum(a);
	u.disp();sum1(a);
}