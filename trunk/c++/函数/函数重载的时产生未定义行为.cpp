#include<iostream>      //�������ص�ʱ����δ������Ϊ

using namespace std;

void disp(long a)
{
	cout<<0<<endl;
}

void disp(char);
int main()
{
	disp(10);      //������ƥ���ʱ��᲻֪������char ���ǵ��� long ������δ������Ϊ������취������disp(int)�������߽�������ת��
	return 0;
}


void disp(char a)
{
	cout<<1<<endl;
}