#include<iostream.h>
#include<fstream.h>
#include<string.h>
struct stud              //�ṹ����������//
{
	int num;
	char name[5];
};
class base                //�����//
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
    struct stud c;c.num=100;strcpy(c.name,"xiao");stud d;
	fstream  ofile;base a[2],b[2]={base(10,'A'),base(20,'B')};
	ofile.open("000.dat",ios::binary|ios::out,0);
	if(!ofile)
	{
		cout<<"���ļ�ʧ��"<<endl;
	
	};
	for(int i=0;i<2;i++)
	{
		ofile.write((char *) &b[i],sizeof(base));
	}
	ofile.write((char *) &c,sizeof(stud));
	ofile.close();                                  //�ڶ��ļ������˶���д������Ҫ�ر��ļ���Ȼ����ܽ��в�ͬ���͵Ĳ������������ݽ����Ǵ洢���ڴ��У���û��д���ļ�//
	fstream ifile("000.dat",ios::binary|ios::in,0);
	for(i=0;i<2;i++)                                //�ļ��Ķ�дָ�����������Ĵ��������Ⱥ��Զ��ƶ�//
	{
		ifile.read((char *) &a[i],sizeof(base));
	}
	a[0].disp();a[1].disp();                         
     ifile.read((char *) &d,sizeof(stud));
	 cout<<d.num<<d.name<<endl;
	ifile.close();
}
