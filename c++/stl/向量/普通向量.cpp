#include<iostream> //vector的使用
#include<string>
//#include<iomanip>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;


void main()
{
	vector<char> s(10,97);
	vector<char> s1(s);
    vector<char> s2(s.begin(),s.end());
	vector<char> s3(10);     
	cout<<s.capacity()<<endl;
	vector<char>::iterator it;     //一代起


	it=s1.begin();
	
	for(int i=0;i<s1.capacity();i++)
	   cout<<s1[i]<<*it++<<endl;
	s1.push_back('n');
	it=s1.end()-1;
	cout<<*it;
	



  
	
      

	  

	
	
}
