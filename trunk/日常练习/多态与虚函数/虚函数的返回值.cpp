#include<iostream>

using namespace std;

class stu
{
      public:
             virtual stu & fn()
             {
                 cout<<"stu"<<endl;
                 return *this;
             }

            // virtual ~             
};

class gstu:public stu              
{
      public:
             gstu & fn()             //实现多态的虚函数的返回值也必须一样，否则编译不视为虚函数，但是当虚函数都分别返回自己类型的指针或者引用的时候可以有不同有不同的数据类型，既各自的指针或者 引用 
             {
                  cout<<"gstu"<<endl;
                  return * this;
             }
             
}; 

int main()
{
    stu  m;
    gstu n;
    stu & k=n;
    stu o=n;           //实现多态只能是基类的指针或者引用，不可以是基类的对象，或者使用抽象类，抽象类不可以定义对象，但是可以定义指针和引用 
    o.fn();
    n.fn();
    stu * l=& m;
    l->fn();
    system("pause");
    
    
}
 
