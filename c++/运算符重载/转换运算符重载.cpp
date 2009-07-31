//转换运算符
#include<iostream>
#include<string>
using namespace std;



class inter
{
	string::size_type num;
public:
	inter() : num(48){}
	operator int () const         //没有返回值 没有参数 为const 必须return num
	{
		cout <<"调用转换操作符" << endl;
		 return num;
	}
};


int main()
{
	inter minter;

	cout << char(minter) << endl;
	

	getchar();
}
