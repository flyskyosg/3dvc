#include<iostream>         //��̬ת�� ��typeid���÷� 
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
    cout<<typeid(*j).name()<<endl;    //��̬���ͼ�� 
    cout<<typeid(10.0).name()<<endl;  //�������ͼ�� 
   
    dynamic_cast<b *>(j)->disp();      //dynamicר�����Զ�̬������ת�� 
    system("pause");
    return 0;
}

 
