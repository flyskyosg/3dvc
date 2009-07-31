#include<iostream>            //->重载  // 必须重载为成员函数

using namespace std;



struct  s
{
       string name;
       int num;
       s(string s,int a):name(s),num(a)
       {}
};






class  xiao
{
    
    int a;
    s b;
    public:
    xiao(int x,string s,int y):a(x),b( s,y)
    {}
    
    s * operator ->();
};



s* xiao:: operator ->()
{
          return &(this->b);
}
          
          


int main()
{
    xiao a(10,"hello",20);
    
    cout<<a->name<<endl;  //->运算符重载 
    
    system("pause");
    return  0;
}
    
    
    
    
    
       
   
