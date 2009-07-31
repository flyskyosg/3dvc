#include<iostream>                //模版函数参数匹配 

using namespace std;

class zhong
{
	int a;
public:
	zhong()
	{}


};


//模板函数特化 
template<class T>             
T disp(T a)
{
	cout<<"调用1"<<endl;
	return a;
}

template<>
int disp(int a)
{
    return a+1;
}


//模板类特化 

template <class T>
class xiao
{
      T a;
      public:
             xiao(T x)
             { a=x;
             }
      void  disp()
      {
            cout<<a<<endl;
      } 
             
};

template<>
class xiao<int>
{
      int a;
      public:
             xiao()
             {
                   a=20;
             }
             
             void disp()
             {
                  cout<<a<<endl;
             }
};

template<>
class xiao<void *>
{
          void * p;
          public:
                 xiao()
                 {
                       p=new int;
                 }
               
};

//部分特化      未知 
template<class T>
class xiao<T *>
{
         T * p;
         public:
                xiao()
                {
                      p=new T;
                }
                
};


int main()
{
    
    
    
    xiao<int> a;
    xiao<double> b(10.0);
    xiao<void *> c;
    xiao<char> d('c');
}




          

          
            
            
































