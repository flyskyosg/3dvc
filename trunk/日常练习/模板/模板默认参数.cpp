#include<iostream>             //ģ��Ĭ�ϲ���

using namespace std;

template<class T>              //��ģ���趨Ĭ�ϲ���Ϊ�������ͣ�Ҳ��������Ϊ�Զ������ͱ����ࣩ
class xiao
{
	T a;
	public:
		xiao(T x):a(x)
		{}
	void disp()
	{
		cout<<a<<endl;
	}
};


template<class T ,class U=xiao<T> >     //��ģ���趨Ĭ�ϲ���Ϊģ������,����Ҫע������ĺ�һ��������ģ������Ҫ������ǰ�ߵ�����
class da
{
   T b;
   U a;
   public:
	   da(T y,U x):b(y),a(x)
	   {}
   void disp()
   {
	   cout<<b<<endl;
	   a.disp();
   }
};


int main()
{
	xiao<double> b(20);
	xiao<int> b1(20.0);//2222
	
	da<double> a(10,b);
	da<int> a1(10,b1) ;  //��Ϊģ�岻�ܽ��б�׼�Ĳ���ת����������ʹ����������ģ����Ϊ�Լ������Ͳ���ʱ��Ҫע������һ��,�����b���г�ʼ���ͻ����
	a.disp();
	a1.disp();
	return 0;
}
