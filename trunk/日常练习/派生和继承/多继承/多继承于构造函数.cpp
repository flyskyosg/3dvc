#include<iostream.h>
class xiao    //��Ϊ����ʹ��//
{
private:      
	int x;
protected:
	int y;
public:
	int z;
    xiao(int i,int j,int k)
	{
		x=i;y=j;z=k;
	}
	void disp()
	{
		cout<<x<<endl;
	}
	void disp1()
	{
		cout<<x<<y<<z<<endl;
	}
};
class xiao1
{
	int v;
public:
	xiao1 (int i)
	{v=i;}
	void disp2()
	{
		cout<<v<<endl;
	}
};

class da :private xiao ,private xiao1   //˽�м̳�//
{
	int w;xiao m;  xiao1 n;         //�����൱�� ����Ļ�����Ӷ���//
public:
	da(int i,int j,int k,int l,int b):xiao(i,j,k),xiao1(b),m(i,j,k),n(b)     //���̳еĹ��캯����//
	{
		w=l;
	}
	void output()
	{	
		disp();	
		disp2();                       //���۵�˽�г�Աֻ��ͨ�����û���ĳ�Ա���������û������������������������//
	    cout<<y<<endl<<z<<endl<<w<<endl;     
		m.disp1();
	
		
	}
};



void main()
{
   da x(10,20,30,40,50);
   x.output();
}
	





	