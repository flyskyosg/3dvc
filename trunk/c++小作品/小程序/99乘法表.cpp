#include<iostream>
#include<iomanip>

using namespace std;

void main()
{
	int i=1;
	cout<<"*";
	for(i=1;i<=9;i++)
		cout<<setw(4)<<i;
	cout<<endl;
	for(i=1;i<=9;i++)
	{
		cout<<i;
		for(int j=1;j<i;j++)
		{
			
			cout<<setw(4)<<" ";
		}
		for(;j<=9;j++)
			cout<<setw(4)<<i*j;
		cout<<endl;
	}
     
}
