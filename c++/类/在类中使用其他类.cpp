#include<iostream>

using namespace std;

class xiao
{
     
      int const t;
      int & a;
      public: static int m;
             xiao(int x,int & b):t(x), a(b)
             {cout<<"ok";}
             
      void disp()
      {
           cout<<"t="<<t<<"a="<<a<<endl;
      }
};
 int xiao:: m=100; 
 


int main()
{
    int n=100;
    xiao m(10,n);
    m.disp();
    cout<<xiao::m<<endl;
    system("pause");
    
}
