#include<iostream.h>
class xiao 
{
	int x;
public:
	xiao(int i)
	{
		x=i;
	}
	int & f(int m)
	{
		x+=m;
		return x;
	}
 void disp()
 {
	 cout<<"x="<<x<<endl;
 }
};
void main()
{
	xiao a(100);
	a.f(100)+=100;
	a.disp();
}