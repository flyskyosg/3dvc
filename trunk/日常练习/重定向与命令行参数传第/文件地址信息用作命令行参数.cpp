#include<iostream> //�����д����ļ���Ϣ   ע�����������������������ݣ��ض��� xxx.txt yyy.txt �����Ͱ�xxx.txt �е�������Ϣ��������yyy.txt
#include<fstream>
using namespace std;

int  main(int argc,char ** argv)           //����ʱֻ��Ҫ�����ַ�������һ���������Ҫ���룬ϵͳ�Զ�����
{
	
	ifstream inf(argv[1]);                   //������±���1��2����Ϊ��һ���ַ����ǳ�����������argc�ĸ��������˳������ַ���
	ofstream ouf(argv[2]);
	if(inf&&ouf) ouf<<inf.rdbuf();            //�ú������������������ж�ȡ�ַ�
}