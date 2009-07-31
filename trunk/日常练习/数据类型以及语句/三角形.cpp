#include<iostream>   //倒三角型的输出，
#include<iomanip>
#include<string>
#define max 10
using namespace std;
int p(int i)
{
	return i>=0?i:-i;
}

void main()
{
	for(int i=1;i<=max;i++)  //利用输出流输的格式控制输出符出
	{
		cout<<setfill(' ')<<setw(i)<<" "<<setfill('M')<<setw(19-(i-1)*2)<<"M"<<endl;
	}
    

	for(i=1;i<=max;i++)   //利用string的构造函数输出实现
	{
		cout<<string(i,' ')+string(21-2*i,'M')<<endl;
	}
	
	
	for(i=max;i>=-max;i--)    //一般传统方法实现
	{
		for(int k=0;k<p(i);k++)
			cout<<" ";
		for(int z=0;z<2*(10-p(i))-1;z++)
			cout<<"M";
		cout<<endl;
	}




}