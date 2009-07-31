#ifndef NAMESPACE_HEADER
#define NAMESPACE_HEADER

#include<iostream>
using namespace std;

namespace stack
{
	bool push(char );         //在名称空间的头文件中一般声明他的界面--函数，而在他的实现文件中定义他的数据
	bool pop();
	void print(); 
    

	
}

#endif