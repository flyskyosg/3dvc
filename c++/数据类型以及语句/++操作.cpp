#include<iostream>

using namespace std;

int main()
{
    int a=1,b=1,c=1,d=1;
    int a0=0,b0=0,c0=0,d0=0;
    a0=(++a)++; //(b++)++;  //�����b++���ص���һ��������ֵ�����ܽ���++�����������������������±ߵ�d++ͬ��,++a���ص���a��������������Ϊ��ֵ
    c0=++(++c);//++(d++);
    cout<<a0<<" "<<a<<endl;
     cout<<" "<<b<<endl;
      cout<<c0<<" "<<c<<endl;
       cout<<" "<<d<<endl;
       return 1;
}
    
     