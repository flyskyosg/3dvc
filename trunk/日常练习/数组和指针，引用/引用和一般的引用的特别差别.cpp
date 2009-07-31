#include<iostream>         //常引用和一般的引用的特别差别

using namespace std;

void f0(const int a)
{
	cout<<0<<endl;
}

void f1(int & a)
{
	cout<<1<<endl;
}


int main()
{
	int a=10;double b=20.0;

	f0(a);f0(b);f0(10);f0(10.0);     //当函数的参数是常引用的时候，前边的这些都对

	f1(a);                           //当不是常引用的时候，只能精确匹配，只能是该类型的变量
	//f1(b);                         //下边的这三个都是错的
	//f1(10);
	//f1(10.0);

	return 0;
}
