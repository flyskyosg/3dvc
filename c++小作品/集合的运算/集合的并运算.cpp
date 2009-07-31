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
	void shuru()                //来输入集合所需的数据//
	{
		cout<<"请输入一个集合:"<<endl;
		for(int i=0;i<m;i++)
		{
			cout<<"第"<<i+1<<"个数据"<<endl;
			cin>>p[i];
		}
	}
    
	
	void px(o a[],int n)      //对合并后的两个集合进行排序处理，以备后来的删去重复的元素使用//
	{
		o t;
		for(int i=1;i<n;i++)
			for(int j=0;j<n-i;j++)
			{
				if(a[j]>a[j+1]) 
				{t=a[j];a[j]=a[j+1];a[j+1]=t;}
			}
	}
    void jj(o a[],int n)     //删去重复的元素//
	{
		o  *t=new o  [n];int j=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]!=a[i+1]) {t[j]=a[i];j++;}
			else continue;
		}
		cout<<"这两个集合的并集是:"<<endl;
		for(i=0;i<j;i++)
		{  cout<<"  ";
			cout<<t[i];
		}
		cout<<endl;
	}

     void operator +(jh b)       //运算符重载，在处理两个对像的集//
	{
		o *a=new o [m+b.m];  //动态分配内存//
		
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
cout<<"==========================集合的并运算=============================="<<endl; 
	int m;
a0:	cout<<"请输入要比较的集合的性质：1-整形集合.2-字符型集合.3-浮点型集合."<<endl;
	cin>>m;
	switch(m)
	{
	case 1: 
	{
	int i,j;
    cout<<"输入第一个集合元素的个数:"<<endl;
    cin>>i;
	jh <int> a(i);
	a.shuru();
	cout<<"输入第二个集合元素的个数:"<<endl;
    cin>>j;
	jh <int>b(j);
	b.shuru();
	a+b;
    cout<<"按任意键结束。"<<endl;
    getchar();
	}       break;
	case 2: 
	{
	int i,j;
    cout<<"输入第一个集合元素的个数:"<<endl;
    cin>>i;
	jh <char> a(i);
	a.shuru();
	cout<<"输入第二个集合元素的个数:"<<endl;
    cin>>j;
	jh <char>b(j);
	b.shuru();
	a+b;
    cout<<"按任意键结束。"<<endl;
    getchar();
	}        break;
	case 3: 
	{
	int i,j;
    cout<<"输入第一个集合元素的个数:"<<endl;
    cin>>i;
	jh <double> a(i);
	a.shuru();
	cout<<"输入第二个集合元素的个数:"<<endl;
    cin>>j;
	jh <double>b(j);
	b.shuru();
	a+b;
    cout<<"按任意键结束。"<<endl;
    getchar();
	}        break;
	default:cout<<"输入错误，请重新输入。"<<endl;goto a0;
	}


}





