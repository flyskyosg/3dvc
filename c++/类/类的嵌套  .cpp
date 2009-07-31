#include<iostream.h>
class da
{
	int  x,y; 
public:
	
    da(int i,int j,int k):b(k)
	{   x=i;y=j;}
		
		   
    void t() 
	{
   cout<<(x+y)<<endl;
b.t();
	}
    class xiao
	{
		
	public:int x;
		xiao(int i)
		{x=i;}
	void t()
		{cout<< x+x<<endl;}
	};
	xiao b;

};

void main()
{
	
da m(2,2,2);
m.t();
da::xiao n=10;
n.t();
cout<<n.x<<endl;




}

