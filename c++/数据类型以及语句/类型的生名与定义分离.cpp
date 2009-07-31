#include<iostream>            //类型的生命与定义分离 
#include<string>

using namespace std;


struct node; 


int main()
{
    
    
    //node a0 ;                //这里将导致错误，虽然已经声明了node，但是在没有定义 之前是不能定义对象的，但是可以定义该类型的指针，或者函数返回类型以及参数类型，这样的类型包括类，等自定义类型 
    node * b0;
    
    
   

    


}

struct node
{
       int a;
       char c;
};
