
#include<iostream>              //模板类的有缘函数 

using namespace std; 

template <class T>
class xiao
{
      T a;
      public:
		  xiao(T x);
            
      void  disp();                   
     
      template<class U>
      friend void disp1(U  x);          
      
      
             
};
template<class U>
void disp1(U x);

 template<class T>
 xiao<T>::xiao(T x)     
 {
          a=x;
 }

   template <class T>
  void xiao<T>:: disp()
  {
            cout<<a<<endl;
  } 
 template<class U>
 void disp1(U  x)
{
             cout <<x.a<<endl;
}

