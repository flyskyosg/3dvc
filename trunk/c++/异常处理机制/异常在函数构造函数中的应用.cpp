//�쳣�ں������캯���е�Ӧ��
#include<iostream>
using namespace std;
class test
{
	int * p;
public:
	test()try:p( new int (10) )   //����Ĺ��캯���ĳ�ʼ���б�Ϊ�쳣�����
	{}
	catch(const std::bad_alloc & e)
	{
		cout << e.what() << endl;
	}

	void disp()
	{
		cout << *p << endl;
	}
};

int main()
{
	test x;
	x.disp();
	getchar();
}