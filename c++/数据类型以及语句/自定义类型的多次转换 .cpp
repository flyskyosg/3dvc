#include<iostream>      //自定义类型的多次转换 

using namespace std;

class xiao
{
      int a;
      public:
             xiao(int x):a(x){}
};

class da
{
      char a;
      public:
             da(xiao a)
             {}
};

void f(da a)
{}

int main()
{
    //f('c');    //先从char 到  xiao ,再从xiao 到 da; 这样的转换不存在 
    f(da('c'));  //直接生成da的临时变量  ，也是先从char 到  xiao ,再从xiao 到 da， 但是这种语法可以 
    f(xiao(10)); //这里仅仅进行了一次转换直接得到xiao的变量 
}
              
