
#include<iostream>              //模板类的有缘函数 

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
      friend void disp1(U & x);        //模板类的有缘函数 
     
      
      
      
      
      
      
      
             
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














      
