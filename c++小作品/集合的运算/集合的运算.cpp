#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
template<class o>                //ʹ��ģ�壬������ͬ���������͡�//
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
				{t=a[j];a[j]=a[j+1];a[j+1]=t;};
			}
	}
    void jj1(o a[],int n)                //ɾȥ�ظ���Ԫ��//
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

    void jj2(o a[],int na,o b[],int nb )    //ɾȥ�ظ���Ԫ��//
	{
		o *t1=new o  [na];int ja=0;               //�ֱ��a��b�����ļ��ϴ�ŵ�t1��t2��ȥ��//
		for(int i=0;i<na;i++)
		{
			if(a[i]!=a[i+1]) {t1[ja]=a[i];ja++;}
			else continue;
		}
		o *t2=new o[nb]; int jb=0;          //��t2���ٵĿռ�ļ�����b�Ĵ�С��//
        for( i=0;i<nb;i++)
		{
			if(b[i]!=b[i+1]) {t2[jb]=b[i];jb++;}          
			else continue;
		}
           int k=0;
		o *u=new o[ja<jb?ja:jb];            
		for( i=0;i<ja;i++)                  //����t1�е�ÿ��Ԫ�غ�t2�е�ÿ��Ԫ�رȽϣ���������ǵ���ͬ��Ԫ�أ������u��//
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
 
	void jj3(o a[],int na,o b[],int nb )     //ɾȥ�ظ���Ԫ���ǻ����Ĺ��ܣ�����ʹ�õ��ǵ�ַ���ݣ�//
	{
		o *t1=new o[na];int ja=0;
		for(int i=0;i<na;i++)
		{
			if(a[i]!=a[i+1]) {t1[ja]=a[i];ja++;}   //ɾȥt1��t2���ظ���Ԫ��//
			else continue;
		}
		o *t2=new o[nb]; int jb=0;
        for( i=0;i<nb;i++)
		{
			if(b[i]!=b[i+1]) {t2[jb]=b[i];jb++;}
			else continue;
		}
           int k=0;
		o *u=new o[ja<jb?ja:jb];     //��һ���ͼ��ϵĽ������е�һ��,���󼯺ϵĽ�����//
		    for( i=0;i<ja;i++)       //���ݼ��ϵĽ����󼯺ϵĲ.u��������������ϵĽ���,��u���ٵĿռ������������н�С��һ�����ϵ�Ԫ�صĸ���//
			for(int j=0;j<jb;j++)
			{
				if(t2[j]==t1[i]) {u[k]=t2[j];k++;};   //�����k��ʾ����u�н���Ԫ�صĸ���,//    
			}
		o *l=new o[na];int z=0,w=0;  //�����l��������¼t1�в����ڽ�����Ԫ�ص�λ�õ�,����Ĵ�С��t1�Ĵ�Сһ����t1�Ĵ�С�Ǽ������//
		                  
			for(i=0;i<na;i++)
			{
				z=0;                      //����Ҫע��ÿ��ѭ����z����//
				for(int j=0;j<k;j++)
				{
					if(t1[i]==u[j]) { z++;};     //z������Ϊһ�����أ����z����0˵���뽻���ȽϺ��Ԫ�ز��뽻���е�Ԫ����ͬ����֮���Ϊ1��˵���ͽ����е�һ��Ԫ����ͬ//
				}
				if(z==0) {l[w]=t1[i];w++;};     //���z����,�Ͱ�t1�����Ԫ�ش淽��l��ȥ��w����¼l��Ԫ�صĸ�����      //         
			}
			cout<<"���������ϵĲ��:"<<endl;
			for(i=0;i<w;i++)
			{
				cout<<l[i];
			}
			cout<<endl;
	}
	

    void operator -(jh b)       //���������,�ڴ�����������Ľ���//
	{
		px(p,m);
		px(b.p,b.m);
		jj3(p,m,b.p,b.m);
    }
	

       

    void operator *(jh b)       //���������,�ڴ�����������Ľ���//
	{
		px(p,m);
		px(b.p,b.m);
		jj2(p,m,b.p,b.m);
    }
	
	void operator +(jh b)       //��������أ��ڴ�����������ļ�//
	{
		o *a=new o [m+b.m];  //��̬�����ڴ�//
		
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
	
cout<<"�����һ������Ԫ�صĸ���:"<<endl;

}
inline void part2()
{
	cout<<"����ڶ�������Ԫ�صĸ���:"<<endl;
}
inline void part3()
{ 
	cout<<"�������������"<<endl;
    getchar();
}
inline void part4()
{
	cout<<"������Ҫ�Ƚϵļ��ϵ����ʣ�1-���μ���.2-�ַ��ͼ���.3-�����ͼ���."<<endl;
}
inline void part5()
{
cout<<"����������������롣"<<endl;
}



void main1()
{
	cout<<"==========================���ϵĲ�����=============================="<<endl; 
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
	cout<<"==========================���ϵĲ�����=============================="<<endl; 
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
	cout<<"==========================���ϵĽ�����=============================="<<endl; 
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

     cout<<"==============================���ϵ�����=================================="<<endl;
a0:		cout<<"��������Ҫ�������������:"<<endl;
	cout<<"������-1.������-2.������-3.�˳�-0."<<endl;
    int m;
	cin>>m;
	switch(m)
	{
	case 1:main1();break;
	case 2:main2();break;
	case 3:main3();break;
	case 0:cout<<"ллʹ��"<<endl;break;
	default:cout<<"�����������������"<<endl;goto a0;
	}
	cout<<"��������˳���ϵͳ."<<endl;
	getchar();
}


       
































