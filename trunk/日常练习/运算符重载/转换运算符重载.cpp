//ת�������
#include<iostream>
#include<string>
using namespace std;



class inter
{
	string::size_type num;
public:
	inter() : num(48){}
	operator int () const         //û�з���ֵ û�в��� Ϊconst ����return num
	{
		cout <<"����ת��������" << endl;
		 return num;
	}
};


int main()
{
	inter minter;

	cout << char(minter) << endl;
	

	getchar();
}
