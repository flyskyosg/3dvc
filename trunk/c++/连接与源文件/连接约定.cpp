#include<vc60.h>

extern "C"                          //这个c必须大写,标明下边的对象遵循这种连接约定
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
	c_out(c_disp);                 //下边的都正确，因为c_out和c_disp都具有c连接，而且vc中c与c++具有相同的连接约定
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
