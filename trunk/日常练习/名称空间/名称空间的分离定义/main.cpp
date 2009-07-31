#include<iostream>
#include"namespace.h"

using namespace std;

int main()
{
	//using namespace stack
	stack::push('a');
	stack::push('b');
	//cout<<stack::max[0]<<stack::max[1]<<endl;
	stack::print();
	stack::pop();
	stack::pop();
	//cout<<stack::max[0]<<stack::max[1]<<endl;
    stack::print();
	return 1;
}
