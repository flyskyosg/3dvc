#include<iostream.h>
class da
{
	int x;
public:
	da (int i)
	{
		x=i;
	}
	void disp()
	{
		cout<<x<<endl;
	}
	friend class xiao;
};
class xiao
{
	int y;da z;
public:
	xiao(int i,int j):z(j)
	{
		y=i;  
	}
	void disp()
	{
		cout<<y<<endl<<z.x<<endl;
		z.disp();
	}
   

};
void main()
{
	
	int *p=new int ,*q=new int ;cout<<"输入两个值";
    cin>>*p>>*q;
	xiao m(*p,*q);
	m.disp();
}