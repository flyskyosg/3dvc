#include<iostream> //位操作
#include<string>
//#include<iomanip>
#include<sstream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;

double cheng(double n)
{
	
	for(double sum=1.0, i=1.0;i<=n;sum*=i,i++);
	
	return sum;
}





void main()
{

   

    cout<<cheng(5.0)<<endl;
	cout<<cheng(18.0)/(cheng(13.0)*cheng(5.0))<<endl;

	double d1=123456789.9*9,d2=1111111109.1;
	if(abs(d1-d2)<1e-5) cout<<"same"<<endl;  //邻域比较技术来判断两个浮点数是否相等
	cout<<(d1-d2)<<endl;
   
	 

	 double p=123456789.9;      //精度丢失

	 int o;float l;
	 o=l=p;
	 cout<<o<<endl<<l<<endl<<p<<endl;     


	 int  g=1000000000,j=2000000000;
	 int c0=(double(g)+j)/2;         //如果不转换位double中间结果溢出，计算后没有溢出，可赋值给int型变量
	 
	 cout<<c0<<endl; 
}



