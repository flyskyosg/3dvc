#include<iostream>

using namespace std;

class xiao
{
      
      int const t;
      int & a;
        
      public:
             static int m;
             xiao(int x,int & b):t(x), a(b)
             {cout<<"ok"<<endl;}
             
      void disp()
      {
           cout<<"t="<<t<<"a="<<a<<endl;
      }
};
 int xiao:: m=100; 
 
 class da :public xiao
 {
       int p;
       xiao m;
 public: 
         da(int x,int & b,int y):xiao(x,b),m(x,b),p(x)
         {
         }
         
         void  disp()
         {
               cout<<"p="<<p<<" "<<endl;
               xiao::disp();
               m.disp();
         }
 };
 
 
 int main()
 {
     int n=20;
     da o(10,n,20);
     o.disp();
     system("pause");
 }
 
 
 
               
         
            
               
               
               
                
                
                
                
                
         



