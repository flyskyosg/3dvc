#include<iostream.h>
#include<string.h>
#define N 5
#include<iomanip.h>
void main()
{
	int i,j;
	char a[N][10];
	for(i=0;i<N;i++)
	{
		cout<<"输入第"<<i+1<<"个人的名字";
		cin>>a[i];
	}
   

		
    int k; char *b[N]; char *m;
	k=N;
	for(i=0;i<N;i++)
		b[i]=a[i];
	for(i=0;i<=N-2;i++)
	{
		for(j=0;j<=k-2;j++)
		{
			if(strcmp(b[j],b[j+1])>0)  {m=b[j],b[j]=b[j+1],b[j+1]=m;};
		}
	k--;
	}
	for(i=0;i<N;i++)
		cout<<setw(3)<<a[i];
	cout<<endl;
	for(i=0;i<N;i++)
		cout<<setw(3)<<b[i];
	cout<<endl;
}

	
