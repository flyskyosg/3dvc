#include<iostream>            //字符数组与char * 
#include<string>

using namespace std;


const char * disp()
{
	return "hello\n";
}

int main()
{
	cout<<disp();				//将char * 作为数值返回
   
	char a[]="he"  "llo";       //支持分离定义
	char b[]="wo"
		     "rld";
	cout<<a<<b<<endl;	      

	char * p="hello";           //char * 的初始化使用
		   p="world";    
	       p=a;
	cout<<p<<endl;

                                //可以用字符数组来初始化char * ,反之不成立
	cout<<p<<" "<<*p<<" "<<p[0]<<" "<<++p<<endl; //char * 这里既可以表示整个数组也可以表示指向单个字符的指针 
    cout<<p<<" "<<*p<<" "<<p[0]<<" "<<++p<<endl;
	cout<<strlen(a)<<sizeof(p)<<endl;
    system("pause"); 


    return 0;


}
