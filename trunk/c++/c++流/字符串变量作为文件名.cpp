#include<iostream>         //string ���͵ı�����Ϊ�ļ���


#include<fstream>
#include<string>
using namespace std;



int main()
{
  

	string s;
	s="abc.txt"; string s1="abc";
	ofstream ouf(s.c_str());
	ouf<<s;
	ifstream inf(s1.c_str());
	inf>>s;
	cout<<s<<endl;
	return 0;
    
}