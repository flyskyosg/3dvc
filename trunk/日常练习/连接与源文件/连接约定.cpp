#include<vc60.h>

extern "C"                          //���c�����д,�����±ߵĶ�����ѭ��������Լ��
{
	typedef void(*cft)(int ,char);
	void  c_disp(int ,char);
	void  c_out(cft uu);
}


typedef void(*ft)(int ,char);

void  disp(int ,char);
void  out(ft uu);



void main()
{
	c_out(c_disp);                 //�±ߵĶ���ȷ����Ϊc_out��c_disp������c���ӣ�����vc��c��c++������ͬ������Լ��
	c_out(disp);
	
	out(c_disp);
	out(disp);
}

void c_disp(int a,char b)
{
}

void disp(int a,char b)
{
}

void c_out(cft uu)
{
}

void out(ft uu)
{
}
