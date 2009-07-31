//异常在函数构造函数中的应用
#include<iostream>
using namespace std;
class test
{
	int * p;
public:
	test()try:p( new int (10) )   //以类的构造函数的初始化列表为异常捕获点
	{}
	catch(const std::bad_alloc & e)
	{
		cout << e.what() << endl;
	}

	void disp()
	{
		cout << *p << endl;
	}
};

int main()
{
	test x;
	x.disp();
	getchar();
}