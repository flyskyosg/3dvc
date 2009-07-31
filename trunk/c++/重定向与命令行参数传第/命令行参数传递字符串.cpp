#include<iostream> //命令行传递参数
using namespace std;

int  main(int argc ,char ** argv)           //输入时只需要传入字符串，第一项参数不需要传入，系统自动传入
{
	for(int i=0;i<argc;i++)
         cout<<argv[i]<<" ";
	cout<<endl;
}