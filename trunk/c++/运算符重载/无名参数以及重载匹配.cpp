#include<iostream>
#include<vector>

using namespace std;

void print(int  a,int =100);  //��������������




void print(int a,double b )
{
	cout<<a<<" "<<b<<endl;
	cout<<2<<endl;
}


void print(char a,double b )
{
	cout<<a<<" "<<b<<endl;
	cout<<3<<endl;
}


void main()
{
	print(97,10); //��Ȼ������������������ʵ�ν��д��ݵ�ʱ����������Ӧ���͵�ʵ��
	print(97,10.0);
	print(char(97),10.0);

}


void print(int a,int  )  //����������������
{
	cout<<a<<" "<<endl;
	cout<<1<<endl;
}