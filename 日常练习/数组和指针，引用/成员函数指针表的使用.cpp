
//成员函数指针表的使用
#include<iostream>
using namespace std;

class screen
{
public:

	typedef screen& (screen:: * facp)();
	
	static facp facarry[];

	enum num {UP,DOWN,LEFT,RIGHT};
	screen & up()
	{
		cout << "up" << endl;
		return *this;
	}

	screen & down()
	{
		cout << "down" << endl;
		return *this;
	}

	screen & left()
	{
		cout << "left" << endl;
		return *this;
	}

	screen & right()
	{
		cout << "right" << endl;
		return *this;
	}

	screen & move(num i)
	{
		return (this->*facarry[i])();
	}
};

screen::facp screen::facarry[] = {&screen::up,&screen::down,&screen::left,&screen::right};

int main()
{
	screen m;
	m.move(screen::num::LEFT);
	getchar();
}
