#include<iostream>      //������������

using namespace std;

void disp(double a)
{
	cout<<0<<endl;
}


int main()
{
	void disp(int);    //�ھֲ��������������ĺ���ȫ��������ͬ�������أ������ھֲ��������ھֲ�����������Ч,�����Ҫʹ��ȫ�ֵģ���Ҫʹ���������
	::disp(10.0);
	return 0;
}


void disp(int a)
{
	cout<<1<<endl;
}