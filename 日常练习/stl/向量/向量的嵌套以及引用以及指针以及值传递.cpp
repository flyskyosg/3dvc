#include<iostream> //������Ƕ���Լ�����ָ�봫�ݲ���
#include<string>
//#include<iomanip>
#include<sstream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;


void input(vii & oo)  //���ļ��ж�ȡ���ݳ�ʼ������
{
	 ifstream inf("123.in");
     
	 oo.resize(3);
     int i=0;
	 vi * p=NULL;
	 for(string s;i<3,getline(inf,s);i++)
	 {
		 
		 int m=0;
		 for(istringstream istr(s);istr>>m;)      //����������string��
		 {
			 cout<<m<<" ";
			 p=& oo[i];							  //����Ҳ֧��ָ�룬
			 p->push_back(m);					  //������ָ�������������ĺ���
			 	 
		 }
		 cout<<endl;
	
	 
	 }


}

void print(vii & oo)          //�����ά����
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



bool find ( vii & oo ,int & o)              //���ҷ��ϵ�����   
                                            //����֧�����ã�����ʹһά��Ҳ�����Ƕ�ά�ģ�
{
	for(int i=0;i<oo.size();i++)
	{
		for(int j=0;j<oo[i].size();j++)     //oo.[i].size()ÿ�㶼���Կ�����һ������
		
		{
			
			
			if(oo[i][j]==-1) { o=i;cout<<"ok"<<endl;return 1;} // ��ά������Ƕ�׿���ʹ��˫�±����

			
		}

	}
	
}






void main()
{
	/*string s(3,'1');       //����������ʼ���ļ�
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

	 cout<<"����:"<<endl;      
	 vii pp=oo;            //������ֵ����
	 print(pp);
	
	
	
	

   
}



