#include<iostream.h>
double atoe(char s[])
{
	int i,k=0,n1=0,n2=0,n3=0,n4=0;
	char s1[10],s2[2],s3[10],s4[10];
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='E'||s[i]=='e')
		{
			k=1;continue;
		}
		if(k==0)
		{
			s1[n1]=s[i];
			n1++;
		}
		else
		{
			s2[n2]=s[i];
			n2++;
		}
	}
	k=0;
    for(i=0;i<n1;i++)
	{
		if(s1[i]=='.')
		{
			k=1;continue;
		}
		if(k==0)
		{
			s3[n3]=s1[i];
			n3++;
		}
		else
		{
			s4[n4]=s1[i];
			n4++;
		}
	}
	double kk1=0,kk2=0,k1=1,k2=.1;
	for(i=n3-1;i>=0;i--)
	{
		if(s3[i]>='0'&&s3[i]<='9')
		{
			kk1=kk1+(s3[i]-48)*k1;
			k1=k1*10.;
		}
		else kk1=0;
	}
	for(i=0;i<n4;i++)
	{
		if(s4[i]>='0'&&s4[i]<='9')
		{
			kk2=kk2+(s4[i]-48)*k2;
			k2=k2/10.;
		}
		else kk2=0;
	}
	kk1=kk1+kk2;
	int kk3=0,k3=1;
	for(i=n2-1;i>=0;i--)
	{
		if(s2[i]>='0'&&s2[i]<='9')
		{
			kk3=kk3+(s2[i]-48)*k3;
			k3=k3*10;
		}
		else kk3=0;
	}
	if(kk3>0)
	{
		for(i=0;i<kk3;i++)
			kk1=kk1*10.;
	}
	return kk1;
}
void main()
{
	int k;


	char ss[20];
	cout<<"Enter data:";
	cin>>ss;
	cout<<atoe(ss)<<endl;
    cout<<"按任意建返回";
	cin>>k;
}
