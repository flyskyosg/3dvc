#include<iostream>
#include<string>
using namespace std;

void disp2();
void disp1()
{
	//throw 1;
	disp2();
}

void disp2()
{
	string s="helloc";
	throw s;
}

int main()
{
	try
	{
		disp1();
		//disp2();
	}
	catch(int a)
	{
		cout<<a<<endl;
	}
	catch(string s)
	{
		cout<<s<<endl;
	}
	return 0;
}
