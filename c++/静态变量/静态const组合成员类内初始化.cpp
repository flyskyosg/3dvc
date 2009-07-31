//静态const组合成员类内初始化
#include"vector"
#include"deque"

using namespace std;

class A
{

      //只有int类型的成员才可以
	static int const a = 10;
	
	enum color{red,blue};

	static const color  b = red;

	static const char c = 'c';
};

int main()
{
   
	////////
   
    return 0;
}