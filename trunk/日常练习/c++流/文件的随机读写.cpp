#include<iostream.h>
#include<fstream.h>
#include<string.h>

class base                                       //�����//
{
	int a;char b;
public:
	base(){}
	base(int i,char j)
	{
		a=i;b=j;
	}
	void disp()
	{
		cout<<"a="<<a<<endl<<"b="<<b<<endl;
	}
};
void  main()
{
   	ofstream  ofile;base a[2],b[2]={base(10,'A'),base(20,'B')};
	ofile.open("000.dat",ios::binary,0);
	if(!ofile)                                   //�����ļ��Ƿ�򿪳ɹ�//
	{
		cout<<"���ļ�ʧ��"<<endl;
	
	};
	for(int i=0;i<2;i++)
	{
		ofile.write((char *) &b[i],sizeof(base));
	}
	
	ofile.close();                               //�ڶ��ļ������˶���д������Ҫ�ر��ļ���Ȼ����ܽ��в�ͬ���͵Ĳ���.�������ݽ����Ǵ洢���ڴ��У���û��д���ļ�//
	ifstream ifile("000.dat",ios::binary,0);
	for(i=0;i<2;i++)                             //�ļ��Ķ�дָ�����������Ĵ��������Ⱥ��Զ��ƶ�//
	{    ifile.seekg(0,ios::beg);                //********ÿ��ѭ�����Ѷ�ָ�붨λ���Ŀ�ͷλ��***********//
		ifile.read((char *) &a[i],sizeof(base)); //��һ�еĳ���ÿ�ζ��Ѷ�ָ�붨λ�����Ŀ�ͷ������ÿ�ε���������һ��//
	}	
	a[0].disp();
	a[1].disp();
	ifile.close();
}
