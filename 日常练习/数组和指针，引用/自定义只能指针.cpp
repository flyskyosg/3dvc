//����ָ��
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

	AutoPtr(const AutoPtr & autoptr)      //�������캯��
	{
		pointer = autoptr.pointer;
		num ++;
		cout << "���ÿ������캯�������ü�����1,num = " << num << endl;
		
	}

	~AutoPtr()
	{
		num--;
		cout << "�����������������ü�����һ,num = " << num <<endl;
		if(num == 0) 
		{
			cout << "���ü���Ϊ" << num << "�ͷſռ�" << endl;
			delete pointer;
		}
	}

	AutoPtr & operator = (const AutoPtr & autoptr)
	{
		pointer = autoptr.pointer;
		num++;
		cout << "=���������,���ü�����һ��num =" << num << endl;
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
		cout << "���������ɹ�" << endl;
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













		


