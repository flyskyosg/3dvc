#include<iostream> //��ָ���ת���Ͷ������Լ�δ������Ϊ
#include<string>
//#include<iomanip>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;







void main()
{
	float d=34.5;
	int * i=(int *)(&d);      //��d�ĵ�ַת��Ϊint * �͵�
	cout<<d<<" "<<&d<<endl;
	cout<<*i<<" "<<i<<endl;
	*i=100;
	cout<<*i<<endl;       
	cout<<d<<endl;            //�����в�Ҫʹ�ò�ָͬ����ת��


	int a=100;
	int & const  b=a,&c=a;      //һ�����������ֶ������,����Ҳ����ʹ��const���η����޶����÷���ָ�����ƣ����õ��ڲ�ʵ�ֻ���ָ��

	cout<<a<<" "<<b<<endl;
	b=50;
	cout<<(b=10)<<" "<<b<<"��"<<c<<endl;         //b=10Ϊ������Ϊ��������������10����b;
	cout<<&a<<" "<<&c<<endl;       //������ԭ�����ĵ�ַһ��
	
     int f=(b=200)*10;             
	 cout<<b<<" "<<f<<endl;

}



