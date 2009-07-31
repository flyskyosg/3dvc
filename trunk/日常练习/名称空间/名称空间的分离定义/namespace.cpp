#include"namespace.h"

namespace stack        //名称空间可以分开声明，只要他的名称匹配就可以
{
	int max[100];      //一般在名称空间的实现文件中定义他的数据成员，如果在头文件的话会产生重复定义
	int i=-1;

}

bool stack::push(char c)
{
	if(i>99) return 0;
	i++;                    //在同一个名称空间中定义的函数以及数据，他们关系就像在类中定义的一样，可以在函数中直接调用数据使用，就相当于名称空间中的全局数据，但是他们的初始化是不确定的
	max[i]=c;
	return 1;
}

bool stack::pop()         //向类一样，在外部定义时候要加域运算符
{
	if(i<0) return 0;

	max[i]=0;
	i--;
	return 1;
}
void stack::print()
{
		for(int i=0;i<2;i++	)
		{
			cout<<max[i]<<endl;
		}
}