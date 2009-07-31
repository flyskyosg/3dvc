
#include<iostream>      //指向指针的指针的数组 
using namespace std;
void ax(int * * & a ,int n, int m )
{   
	a=new  int * [n];
	for(int i=0;i<n;i++)
		a[i]=new int[m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}			
}


int  main()
{
	
    int * * a; 
	ax(a,4,3); 
    
    for(int i=0;i<4;i++)
		for(int j=0;j<3;j++)
		{
			cout<<a[i][j];
		}
		system("pause");		
}
