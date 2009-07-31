#include<iostream>            //字符数组与char * 
#include<string>

using namespace std;


const char * disp()
{
	return "hello\n";
}

int main()
{
    
    
   
    int c=10;
    int & b=c;  //一般引用 
    
    const int & a=1;  //常引用可以用字面常量来赋值 ,也可以用常变量来赋值，同时也更可以用个普通变量来初始化 
    const int & d=c;
    const int & e=b; 
   
    cout<<a<<" "<<b<<" "<<c<<endl;
    system("pause");
    
    


}