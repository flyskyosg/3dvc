#include<iostream>     //��׼���е��쳣�����Զ���쳣Ƕ�ײ���
#include<string>
#include<exception>
using namespace std;

void disp2();
void disp1()
{
	try
	{
	
	disp2();
	}
	catch(char)
	{
		cout<<"char"<<endl;
	}
}

void disp2()
{
	
	throw 10.0;
	//throw 'a'; ͬ��
}

int main()
{
	try
	{
		disp1();
		//disp2();
	}
	catch(double )         //���쳣������ƥ��,�������о�ȷƥ�䣬���������͵�ת��
	{
		cout<<endl;
	}
	catch(string s)      //ͨ�������������쳣��״̬
	{
		cout<<s<<endl;
	}
	catch(...)           //�����������͵��쳣
	{
		cout<<"catch"<<endl;
	}

	try 
	{

	int * p =new int [100000000];  //�����쳣
	}
	catch(bad_alloc)               //  ��exception�ж���
	{
		cout<<"bad aloc"<<endl;
	}
	string s="success";
	cout<<s+string("hello")<<endl;
	cout<<s+"hello"<<endl;
	return 0;
}
