#include<iostream>             //ģ��Ĳ�������

using namespace std;

template<class T,int i=0>             
class xiao
{
	T a;
	public:
		xiao(T x)
		{a=x;}

};


template<class T ,class U=xiao<T> >     //ģ���������Ϊ��һ��ģ������
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

class zhong
{
	int a;
public:
	zhong()
	{}


};



int main()
{
	zhong y;
	char z='a';
	xiao<int> a(10);        //��������
	xiao<zhong> b(y);       //�Զ�������
    xiao<char *> c(&z);     //ָ������
    xiao<int,10-5> d(5);    //�������ʽ    �����ʱ��Ҫ��ģ������е����ͱ��ǻ������Ͳμ�xiao�Ķ���



	return 0;
}
