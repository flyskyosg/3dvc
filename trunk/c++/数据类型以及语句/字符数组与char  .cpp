#include<iostream>            //�ַ�������char * 
#include<string>

using namespace std;


const char * disp()
{
	return "hello\n";
}

int main()
{
	cout<<disp();				//��char * ��Ϊ��ֵ����
   
	char a[]="he"  "llo";       //֧�ַ��붨��
	char b[]="wo"
		     "rld";
	cout<<a<<b<<endl;	      

	char * p="hello";           //char * �ĳ�ʼ��ʹ��
		   p="world";    
	       p=a;
	cout<<p<<endl;

                                //�������ַ���������ʼ��char * ,��֮������
	cout<<p<<" "<<*p<<" "<<p[0]<<" "<<++p<<endl; //char * ����ȿ��Ա�ʾ��������Ҳ���Ա�ʾָ�򵥸��ַ���ָ�� 
    cout<<p<<" "<<*p<<" "<<p[0]<<" "<<++p<<endl;
	cout<<strlen(a)<<sizeof(p)<<endl;
    system("pause"); 


    return 0;


}
