#include<iostream>         //�����ú�һ������õ��ر���

using namespace std;

void f0(const int a)
{
	cout<<0<<endl;
}

void f1(int & a)
{
	cout<<1<<endl;
}


int main()
{
	int a=10;double b=20.0;

	f0(a);f0(b);f0(10);f0(10.0);     //�������Ĳ����ǳ����õ�ʱ��ǰ�ߵ���Щ����

	f1(a);                           //�����ǳ����õ�ʱ��ֻ�ܾ�ȷƥ�䣬ֻ���Ǹ����͵ı���
	//f1(b);                         //�±ߵ����������Ǵ��
	//f1(10);
	//f1(10.0);

	return 0;
}
