#include<iostream>            //
#include<cstdlib>
using namespace std;

class exe
{
	int a;
};
int a;

void disp()
{
	cout<<"stop"<<endl;
}

int main()
{
	
	cout<<"come on"<<endl;
    atexit(disp);              //�������ó�������ֹǰִ�еĲ�����atexit������Ϊvoid()���������в����������з�������
	exit(1);                   //ֱ����ֹ���� 
	//abort();                 //ǿ����ֹ����
	cout<<"baby"<<endl;

	return 0;



}
