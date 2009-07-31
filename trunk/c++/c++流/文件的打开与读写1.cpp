#include<iostream.h>
#include<fstream.h>
#include<string.h>
struct stud              //结构体数据类型//
{
	int num;
	char name[5];
};
class base                //类对象//
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
		cout<<"打开文件失败"<<endl;
	
	};
	for(int i=0;i<2;i++)
	{
		ofile.write((char *) &b[i],sizeof(base));
	}
	ofile.write((char *) &c,sizeof(stud));
	ofile.close();                                  //在对文件进行了读或写操作后都要关闭文件，然后才能进行不同类型的操作，否则数据仅仅是存储在内存中，并没有写入文件//
	fstream ifile("000.dat",ios::binary|ios::in,0);
	for(i=0;i<2;i++)                                //文件的读写指针会随着输入的次数依次先后自动移动//
	{
		ifile.read((char *) &a[i],sizeof(base));
	}
	a[0].disp();a[1].disp();                         
     ifile.read((char *) &d,sizeof(stud));
	 cout<<d.num<<d.name<<endl;
	ifile.close();
}
