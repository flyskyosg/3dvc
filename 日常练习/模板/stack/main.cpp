#include"stack.h"         //类以及函数模板以及他们特化以及模板实现的静态多态

int main()
{
	c_stack<int> m(10);
	m.push(10);
	m.push(20);
   
	c_stack<char> m0(10); //类模板特化
	m0.push('a');
    
	c_push(m0,'b');       //通过函数模板实现静态多态
	c_push(m,10);         //即实现了模板的静态多态又实现了函数模板的特化，还实现在类模板的实例上进行特化与多态
	return 0;
}

	