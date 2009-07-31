
//重载与命名空间，
#include<iostream>

using namespace std;

namespace NS
{
	class iteam_base
	{
	   public:
	};

	void disp(const iteam_base & m)
	{
		cout << "called" << endl;
	
	}

	void disp()
	{
		cout << "called1" << endl;
	}
}

void disp(int a)
	{
		cout << "called2" << endl;
	}


class sales_iteam : public NS::iteam_base
{
};

int main()
{
	using NS::disp; //该生明使得ns中的两个disp都在main中可见//如果不加这一行的话，下边的调用仍然可以找到disp的重载
	sales_iteam m;
	disp(m);
	disp();
	int a = 10;
	::disp(a);
	getchar();

}