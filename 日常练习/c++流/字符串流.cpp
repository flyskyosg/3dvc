
#include<iostream>
#include<fstream>   //ifstream以及ofsteam均包含在fstream中，
#include<string>
#include<sstream>  //ostringstream以及istringstream均包含在sstream中，
using namespace std;

struct x
{
	int a;
	char b;
	//string s;
	char s[5];
};

void main()
{
	struct x o={10,'a',"1234"};
//	o.a=10;
//	o.b='a';
//	strcpy(o.s,"1234");
	//o.a=10;
	//o.b='a';
	struct x y;
	ofstream pp("00.dat",ios::out|ios::binary);
	pp.write((char *) & o,sizeof(x));
	pp.close();
	ifstream qq("00.dat",ios::in);
	qq.read((char *) & y,sizeof(x));
	qq.close();
	string u;
	cout<<y.a<<" "<<y.b<<" ";
    stringstream str(u);  //使用构造函数初始化，
	//stringstream str;或者使用默认构造函数
	//str(u)  ，也可以，这里用成员函数初始化，;
	//stringstream对象只接受string类型的对象作为输入 输出对象，格式必须如上
	str<<u;
	cout<<u;
    cin>>oct;
	int h;
	cin>>h;
	cout<<h;

	
	


}
