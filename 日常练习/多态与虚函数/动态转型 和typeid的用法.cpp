#include<iostream>         //动态转型 和typeid的用法 
#include<typeinfo>

using namespace std;

class a
{
      public:
             virtual void disp()=0;
      
};
class b:public a
{
      public:
             void disp()
             {
                  cout<<"b"<<endl; 
             }
};

int main()
{
    b i;
    a *j=&i;
    cout<<typeid(*j).name()<<endl;    //多态类型检查 
    cout<<typeid(10.0).name()<<endl;  //基本类型检查 
   
    dynamic_cast<b *>(j)->disp();      //dynamic专门用以多态的类型转换 
    system("pause");
    return 0;
}

 
