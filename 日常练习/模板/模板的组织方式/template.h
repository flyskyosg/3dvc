#include<iostream>
#include<string>

using namespace std;



//����ģ���Լ�����ģ���ػ� 
template<class t>
t max(t a, t b)
{
	return a>b?a:b;
}

//�ػ� 

template<>
char const * max(char const * a,char const * b)
{
	return strcmp(a,b)>0?a:b;
}


///��ģ���Լ���ģ���ػ� 

template<typename T>
class xiao
{
      T * n;
      public:
             xiao()
             {
                   n=new T ;
             }
             void disp(T  q);
             
             
};

template<typename T>
void xiao<T>::disp(T  q)
{
cout<<"success"<<endl;
}


//�ػ� 
template<>
class xiao<double>
{
      double * n;
      public:
             xiao()
             {
                   n=new double;
             }
             void disp(double q);
};

void xiao<double>:: disp(double q)
{
     cout<<"success full"<<endl; 
}


   
                        
