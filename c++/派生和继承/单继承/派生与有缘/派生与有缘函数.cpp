#include<iostream.h>
class xiao
{
private:int x;
protected:int y;
public:int z;
	xiao(int i,int j,int k)
	{
		x=i;y=j;z=k;
	}
	void disp()
	{
		cout<<"x="<<x<<endl;
	    cout<<"y="<<y<<endl;
    }
};
class da:private xiao
{
	int w;
protected:int v;
public:
	da(int i,int j,int k,int l,int b):xiao(i,j,k)
	{
		w=l;v=b;
	}
	
	friend void f(da &p);
    friend class  mid;
};
class mid
{
	da o;
public:
	mid(int i,int j,int k,int l,int b):o(i,j,k,l,b)
	{
	
	}
	void disp()
	{
		
		cout<<"o.w="<<o.w<<endl;
		cout<<"o.v"<<o.v<<endl;
		cout<<"o.z="<<o.z<<endl;
		o.disp();
	}
};
void f(da &p)  //���������Ե���������ܷ����������˽�кͱ�����Ա�⣬��ֻ�ܷ���������ĸ���Ĺ��г�Ա��������е�˽�кͱ�����Ա�ǲ��ܱ����������Ե���ʵ�//
{              
	
	cout<<"p.w="<<p.w<<endl<<"p.v"<<p.v<<endl<<"p.z="<<p.z<<endl;
	p.disp();  //���Ҫ���ʣ�ֻ��ͨ����Ե�������������дӸ���̳й����ĸ���ĳ�Ա����������,disp()��������da��xiao�м̳�����xiao�Ĺ��г�Ա����//

}
void main()
{
	da x(1,2,3,4,5);
	mid y(1,2,3,4,5);
	f(x);
	y.disp();
}




