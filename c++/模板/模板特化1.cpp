#include<iostream>                //ģ�溯������ƥ�� 

using namespace std;

class zhong
{
	int a;
public:
	zhong()
	{}


};


//ģ�庯���ػ� 
template<class T>             
T disp(T a)
{
	cout<<"����1"<<endl;
	return a;
}

template<>
int disp(int a)
{
    return a+1;
}


//ģ�����ػ� 

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

//�����ػ�      δ֪ 
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




          

          
            
            
































