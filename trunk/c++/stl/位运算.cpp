#include<iostream> //λ����
#include<string>
//#include<iomanip>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;







void main()
{

   
	int a=2,b=2;
	cout<<(a<<1)<<" "<<a<<endl; //����������λ����������õ��Ľ�����ʵ��Ԫ���Ľ�����������ı��������
	cout<<(a<<=1)<<" "<<a<<endl;//��������б�����ֵ��һ���Զ���ģ��ڶ���֮�󲻻ᷢ���仯����ʹ�������κεı��ʽ��������ֵ��Ҳ�������´β����¶�������
	cout<<(b<<=1)<<" ";cout<<b<<endl;//���ϱߵ�a�γɶԱȣ������b���ڸı�����¶���ġ�
	a<<=1;cout<<a<<endl;//�븳ֵ���������л�������Ÿı��˱��������ֵ��ͨ����λ���������ڸ�ֵ���������ʹ��	

}



