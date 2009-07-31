#include<iostream.h>
int n=100;
int *sum(int m)
{
   n+=m;
   return(&n);
}
void main()
{
	int m=100,*p;
	p=sum(m);
	cout<<*p;
}

