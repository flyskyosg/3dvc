#include<iostream.h>          //�����쳣����
class base
{
	int x;
public:
	base(){cout<<"���ù��캯��1"<<endl;}
	base(int i)
	{
		cout<<"���ù��캯��2"<<endl;
		if(i<0) throw i;
		x=i;

	}
	~base(){cout<<"������������"<<endl;}
	void disp()
	{
		cout<<"x="<<x<<endl;
	}
};
void f()
{
	int i;
	cout<<"����������:";cin>>i;
	if(i<0) throw i;
	base b(i);
	cout<<"����������:";cin>>i;
    
    base c(i);
}
void main()
{
	try
	{
		f();
	}
	catch(int )
	{
		cout<<"�������."<<endl;
	}
	catch(...)
	{}
	
}
	
