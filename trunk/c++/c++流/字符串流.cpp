
#include<iostream>
#include<fstream>   //ifstream�Լ�ofsteam��������fstream�У�
#include<string>
#include<sstream>  //ostringstream�Լ�istringstream��������sstream�У�
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
    stringstream str(u);  //ʹ�ù��캯����ʼ����
	//stringstream str;����ʹ��Ĭ�Ϲ��캯��
	//str(u)  ��Ҳ���ԣ������ó�Ա������ʼ����;
	//stringstream����ֻ����string���͵Ķ�����Ϊ���� ������󣬸�ʽ��������
	str<<u;
	cout<<u;
    cin>>oct;
	int h;
	cin>>h;
	cout<<h;

	
	


}
