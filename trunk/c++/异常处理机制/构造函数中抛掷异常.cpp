#include<iostream.h>
class base
{
	int x;
public:
	base(){cout<<"���ù��캯��1"<<endl;} //���캯���������쳣
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
void main()
{
	try
	{
		base a,b(1),c(-1);
	}
	catch(int )
	{
		cout<<"�������."<<endl;
	}
	catch(...)
	{}
	
}
	
