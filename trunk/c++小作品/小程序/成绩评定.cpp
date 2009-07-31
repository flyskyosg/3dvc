#include<iostream.h>
#include<iomanip.h>
#define N 10
void input(int a[][3],int n)
{
	int i,j;
	for(i=0,j=0;i<n;i++)
	{
		cout<<"输入学号";
		cin>>a[i][j];
		cout<<"输入成绩";
		cin>>a[i][j+1];
		a[i][j+2]=0;
	    cout<<endl;
	}
}

void comp(int a[][3],int n)
{
	int i;int k,sum=0;
	for(i=0;i<n;i++)
		sum+=a[i][1];
	    k=sum/n; 
	for(i=0;i<n;i++)
	{
		if(a[i][1]>=((1+0.2)*k)) a[i][2]=1;
		else 
			if(a[i][1]>=((1+0.15)*k)) a[i][2]=2;
			else 
				if(a[i][1]>=((1+0.1)*k)) a[i][2]=3;
				else a[i][2]=0;
				
	}
}

void output(int a[][3],int n)
{
	int i,j;
	cout<<"学号"<<"成绩"<<"级别"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=2;j++)
			cout<<setw(4)<<a[i][j];
		cout<<endl;
	}
}

void main()
{
	int a[N][3],n=N;
	input(a,n);
	comp(a,n);
	output(a,n);
    	cin>>n;
}