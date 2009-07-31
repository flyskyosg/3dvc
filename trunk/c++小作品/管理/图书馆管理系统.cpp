
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
    
      cout<<"请输入读者的姓名:";cin>>a;
    
	
		cout<<"请输入第"<<i+1<<"本书的资料:"<<endl;
		cout<<"书名:";cin>>b;cout<<endl;
		cout<<"书号:";cin>>num;cout<<endl;
		cout<<"简介:";cin>>c;cout<<endl;
	    return   reader(a,b,num,c);
		
	
}
void main()
{
	int *n=new int;  
    a0: cout<<"请输入您要借书的册数"<<endl;
	scanf("%d",n);
	if(*n<=0) {cout<<"输入错误，请重新输入."<<endl; goto a0;};
    if(*n>5) {cout<<"每人最多借5本,请重新输入."<<endl;goto a0;};
    reader *x=new reader[*n];
    for(int i=0;i<*n;i++)
    {
	   x[i]=shuru(i);
    }
    cout<<"以下是您的借书证的属性:"<<endl;
	for(int j=0;j<*n;j++)
	{

		x[j].disp();
	}
	delete []x;
	cout<<"按任意键退出本系统."<<endl;
	getchar();
}

	


	

