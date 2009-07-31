#include<iostream.h>
#include<string.h>
void main()
{
	int *a=new int[4],b[4];
	char *c=new char[5],d[5],e[5]={"aaaa"};
    for(int i=0;i<=4;i++)
	{
		a[i]=5;b[i]=6;              
	}	
	cin>>c;cin>>d;
	cout<<c<<endl;
	cout<<d<<endl;
	cout<<e<<endl;
	strcpy(c,"vvvv");strcpy(d,"vvvv");strcpy(e,"vvvv");       //使用strcpy//
	cout<<c<<endl<<d<<endl<<e<<endl;

}
//在c++中，用cout和cin来输出或输入数组时,要想实现整体的输入与输出,只能是字符数组//
//整形数组不可以以cout<<a;或cin>>a;这样的形式来整体赋值与输出//
//如果是一般的字符数组，只能在定义的时候用字符串的形式来赋值，在其他的地方不可以使用字符串，只可以用strcpy来整体赋值，可以使用cout<<和cin>>来整体输入和输出//
//如果是动态分配空间的字符数组，可用cin>>或cout来赋值或输出；也可用strcpy来赋值，strcpy在使用时，第一个必须是数组//
//所有的数组都可以在程序的任何地方用cout和cin单个赋值或输出//
