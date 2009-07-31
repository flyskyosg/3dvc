#include<iostream> //位操作
#include<string>
//#include<iomanip>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;







void main()
{

   
	int a=2,b=2;
	cout<<(a<<1)<<" "<<a<<endl; //单纯进行移位操作符运算得到的仅仅是实体元算后的结果，而并不改变变量本身
	cout<<(a<<=1)<<" "<<a<<endl;//在输出流中变量的值是一次性读入的，在读入之后不会发生变化，即使其他的任何的表达式改了他的值，也仅仅在下次才重新读入流中
	cout<<(b<<=1)<<" ";cout<<b<<endl;//与上边的a形成对比，这里的b是在改变后重新读入的。
	a<<=1;cout<<a<<endl;//与赋值操作符进行混合运算后才改变了变量本身的值，通常移位操作符长于赋值操作符混合使用	

}



