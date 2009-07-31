#include<iostream>     //sizeof的高级应用以及指针类型的大小

using namespace std;



enum color{red=0,bland,back};

int main()
{
	 color s=red;
	 color s1=color(2); 
	 //color s2=10;//错误
	  //s=10; //错误

	 cout<<s<<s1<<endl;


	
	
	
	return 0;
}





