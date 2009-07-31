#include<iostream> //，指针的转换和多引用以及未定义行为
#include<string>
//#include<iomanip>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;







void main()
{
	float d=34.5;
	int * i=(int *)(&d);      //将d的地址转换为int * 型的
	cout<<d<<" "<<&d<<endl;
	cout<<*i<<" "<<i<<endl;
	*i=100;
	cout<<*i<<endl;       
	cout<<d<<endl;            //程序中不要使用不同指针间的转换


	int a=100;
	int & const  b=a,&c=a;      //一个变量可以又多个引用,引用也可以使用const修饰符来限定，用法与指针类似，引用的内部实现还是指针

	cout<<a<<" "<<b<<endl;
	b=50;
	cout<<(b=10)<<" "<<b<<"　"<<c<<endl;         //b=10为定义行为，编译器并不把10赋给b;
	cout<<&a<<" "<<&c<<endl;       //引用与原变量的地址一样
	
     int f=(b=200)*10;             
	 cout<<b<<" "<<f<<endl;

}



