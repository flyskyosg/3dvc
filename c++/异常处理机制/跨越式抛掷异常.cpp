#include<iostream>    
#include<string>
using namespace std;

void disp2();
void disp1()
{
	
	disp2();
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
	catch(int )         //���쳣������ƥ��,�������о�ȷƥ�䣬���������͵�ת��
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
	return 0;
}
