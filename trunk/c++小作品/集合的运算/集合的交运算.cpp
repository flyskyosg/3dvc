#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
template <class o>
class jh
{
	o *p;int m;
public:
	jh(int n)
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
    void jj(o a[],int na,o b[],int nb )     //ɾȥ�ظ���Ԫ��//
	{
		o *t1=new o  [na];int ja=0;
		for(int i=0;i<na;i++)
		{
			if(a[i]!=a[i+1]) {t1[ja]=a[i];ja++;}
			else continue;
		}
		o *t2=new o[nb]; int jb=0;
        for( i=0;i<nb;i++)
		{
			if(b[i]!=b[i+1]) {t2[jb]=b[i];jb++;}
			else continue;
		}
           int k=0;
		o *u=new o[ja<jb?ja:jb];
		for( i=0;i<ja;i++)
			for(int  j=0;j<jb;j++)
			{
				if(t2[j]==t1[i]) {u[k]=t2[j];k++;};
			}
			if(k==0) {cout<<"����������û�н���."<<endl;}
			else
			{
            cout<<"���������ϵĽ�����:"<<endl; 
			for(i=0;i<k;i++)
			cout<<" "<<u[i];
			cout<<endl;
			}
			delete [] u;delete [] t1;delete [] t2;
	}
	

       

    void operator *(jh b)       //���������,�ڴ�����������Ľ���//
	{
		px(p,m);
		px(b.p,b.m);
		jj(p,m,b.p,b.m);
    }
};
void main()
{
	cout<<"==========================���ϵĽ�����=============================="<<endl;
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
	a*b;
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
	a*b;
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
	a*b;
    cout<<"�������������"<<endl;
    getchar();
	}        break;
	default:cout<<"����������������롣"<<endl;goto a0;
	}


}
