// 模版的成员作为模版
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class test
{
	T data;
public:
	test():data(0)
	{}
     
	template<typename T1>
	void disp(T1 t1)
	{
		
		cout << "t1 =" << t1 << endl << "data =" << data << endl;
	}
};

int main()
{
	test<int> p;
	p.disp<string>("ssss");
	getchar();
}
