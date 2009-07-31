#include<iostream>
#include<string>

using namespace std;



//函数模板以及函数模板特化 
template<class t>
t max(t a, t b)
{
	return a>b?a:b;
}

//特化 

template<>
char const * max(char const * a,char const * b)
{
	return strcmp(a,b)>0?a:b;
}


///类模板以及类模板特化 

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


//特化 
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


   
                        
 
int main()
{
	//char const * a="aaaa";
	//char const * b="bbbb";
	//cout<<max(a,b);
	//cout<<max(10.0,100.0);
	
	int a=10;
	xiao<int> m;
	m.disp(a);
	xiao<double> n;
	n.disp(a);
	
	
	
	system("pause");
	return 0;
}
