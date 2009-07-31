#include<iostream.h>//括号运算符重载



class quad
{
public:quad(int a,int b,int c)
	   {
		   a_=a;b_=b;c_=c;
	   }
	   double operator ()(double x)const  // 必须重载为成员函数
	   {
		   return ((a_*x+b_)*x+c_);
	   }
private:
	int a_,b_,c_;
 };

void main()
{
	
	quad m(1,2,3);
	cout<<m(3);
}
