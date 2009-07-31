#include<iostream.h>
void main(  )
{   
	int *p;        
	p=new int;

	cout<<"shuru";
	cin>>*p;
	int *a=new int[*p];
	delete p;
	a[0]=1;cout<<a[0];
	delete a;

}
