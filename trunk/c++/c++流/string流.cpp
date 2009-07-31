#include<iostream> //string Á÷
#include<string>
#include<iomanip>
#include<sstream>
using namespace std;
void main()
{
	string s="wo shi 100 c";
	istringstream inf(s);
	string s1,s2;
	int a;
	char c;
	inf>>s1>>s2>>a>>c;
	cout<<s1<<s2<<a<<c;
    cout<<endl;
	
}
