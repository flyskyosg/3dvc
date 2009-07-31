#include<iostream.h>
#include<stdio.h>
void px(char *p)
{
	int i,j,k;
    for(k=0;p[k]!='\0';k++);
	for(i=1;i<=k-1;i++)
	{
		for(j=0;j<k-i;j++)  
		{
	
		  if(p[j]>p[j+1]) p[j+1]=p[j];
		}  
	}
	cout<<p<<endl;
}


void del(char *p)
{
	char *q=new char[11]; static int j=0;
	for(int i=0;i<=10;i++)
		q[i]='\0';
    for( i=0;p[i]!='\0';i++)
	{
		if(p[i]!=p[i+1]) {q[j]=p[i];j++;}
		else continue;
	}
cout<<q<<endl;
}

void main()
{
	char *p=new char[11];
	for(int i=0;i<=10;i++)
		p[i]='\0';
		cout<<"请输入字符串:";
	cin>>p;
	px(p);
	del(p);
	cout<<"按任意键返回";getchar();
}
	
