#include<iostream> //string ����ʹ��
#include<string>
//#include<iomanip>
#include<sstream>
#include<fstream>
using namespace std;
void main()
{
  	//string ��������ʹ��string����ȡһ���ַ���ʱ�򣬴�string�ִ���һ�ζ�ȡ�����ַ������м�Ĭ���Կո�Ϊ������ţ�
	
	
	

	ifstream inf("aaa.txt");

	for(string s;getline(inf,s);)     
	{
		cout<<s<<endl;long int m=0,sum=0;

		for(istringstream istr(s);istr>>m;)  //Ҫ�ڽ��ļ�����string���Ժ��ڽ�istringstream��string ���а�
			  sum+=m;
		cout<<sum<<endl;
	
	
	}

    inf.close();
	
	
}
