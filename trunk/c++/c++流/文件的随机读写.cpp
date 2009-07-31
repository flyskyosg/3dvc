#include<iostream.h>
#include<fstream.h>
#include<string.h>

class base                                       //类对象//
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
	if(!ofile)                                   //检验文件是否打开成功//
	{
		cout<<"打开文件失败"<<endl;
	
	};
	for(int i=0;i<2;i++)
	{
		ofile.write((char *) &b[i],sizeof(base));
	}
	
	ofile.close();                               //在对文件进行了读或写操作后都要关闭文件，然后才能进行不同类型的操作.否则数据仅仅是存储在内存中，并没有写入文件//
	ifstream ifile("000.dat",ios::binary,0);
	for(i=0;i<2;i++)                             //文件的读写指针会随着输入的次数依次先后自动移动//
	{    ifile.seekg(0,ios::beg);                //********每次循环都把读指针定位流的开头位置***********//
		ifile.read((char *) &a[i],sizeof(base)); //上一行的程序每次都把读指针定位在流的开头，导致每次的输出结果都一样//
	}	
	a[0].disp();
	a[1].disp();
	ifile.close();
}
