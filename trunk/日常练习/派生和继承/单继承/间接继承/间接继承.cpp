#include<iostream.h>
class xiao 
{
private:int x;
protected:int y;
public:int z;
	xiao(int i)
	{
		z=y=x=i;
	}
	void disp()
    {
		cout<<x<<endl<<y<<endl<<z<<endl;
	}
};
class da:public xiao             //������ֱ�Ӽ̳л��Ǽ�Ӽ̳У����඼��ͨ�����������н������������Ӷ���ķ�ʽʵ�õģ�Ҳ����˵���������г��ֵĸ���ĳ�Ա���ڸ����������Ӷ���ĳ�Ա,��ȻҲ���Զ�����ʾ�ĸ�����Ӷ���
                                  //�������Ĺ��캯���޲����������������еĹ��캯������Ҫ�Ӹ��ഫ�ݲ�������֮�в���ʱ����Ҫ���ݲ���//
{
	int w;
public:
	da(int i,int j):xiao(i)
	{
		w=j;
	}
	void disp()
	{
	    cout<<w<<endl;
	}
	
};
class shi:public da
{
	int r;
public:
	shi(int i,int j,int k):da(j,k)
	{
		r=i;
	}
	void disp()
	{
		xiao::disp();
		da::disp();
		cout<<r<<endl;
	}
};
void main()
{
	shi a(10,20,30);
	a.disp();
}

