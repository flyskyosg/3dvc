#include<iostream> //查每行单词的个数并且排序
#include<algorithm>//map的使用
#include<vector>
#include<fstream>
#include<sstream>
#include<map>
using namespace std;
typedef multimap<int,int> mmap;
void creatfile()
{

	ofstream inf("123.txt");
    for(int i=10;i<30;i++)
	{
		string s(i,'a');
		inf<<s+'\n';
	
	}
}


void main()
{

    mmap nums;
	//creatfile();
	ifstream inf("123.txt");int i=1 ;
	for( string s;getline(inf,s);i++)
	{
		int num=0;string t;
		
		for(istringstream sin(s);sin>>t;num++);
		cout<<"第"<<i<<"行单词的个数是:"<<num<<endl;
		if(num!=0) nums.insert(mmap::value_type(num,i));
	}
	
	for(mmap::iterator it=nums.begin();it!=nums.end();++it)
		cout<< it->first   <<" "<<it->second<<endl;

	cout<<nums.size();


}

