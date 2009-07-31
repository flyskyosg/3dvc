#include<iostream.h> // 必须重载为成员函数
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
		if(m>n-1)                              //因为字符数组的最后一个字符是结束符,数组的第一个元素的下标是从零开始的。//
		{cout<<"数组下标越界";return (' ');}
		
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
