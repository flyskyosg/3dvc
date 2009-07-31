//函数对象---基于（）运算符重载
#include<iostream>

using namespace std;

template<typename T>
class Tabs
{
public:
	T operator () (T data)
	{
		return data >= 0 ? data : -data;
	}
};


int main()
{
	Tabs<int> absint;
	Tabs<double> absdouble;

	cout << absint(-10) << endl;
	cout << absdouble(-12.023) << endl;

	getchar();
}
