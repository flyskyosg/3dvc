#include<iostream.h> // ��������Ϊ��Ա����
#include<string.h>
class xiao 
{    
	char *p;int n;
public:
	xiao (char *a)
	{
		p=new char[strlen(a)+1];
		strcpy(p,a);
		n=strlen(a);
	}
	xiao(){}
	void disp()
	{
		cout<<p<<endl;
	}
	char operator [](int m)
	{
		if(m>n-1)                              //��Ϊ�ַ���������һ���ַ��ǽ�����,����ĵ�һ��Ԫ�ص��±��Ǵ��㿪ʼ�ġ�//
		{cout<<"�����±�Խ��";return (' ');}
		
		else{
			return *(p+m);};
	}
		
		
};
void main()
{
	xiao a("sias");
	a.disp();
	cout<<a[0];
}
