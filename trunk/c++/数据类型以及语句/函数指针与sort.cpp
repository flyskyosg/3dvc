#include<iostream>   //函数指针，以及sort使用
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef void (*mm)(int);  //定义mm为指向int (int) 类型函数的指针的别名，程序中通常这样使用

void fun(int a)
{
	cout<<a<<endl;
}

int bitsum(int a)
{
	int sum=0;
	for(int x=a; x;x/=10) sum+=x%10;
	return sum;
}

bool ppp(int a,int b)
{
	return bitsum(a)<bitsum(b);
}





void main()
{
	mm p=fun;              //函数指针
	p(100);
	
	void (*q)(int);q=fun;  //函数指针
	q(200);


	int b[]={60,05,13,92,49,10,5,6};
	vector<int> aa(b,b+7);
	
	sort(aa.begin(),aa.end());
	
	for(int i=0;i<aa.size();i++)
		cout<<aa[i]<<" ";
	cout<<endl;



	
	sort(aa.begin(),aa.end(),ppp);
	
	for(i=0;i<aa.size();i++)
		
		cout<<aa[i]<<" ";
	cout<<endl;

    mm & o=p;           //函数指针的引用
	o(300);

	mm u[2];            //定义函数指针的数组
	u[0]=fun;
	u[0](400);          //函数指针的使用

   



	
}

	
