#include<iostream>            //��������ʡ��

using namespace std;

void disp(long a ...)		  //�����Ĳ�������ȷʱ������ʡ�ԺŴ���
{
	cout<<0<<endl;
}

void disp(char);
int main()
{
	
	disp(char(10),int(20));   //�ں�����������ȷ������¿��Լ��Ϻܶ������������������о�ȷƥ��
	return 0;
}


void disp(char a)
{
	cout<<1<<endl;
}