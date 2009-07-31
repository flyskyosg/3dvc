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
		cout<<"再次抛掷"<<endl;
		throw;                      //异常的再次抛出
	}
   }
   catch(bad)
   {
	   cout<<"再次捕获"<<endl;
   }
	
}