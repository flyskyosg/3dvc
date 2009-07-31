#include<iostream>
#include<string>
using namespace std;

int  sqr(int n )
{

	int sum=1;
	for(int i=1;i<=n;i++)
		sum*=10;
	return sum;
}
int sqr3(int i)
{
	return i*i*i;
}



void main()
{
	string s;
	cout<<"input data:";
	cin>>s;
	int sum=0,sum3=0;

    
	for(int i=s.length()-1,j=0;i>=0,j<s.length();j++,i--)
	{
		sum+=(s[j]-48)*sqr(i);
		sum3+=sqr3(s[j]-48);
	}
	cout<<"this is"<<" "<<(sum==sum3?" ":"not")<<"true"<<endl;
	
}
		


