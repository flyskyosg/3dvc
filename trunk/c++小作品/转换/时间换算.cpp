#include<iostream.h>
class xiao
{
	int x,y,z;
public:
	xiao(int a,int b,int c)
	{
		x=a;y=b;z=c;
	}
	xiao(){}
	void disp()
	{
		cout<<x<<"Ê±"<<y<<"·Ö"<<z<<"Ãë"<<endl;
	}
	xiao operator +(xiao a)
	{
		int i=0,j=0,k=0;
		i=x+a.x;j=y+a.y;k=z+a.z;
		if(k>=60) {  j+=k/60;k%=60;};
	    if(j>=60) {  i+=j/60;j%=60;};
		return xiao(i,j,k);
	}
};
void main()
{
	xiao a(10,50,50),b(20,50,50),c;
	c=a+b;
	c.disp();
}

