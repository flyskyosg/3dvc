#include<iostream>   //�������͵������
#include<iomanip>
#include<string>
#define max 10
using namespace std;
int p(int i)
{
	return i>=0?i:-i;
}

void main()
{
	for(int i=1;i<=max;i++)  //�����������ĸ�ʽ�����������
	{
		cout<<setfill(' ')<<setw(i)<<" "<<setfill('M')<<setw(19-(i-1)*2)<<"M"<<endl;
	}
    

	for(i=1;i<=max;i++)   //����string�Ĺ��캯�����ʵ��
	{
		cout<<string(i,' ')+string(21-2*i,'M')<<endl;
	}
	
	
	for(i=max;i>=-max;i--)    //һ�㴫ͳ����ʵ��
	{
		for(int k=0;k<p(i);k++)
			cout<<" ";
		for(int z=0;z<2*(10-p(i))-1;z++)
			cout<<"M";
		cout<<endl;
	}




}