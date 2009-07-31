#include<iostream> //string 流的使用
#include<string>
//#include<iomanip>
#include<sstream>
#include<fstream>
using namespace std;
int a[10];
static int b[10];
void main()
{
  
	
      //数组的5中定义方法：
	  int  a[2];           
	  int  a0['a'];         //因为cha是intd的子集，其等价与int a[97];
	  int const n=10; int a1[n];        //这里的n相当于常量

	  int m;cin>>m;int *a2=new int[m];      //实现数组的动态定义，需要多少定义多少

	 
       cout<<::a[0]<<" "<<a[0]<<" "<<b[0]; //全局数组和静态数组如果定义后没有初始化，哪么系统自东初始化为0或‘、0’，而定义在局部作用域内的数组比如函数和类内部的数组则其值不确定
     


	  

	
	
}
