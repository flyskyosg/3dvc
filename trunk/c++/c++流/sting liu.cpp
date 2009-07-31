#include<iostream> //string 流的使用
#include<string>
//#include<iomanip>
#include<sstream>
#include<fstream>
using namespace std;
void main()
{
  	//string 流用来在使用string串读取一行字符的时候，从string字串中一次读取各个字符串，中间默认以空格为间隔符号，
	
	
	

	ifstream inf("aaa.txt");

	for(string s;getline(inf,s);)     
	{
		cout<<s<<endl;long int m=0,sum=0;

		for(istringstream istr(s);istr>>m;)  //要在将文件读入string流以后在将istringstream与string 尽行绑定
			  sum+=m;
		cout<<sum<<endl;
	
	
	}

    inf.close();
	
	
}
