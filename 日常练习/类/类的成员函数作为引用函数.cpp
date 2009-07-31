#include<iostream>

using namespace std;
class xiao
{
	int n;
public:
	xiao (int i)
	{
		n=i;
	}
	int &f()
	{
		n+=100;
		return n;

	}
	void disp()
	{
		cout<<n<<endl;
	}
};
int main()
{
	xiao a=100;
	a.f()+=100;
	a.disp();
}
