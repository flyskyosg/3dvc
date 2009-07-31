#include<iostream>     //bool作为int的子类型

using namespace std;

int main()
{
	int n=10,m=0;
	bool a=false,b=n;
	cout<<a<<b<<a+b<<endl;
    m=b;
	cout<<m<<m+b<<endl;
	
	return 0;




}