#include<iostream>         //一些有趣的用法


#include<fstream>
#include<string>
using namespace std;


void f(int a,int b=0)
{
	cout<<a<<" "<<b<<endl;
}

int main()
{
  



	int b=10,c=20;
    
	if(10<=b<=20)
	f(b,c);
	else
	f((b,c));
    
	cout<<int(10)<<endl;
	return 0;
    
}