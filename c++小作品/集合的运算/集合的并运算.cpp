#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
template <class o>
class jh
{
	o *p;int m;
public:
	jh(int  n)
	{
		p=new o [n];m=n;
	}
	jh(){}
	void shuru()                //�����뼯�����������//
	{
		cout<<"������һ������:"<<endl;
		for(int i=0;i<m;i++)
		{
			cout<<"��"<<i+1<<"������"<<endl;
			cin>>p[i];
		}
	}
    
	
	void px(o a[],int n)      //�Ժϲ�����������Ͻ����������Ա�������ɾȥ�ظ���Ԫ��ʹ��//
	{
		o t;
		for(int i=1;i<n;i++)
			for(int j=0;j<n-i;j++)
			{
				if(a[j]>a[j+1]) 
				{t=a[j];a[j]=a[j+1];a[j+1]=t;}
			}
	}
    void jj(o a[],int n)     //ɾȥ�ظ���Ԫ��//
	{
		o  *t=new o  [n];int j=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]!=a[i+1]) {t[j]=a[i];j++;}
			else continue;
		}
		cout<<"���������ϵĲ�����:"<<endl;
		for(i=0;i<j;i++)
		{  cout<<"  ";
			cout<<t[i];
		}
		cout<<endl;
	}

     void operator +(jh b)       //��������أ��ڴ�����������ļ�//
	{
		o *a=new o [m+b.m];  //��̬�����ڴ�//
		
        for(int i=0;i<m;i++)
		   a[i]=p[i];
	    for(int j=0;i<m+b.m,j<b.m;i++,j++)
		   a[i]=b.p[j];
		px(a,m+b.m);
		jj(a,m+b.m);             
	    delete [] a;
	 }
};
void main()
{
cout<<"==========================���ϵĲ�����=============================="<<endl; 
	int m;
a0:	cout<<"������Ҫ�Ƚϵļ��ϵ����ʣ�1-���μ���.2-�ַ��ͼ���.3-�����ͼ���."<<endl;
	cin>>m;
	switch(m)
	{
	case 1: 
	{
	int i,j;
    cout<<"�����һ������Ԫ�صĸ���:"<<endl;
    cin>>i;
	jh <int> a(i);
	a.shuru();
	cout<<"����ڶ�������Ԫ�صĸ���:"<<endl;
    cin>>j;
	jh <int>b(j);
	b.shuru();
	a+b;
    cout<<"�������������"<<endl;
    getchar();
	}       break;
	case 2: 
	{
	int i,j;
    cout<<"�����һ������Ԫ�صĸ���:"<<endl;
    cin>>i;
	jh <char> a(i);
	a.shuru();
	cout<<"����ڶ�������Ԫ�صĸ���:"<<endl;
    cin>>j;
	jh <char>b(j);
	b.shuru();
	a+b;
    cout<<"�������������"<<endl;
    getchar();
	}        break;
	case 3: 
	{
	int i,j;
    cout<<"�����һ������Ԫ�صĸ���:"<<endl;
    cin>>i;
	jh <double> a(i);
	a.shuru();
	cout<<"����ڶ�������Ԫ�صĸ���:"<<endl;
    cin>>j;
	jh <double>b(j);
	b.shuru();
	a+b;
    cout<<"�������������"<<endl;
    getchar();
	}        break;
	default:cout<<"����������������롣"<<endl;goto a0;
	}


}





