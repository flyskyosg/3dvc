
//�����������ռ䣬
#include<iostream>

using namespace std;

namespace NS
{
	class iteam_base
	{
	   public:
	};

	void disp(const iteam_base & m)
	{
		cout << "called" << endl;
	
	}

	void disp()
	{
		cout << "called1" << endl;
	}
}

void disp(int a)
	{
		cout << "called2" << endl;
	}


class sales_iteam : public NS::iteam_base
{
};

int main()
{
	using NS::disp; //������ʹ��ns�е�����disp����main�пɼ�//���������һ�еĻ����±ߵĵ�����Ȼ�����ҵ�disp������
	sales_iteam m;
	disp(m);
	disp();
	int a = 10;
	::disp(a);
	getchar();

}