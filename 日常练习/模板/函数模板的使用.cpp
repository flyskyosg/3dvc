#include<iostream>
#include<string>

using namespace std;


template <class t,class r>     //���Ͳ��������������Ҳ����ʹ���//                      
t max(t a,r b )
{
	return a>b?a:b;
}


template <class t>
t max(t a,t b, t c)                      //�Ͳ���Ϊ2���ĺ���ģ������//
{
	return (a>b?a>c?a:c:b>c?b:c);
}


template <typename T ,int m>
void alloc(T * &  n)
{
     n=new T [m];
     cout<<"����"<<m<<"���ռ�ɹ�"<<endl; 
     
}


void max(int a)                        //һ�㺯���ͺ���ģ������//
{
	cout<<a*a<<endl;
}int main()
{
	int a=10,b=20,e=30;
	double c=10.23,d=12.32,f=23.21;
	char g='a',h='b';               //�ַ��������ڱȽϵ�ʱ���ǱȽ���asc��ֵ//
	cout<<max(a,b)<<endl;
	cout<<max(c,d)<<endl;
	cout<<max(a,b,e)<<endl;
	cout<<max(c,d,f)<<endl;
	cout<<max(g,h)<<endl;
	max(a);
	
	int * n;
	alloc<int,10>(n); 
	
	system("pause");
	return 0;
}
