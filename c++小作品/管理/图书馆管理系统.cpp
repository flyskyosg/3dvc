
#include<iostream.h>
#include<stdio.h>
#include<string.h>
class book
{
	char *p;int num;char *q;
public:
	book(char *a,int b,char *c)
	{
		p=new char[strlen(a)+1];
		q=new char[strlen(c)+1];
		strcpy(p,a);strcpy(q,c);
		num=b;
	}
	book(){}
	void disp()
	{
		cout<<p<<endl<<num<<q<<endl;
	}
};

class reader :public book
{
	char *name; 
public:
	reader(char *n,char *a,int b,char *c):book(a,b,c)
	{
		name=new char[strlen(n)+1];
		strcpy(name,n);
	}
	reader()
	{}
	void disp()
	{
		cout<<name<<endl;
		book::disp();
	}
};
reader shuru(int i)
{
      char a[5];char b[10];int num;char c[20];
    
      cout<<"��������ߵ�����:";cin>>a;
    
	
		cout<<"�������"<<i+1<<"���������:"<<endl;
		cout<<"����:";cin>>b;cout<<endl;
		cout<<"���:";cin>>num;cout<<endl;
		cout<<"���:";cin>>c;cout<<endl;
	    return   reader(a,b,num,c);
		
	
}
void main()
{
	int *n=new int;  
    a0: cout<<"��������Ҫ����Ĳ���"<<endl;
	scanf("%d",n);
	if(*n<=0) {cout<<"�����������������."<<endl; goto a0;};
    if(*n>5) {cout<<"ÿ������5��,����������."<<endl;goto a0;};
    reader *x=new reader[*n];
    for(int i=0;i<*n;i++)
    {
	   x[i]=shuru(i);
    }
    cout<<"���������Ľ���֤������:"<<endl;
	for(int j=0;j<*n;j++)
	{

		x[j].disp();
	}
	delete []x;
	cout<<"��������˳���ϵͳ."<<endl;
	getchar();
}

	


	

