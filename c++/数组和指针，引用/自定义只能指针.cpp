//智能指针
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class AutoPtr
{
	
public:
	T * pointer;
	static int num;
	AutoPtr(T * p) : pointer(p)
	{
		num = 1;
	}

	AutoPtr(const AutoPtr & autoptr)      //拷贝构造函数
	{
		pointer = autoptr.pointer;
		num ++;
		cout << "调用拷贝构造函数，引用计数加1,num = " << num << endl;
		
	}

	~AutoPtr()
	{
		num--;
		cout << "调用析构函数，引用计数减一,num = " << num <<endl;
		if(num == 0) 
		{
			cout << "引用计数为" << num << "释放空间" << endl;
			delete pointer;
		}
	}

	AutoPtr & operator = (const AutoPtr & autoptr)
	{
		pointer = autoptr.pointer;
		num++;
		cout << "=运算符重载,引用计数加一，num =" << num << endl;
	}
};

template<class T>
int AutoPtr<T>::num = 0;

class test
{
	AutoPtr<int> intptr;
public:
	test(int * p) :intptr(p)
	{
		cout << "构造测试类成功" << endl;
	}

	void disp()
	{
		cout << "data = " << *intptr.pointer << endl;
	}
};

void main()
{
	int * p = new int(10);
	{
		test mtest(p);
		{
			test ntest(mtest);
		}
		mtest.disp();
	}
	getchar();
}













		


