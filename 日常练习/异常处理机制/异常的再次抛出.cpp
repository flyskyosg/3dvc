#include<iostream>

using namespace std;

class bad
{
};

void f()
{
	throw bad();
}

int main()
{

   try
   {
	try
	{
		f();
	}
	catch(bad)
	{
		cout<<"�ٴ�����"<<endl;
		throw;                      //�쳣���ٴ��׳�
	}
   }
   catch(bad)
   {
	   cout<<"�ٴβ���"<<endl;
   }
	
}