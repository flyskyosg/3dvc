#include<iostream.h>
#include<string.h>
class xiao                   //��Ҫ������ֹ������ݳ�ԱΪָ��ʱ���ڶ����໥��ֵ��ʱ�����ǵ����ݳ�Աָ��ָ��ͬһ���洢�ռ�//
{
	char *p,*q;
public:
	xiao(char *a,char *b)
	{
		p=new char[strlen(a)+1];     //ָ���ڸ�ֵ�ַ�����ʱ������ȸ��������ڴ�ռ�,����ֻ�����䶨���ʱ����丳ֵ//
		strcpy(p,a);
        q=new char[strlen(b)+1];  //�ַ�ָ��������strcpy ����ֵ�ַ���//
        strcpy(q,b);
	}
	xiao ()
	{
	}
	void disp()
	{
		cout<<p<<endl<<q<<endl;
	}
    xiao operator =(xiao &b)
	{
		p=new char[strlen(b.p)+1];
	    q=new char[strlen(b.q)+1];
		strcpy(p,b.p);
		strcpy(q,b.q);
		return *this;
	}
};
void main()
{
	char *m=new char[11],*n=new char [11];
	cout<<"���������ַ���:";
	cin>>m>>n;

	xiao a("sias","sias"),b;xiao c("С","С"),d(m,n);
    b=a;
	b.disp();
	a=c;
	a.disp();
    b.disp();
	a=b=d;
    a.disp();
    b.disp();
}
