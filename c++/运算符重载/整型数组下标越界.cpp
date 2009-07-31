#include<iostream.h>
#include<stdio.h>
class xiao 
{
	int *p,n;
public:
	xiao(int a[],int m)
	{
		p=new int[m];n=m;
		for(int i=0;i<=9;i++)
			p[i]=a[i];
	}
	xiao (){}
	void disp()
	{
        for(int i=0;i<=9;i++)
		cout<<p[i];cout<<endl;
	}
    int operator [](int m)
	{
		if(m>n-1)
		{cout<<"下标越界"<<endl;return NULL;}
		else  return(*(p+m));
	}
};
void main()
{
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	xiao b(a,10);
	cout<<b[6]<<endl;
	cout<<b[10]<<endl;
}

