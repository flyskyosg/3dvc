#include<iostream>                //����ָ��

using namespace std;

void disp(long a )		  
{
	cout<<0<<endl;
}

void disp(char);
int main()
{
	
    void (*p)(long)=disp;        //��������������غ����򵱳�ʼ������ָ���ʱ�򣬻������Щ����ָ��Ķ���ȥƥ�����صĺ���
	void (*q)(char)=&disp;       //�������Ƽ��Ǻ�������ڵ�ַ������ʹ�������ַ�ʽ����ʼ������ָ��
	p(10);                       //��ô��ʹ�ú���ָ���ʱ��Ҳ�������ֵķ�ʽ
	(*q)('a');
	return 0;
}


void disp(char a)
{
	cout<<1<<endl;
}