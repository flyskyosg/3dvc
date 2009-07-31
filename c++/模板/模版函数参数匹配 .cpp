#include<iostream>                //模版函数参数匹配 

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
	cout<<"调用1"<<endl;
	return a;
}

template<class U>             
U disp(U a)
{
	cout<<"调用2"<<endl;
	return a;
}









int main()
{
	int i=0;
	disp(i);
	disp<double>(i);             //通过显示说明参数的类型来区别 
	disp<double,int>(i);
	//disp<int>(i);              //产生二义性
	//disp<zhong>(zhong());
	//disp<zhong>(i);
    system("pause"); 

	return 0;
}
