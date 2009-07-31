#include<iostream.h>
#include<fstream.h>
#include<string.h>
class stud
{
	int cj;char name[5],num[4];
public:
	void input(char i[],int j,char k[])
	{
		strcpy(num,i);cj=j;strcpy(name,k);
	}
	void disp()
	{
		cout<<"姓名:"<<name<<endl<<"学号:"<<num<<endl<<"成绩:"<<cj<<endl;
	}
};
void main()
{
	fstream file("student.dat",ios::binary|ios::out,0);
	int  i;
a1: cout<<"请输入学生的人数:";cin>>i;
	if(i<=0) {cout<<"输入错误.";goto a1;}
	stud p,q;
	for(int j=0;j<i;j++)
	{   
		int cj;char name[5], num[4];
        cout<<"姓名:";cin>>name;cout<<endl;
		cout<<"学号:";cin>>num;cout<<endl;
		cout<<"成绩:";cin>>cj;cout<<endl;
		p.input(num,cj,name);
        file.write((char *) &p,sizeof(stud));
	}
	file.close();
	fstream ifile("student.dat",ios::binary|ios::in,0);
	for(j=0;j<i;j++)
	{
		ifile.read((char *) &q,sizeof(stud));
		q.disp();
	}
	ifile.close();
	cin>>j;
}


	
