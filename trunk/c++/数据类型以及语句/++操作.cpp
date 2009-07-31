#include<iostream>

using namespace std;

int main()
{
    int a=1,b=1,c=1,d=1;
    int a0=0,b0=0,c0=0,d0=0;
    a0=(++a)++; //(b++)++;  //这里的b++返回的是一个常量的值，不能进行++操作，这样会产生编译错误，下边的d++同理,++a返回的是a变量本身，可以作为左值
    c0=++(++c);//++(d++);
    cout<<a0<<" "<<a<<endl;
     cout<<" "<<b<<endl;
      cout<<c0<<" "<<c<<endl;
       cout<<" "<<d<<endl;
       return 1;
}
    
     