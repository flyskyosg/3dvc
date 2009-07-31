#include<iostream> //向量的嵌套以及引用指针传递参数
#include<string>
//#include<iomanip>
#include<sstream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;


void input(vii & oo)  //从文件中读取数据初始化向量
{
	 ifstream inf("123.in");
     
	 oo.resize(3);
     int i=0;
	 vi * p=NULL;
	 for(string s;i<3,getline(inf,s);i++)
	 {
		 
		 int m=0;
		 for(istringstream istr(s);istr>>m;)      //这里试用了string流
		 {
			 cout<<m<<" ";
			 p=& oo[i];							  //向量也支持指针，
			 p->push_back(m);					  //可以用指针来调用向量的函数
			 	 
		 }
		 cout<<endl;
	
	 
	 }


}

void print(vii & oo)          //输出二维向量
{
	for(int i=0;i<oo.size();i++)
	{
		for(int j=0;j<oo[i].size();j++)
		
			cout<<oo[i][j]<<" ";
	cout<<endl;
	}	


	vii * p=& oo;
	cout<<p->size()<<endl;

}



bool find ( vii & oo ,int & o)              //查找符合的向量   
                                            //向量支持引用，可以使一维的也可以是二维的，
{
	for(int i=0;i<oo.size();i++)
	{
		for(int j=0;j<oo[i].size();j++)     //oo.[i].size()每层都可以看做是一个向量
		
		{
			
			
			if(oo[i][j]==-1) { o=i;cout<<"ok"<<endl;return 1;} // 多维向量的嵌套可以使用双下表操作

			
		}

	}
	
}






void main()
{
	/*string s(3,'1');       //这里用来初始化文件
	ofstream of("123.in");
	for(int i=1;i<=3;i++)
	{
		of<<s<<'\n';
		
	}
    of.close();*/
	 
	
	


     vii oo;
	 input(oo);
	 //cout<<oo[2][2]<<endl;
     print(oo);
     int o=0;
	 find(oo,o);
	 for(int i=0;i<oo[o].size();i++)
		 cout<<oo[o][i];
	 cout<<endl;

	 cout<<"试验:"<<endl;      
	 vii pp=oo;            //向量的值传递
	 print(pp);
	
	
	
	

   
}



