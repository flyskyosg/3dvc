#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
template<class o>                //使用模板，来处理不同的数据类型。//
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
				{t=a[j];a[j]=a[j+1];a[j+1]=t;};
			}
	}
    void jj1(o a[],int n)                //删去重复的元素//
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

    void jj2(o a[],int na,o b[],int nb )    //删去重复的元素//
	{
		o *t1=new o  [na];int ja=0;               //分别把a和b精简后的集合存放到t1和t2中去，//
		for(int i=0;i<na;i++)
		{
			if(a[i]!=a[i+1]) {t1[ja]=a[i];ja++;}
			else continue;
		}
		o *t2=new o[nb]; int jb=0;          //给t2开辟的空间的极限是b的大小，//
        for( i=0;i<nb;i++)
		{
			if(b[i]!=b[i+1]) {t2[jb]=b[i];jb++;}          
			else continue;
		}
           int k=0;
		o *u=new o[ja<jb?ja:jb];            
		for( i=0;i<ja;i++)                  //来用t1中的每个元素和t2中的每个元素比较，来球的他们的相同的元素，存放在u中//
			for(int  j=0;j<jb;j++)
			{
				if(t2[j]==t1[i]) {u[k]=t2[j];k++;};
			}
			if(k==0) {cout<<"这两个集合没有交集."<<endl;}
			else
			{
            cout<<"这两个集合的交集是:"<<endl; 
			for(i=0;i<k;i++)
			cout<<" "<<u[i];
			cout<<endl;
			}
			delete [] u;delete [] t1;delete [] t2;
	}
 
	void jj3(o a[],int na,o b[],int nb )     //删去重复的元素是基本的功能，这里使用的是地址传递，//
	{
		o *t1=new o[na];int ja=0;
		for(int i=0;i<na;i++)
		{
			if(a[i]!=a[i+1]) {t1[ja]=a[i];ja++;}   //删去t1，t2中重复的元素//
			else continue;
		}
		o *t2=new o[nb]; int jb=0;
        for( i=0;i<nb;i++)
		{
			if(b[i]!=b[i+1]) {t2[jb]=b[i];jb++;}
			else continue;
		}
           int k=0;
		o *u=new o[ja<jb?ja:jb];     //这一布和集合的交运算中的一样,先求集合的交集，//
		    for( i=0;i<ja;i++)       //根据集合的交集求集合的差集.u用来存放两个集合的交集,给u开辟的空间是两个集合中较小的一个集合的元素的个数//
			for(int j=0;j<jb;j++)
			{
				if(t2[j]==t1[i]) {u[k]=t2[j];k++;};   //这里的k表示的是u中交集元素的个数,//    
			}
		o *l=new o[na];int z=0,w=0;  //这里的l是用来记录t1中不属于交集的元素的位置的,分配的大小与t1的大小一样，t1的大小是极限情况//
		                  
			for(i=0;i<na;i++)
			{
				z=0;                      //这里要注意每次循环把z清零//
				for(int j=0;j<k;j++)
				{
					if(t1[i]==u[j]) { z++;};     //z用来作为一个开关，如果z等于0说明与交集比较后该元素不与交集中的元素相同，反之如果为1，说明和交集中的一个元素相同//
				}
				if(z==0) {l[w]=t1[i];w++;};     //如果z满足,就把t1的这个元素存方到l中去，w来记录l中元素的个数。      //         
			}
			cout<<"这两个集合的差集是:"<<endl;
			for(i=0;i<w;i++)
			{
				cout<<l[i];
			}
			cout<<endl;
	}
	

    void operator -(jh b)       //运算符重载,在处理两个对像的交集//
	{
		px(p,m);
		px(b.p,b.m);
		jj3(p,m,b.p,b.m);
    }
	

       

    void operator *(jh b)       //运算符重载,在处理两个对像的交集//
	{
		px(p,m);
		px(b.p,b.m);
		jj2(p,m,b.p,b.m);
    }
	
	void operator +(jh b)       //运算符重载，在处理两个对像的集//
	{
		o *a=new o [m+b.m];  //动态分配内存//
		
        for(int i=0;i<m;i++)
		   a[i]=p[i];
	    for(int j=0;i<m+b.m,j<b.m;i++,j++)
		   a[i]=b.p[j];
		px(a,m+b.m);
		jj1(a,m+b.m);             
	    delete [] a;
	 }
};
inline void part1()
{
	
cout<<"输入第一个集合元素的个数:"<<endl;

}
inline void part2()
{
	cout<<"输入第二个集合元素的个数:"<<endl;
}
inline void part3()
{ 
	cout<<"按任意键结束。"<<endl;
    getchar();
}
inline void part4()
{
	cout<<"请输入要比较的集合的性质：1-整形集合.2-字符型集合.3-浮点型集合."<<endl;
}
inline void part5()
{
cout<<"输入错误，请重新输入。"<<endl;
}



void main1()
{
	cout<<"==========================集合的并运算=============================="<<endl; 
    int m;
a0:	part4();
	cin>>m;
	switch(m)
	{
	case 1: 
	{
	int i,j;
    part1();
    cin>>i;
	jh <int> a(i);
	a.shuru();
	part2();
    cin>>j;
	jh <int>b(j);
	b.shuru();
	a+b;
    part3();
	}       break;
	case 2: 
	{
	int i,j;
    part1();
    cin>>i;
	jh <char> a(i);
	a.shuru();
	part2();
    cin>>j;
	jh <char>b(j);
	b.shuru();
	a+b;
    part3();
    
	}        break;
	case 3: 
	{
	int i,j;
     part1();
    cin>>i;
	jh <double> a(i);
	a.shuru();
    part2();
    cin>>j;
	jh <double>b(j);
	b.shuru();
	a+b;
    part3();
   
	}    part5();break;
	default:;goto a0;
	}


}

void main3()
{
	cout<<"==========================集合的差运算=============================="<<endl; 
    int m;
a0:	part4();
	cin>>m;
	switch(m)
	{
	case 1: 
	{
	int i,j;
    part1();
    cin>>i;
	jh <int> a(i);
	a.shuru();
	part2();
    cin>>j;
	jh <int>b(j);
	b.shuru();
	a-b;
    part3();
	}       break;
	case 2: 
	{
	int i,j;
    part1();
    cin>>i;
	jh <char> a(i);
	a.shuru();
	part2();
    cin>>j;
	jh <char>b(j);
	b.shuru();
	a-b;
    part3();
    
	}        break;
	case 3: 
	{
	int i,j;
     part1();
    cin>>i;
	jh <double> a(i);
	a.shuru();
    part2();
    cin>>j;
	jh <double>b(j);
	b.shuru();
	a-b;
    part3();
   
	}        break;
	default:part5();goto a0;
	}


}
void main2()
{
	cout<<"==========================集合的交运算=============================="<<endl; 
    int m;
a0:	part4();

	cin>>m;
	switch(m)
	{
	case 1: 
	{
	int i,j;
    part1();
    cin>>i;
	jh <int> a(i);
	a.shuru();
	part2();
    cin>>j;
	jh <int>b(j);
	b.shuru();
	a*b;
    part3();
	}       break;
	case 2: 
	{
	int i,j;
    part1();
    cin>>i;
	jh <char> a(i);
	a.shuru();
	part2();
    cin>>j;
	jh <char>b(j);
	b.shuru();
	a*b;
    part3();
    
	}        break;
	case 3: 
	{
	int i,j;
     part1();
    cin>>i;
	jh <double> a(i);
	a.shuru();
    part2();
    cin>>j;
	jh <double>b(j);
	b.shuru();
	a*b;
    part3();
   
	}        break;
	default:part5();goto a0;
	}


}

void main()
{

     cout<<"==============================集合的运算=================================="<<endl;
a0:		cout<<"请输入您要进行运算的类型:"<<endl;
	cout<<"并运算-1.交运算-2.差运算-3.退出-0."<<endl;
    int m;
	cin>>m;
	switch(m)
	{
	case 1:main1();break;
	case 2:main2();break;
	case 3:main3();break;
	case 0:cout<<"谢谢使用"<<endl;break;
	default:cout<<"输入错误，请重新输入"<<endl;goto a0;
	}
	cout<<"按任意键退出本系统."<<endl;
	getchar();
}


       
































