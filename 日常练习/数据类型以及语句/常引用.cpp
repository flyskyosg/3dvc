#include<iostream>            //�ַ�������char * 
#include<string>

using namespace std;


const char * disp()
{
	return "hello\n";
}

int main()
{
    
    
   
    int c=10;
    int & b=c;  //һ������ 
    
    const int & a=1;  //�����ÿ��������泣������ֵ ,Ҳ�����ó���������ֵ��ͬʱҲ�������ø���ͨ��������ʼ�� 
    const int & d=c;
    const int & e=b; 
   
    cout<<a<<" "<<b<<" "<<c<<endl;
    system("pause");
    
    


}