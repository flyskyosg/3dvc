#include<iostream.h>
class xiao
{
private:int x;
protected:int y;
public:	int z;


	xiao(int a,int b,int c)
	{
		x=a;y=b;z=c;
	}
	void disp()
	{
		cout<<x<<endl<<y<<endl<<z<<endl;
	}
};
class da :private xiao
{
	int w;int y;    //�������൱�ж����ڻ�����ͬ���ֵ����ݳ�Ա��ʹ��ʱ������ĳ�ԭ�����ǻ����ͬ����Ա�����Ҫʹ�û����ͬ�����ݳ�Ա������������Ԥ�����ϾͿ���ʹ��//
     
public:xiao:: z,xiao:: disp;   //�÷���˵�����ָ����̳е�������ԭ�����൱�е�����,����ظ�Ϊԭ���ڻ����е�public���ԣ�ע�����ݳ�Ա�ͺ���Ա�����ĸ�ʽ��һ������Ա��������Ҫ���ϲ����б�//
    da(int i,int j,int k):xiao(i,i,i)
	{
		w=k;y=k;
	}
	void output()
	{
		cout<<y<<endl<<xiao::y<<endl;  //�����y���������е�y,��߼���xiao::�ǻ����y//
		disp();
	}
};
void main()
{
	da x(10,20,30);
	x.output();
}





