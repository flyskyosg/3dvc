#include<iostream>
#include<vector>

using namespace std;

void print(int  a,int =100);  //函数的无名参数




void print(int a,double b )
{
	cout<<a<<" "<<b<<endl;
	cout<<2<<endl;
}


void print(char a,double b )
{
	cout<<a<<" "<<b<<endl;
	cout<<3<<endl;
}


void main()
{
	print(97,10); //虽然又无名参数，但是在实参进行传递的时候必须给出对应类型的实参
	print(97,10.0);
	print(char(97),10.0);

}


void print(int a,int  )  //函数的无名参数，
{
	cout<<a<<" "<<endl;
	cout<<1<<endl;
}