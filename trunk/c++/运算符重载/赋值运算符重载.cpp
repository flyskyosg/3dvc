#include<iostream.h>
#include<string.h>
class xiao                   //主要用来防止类的数据成员为指针时，在对象相互赋值的时候他们的数据成员指针指向同一个存储空间//
{
	char *p,*q;
public:
	xiao(char *a,char *b)
	{
		p=new char[strlen(a)+1];     //指针在赋值字符串的时候必须先给他分配内存空间,否则只能在其定义的时候给其赋值//
		strcpy(p,a);
        q=new char[strlen(b)+1];  //字符指针正能用strcpy 来赋值字符串//
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
	cout<<"输入两个字符串:";
	cin>>m>>n;

	xiao a("sias","sias"),b;xiao c("小","小"),d(m,n);
    b=a;
	b.disp();
	a=c;
	a.disp();
    b.disp();
	a=b=d;
    a.disp();
    b.disp();
}
