#include<iostream>                //ģ�溯������ƥ�� 

using namespace std;




class zhong
{
	int a;
public:
	zhong()
	{}


};

template<class T,class U>             
T disp(U a)
{
	cout<<"����1"<<endl;
	return a;
}

template<class U>             
U disp(U a)
{
	cout<<"����2"<<endl;
	return a;
}









int main()
{
	int i=0;
	disp(i);
	disp<double>(i);             //ͨ����ʾ˵������������������ 
	disp<double,int>(i);
	//disp<int>(i);              //����������
	//disp<zhong>(zhong());
	//disp<zhong>(i);
    system("pause"); 

	return 0;
}
