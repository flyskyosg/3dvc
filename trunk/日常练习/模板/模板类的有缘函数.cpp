
#include<iostream>              //ģ�������Ե���� 

using namespace std; 

template <class T>
class xiao
{
      T a;
      public:
             xiao(T x)     
             {
                     a=x;
             }
      void  disp()
      {
            cout<<a<<endl;
      } 
      template<class U>
      friend void disp1(U & x);        //ģ�������Ե���� 
     
      
      
      
      
      
      
      
             
};
template<class U>
 void disp1(U & x)
{
             cout <<x.a<<endl;
}

int main()
{
    xiao<int> a(10);
    a.disp();
    disp1<xiao<int> >(a);
    system("pause");
    return 0;
}














      
