#include<iostream.h>
#include<string.h>
void main()
{
	int *a=new int[4],b[4];
	char *c=new char[5],d[5],e[5]={"aaaa"};
    for(int i=0;i<=4;i++)
	{
		a[i]=5;b[i]=6;              
	}	
	cin>>c;cin>>d;
	cout<<c<<endl;
	cout<<d<<endl;
	cout<<e<<endl;
	strcpy(c,"vvvv");strcpy(d,"vvvv");strcpy(e,"vvvv");       //ʹ��strcpy//
	cout<<c<<endl<<d<<endl<<e<<endl;

}
//��c++�У���cout��cin���������������ʱ,Ҫ��ʵ����������������,ֻ�����ַ�����//
//�������鲻������cout<<a;��cin>>a;��������ʽ�����帳ֵ�����//
//�����һ����ַ����飬ֻ���ڶ����ʱ�����ַ�������ʽ����ֵ���������ĵط�������ʹ���ַ�����ֻ������strcpy�����帳ֵ������ʹ��cout<<��cin>>��������������//
//����Ƕ�̬����ռ���ַ����飬����cin>>��cout����ֵ�������Ҳ����strcpy����ֵ��strcpy��ʹ��ʱ����һ������������//
//���е����鶼�����ڳ�����κεط���cout��cin������ֵ�����//
