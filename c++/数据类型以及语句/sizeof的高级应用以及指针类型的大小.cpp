#include<iostream>     //sizeof 的高级应用以及指针类型的大小

using namespace std;

int main()
{


	double s=10.20,* p=& s;
	int n=10,* q=& n;
	char  w,* u=& w;
	void * e=p;
	cout<<sizeof(s)<<"=="<<sizeof(double)<<endl;
    cout<<sizeof(int)<<" "<<sizeof(p)<<" "<<sizeof(q)<<" "<<sizeof(u)<<" "<<sizeof(e)<<endl;
       cout<<sizeof(wchar_t)<<endl;  //2个字节
	cout<<*(double *)e<<" "<<*p<<endl;
	 
	//在vc6.0中，指针类型的数据所占用的空间大小与int型数据的大小一致，空指针可以指向任何的类型，但是在对空指针进行间访的时候要
	//进行类型转换
	
	
	
	
	
	
	
	return 0;





}