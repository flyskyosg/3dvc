#include<iostream.h>                                                                                                                                              
void zh(int n,int m)
{
	char a[20];int i,j;
	for(i=0;n>0;i++)
	{
		j=n%m;
		if(j<10) a[i]=j+48;
		else a[i]=j+55;
		n=n/m;
	}
    for(i=i-1;i>=0;i--)
		cout<<a[i];
    cout<<endl;
}
void main()
{
	int n1,m1;
	cout<<" 请输入数据n1与进制m1的值"<<endl;
	cin>>n1>>m1;
	cout<<"n1="<<n1<<"m1="<<m1<<endl;
	zh(n1,m1);
    cout<<"按任意建返回";
	
}
		
	 