#include<iostream.h>
int n=100;
int &f(int m)
{
	n+=m;
	return n;
}
void main()
{   
	int m=100;
	f(m)+=100;
	cout<<n<<endl;
}
