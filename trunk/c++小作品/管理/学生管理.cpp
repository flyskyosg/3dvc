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
		cout<<"����:"<<name<<endl<<"ѧ��:"<<num<<endl<<"�ɼ�:"<<cj<<endl;
	}
};
void main()
{
	fstream file("student.dat",ios::binary|ios::out,0);
	int  i;
a1: cout<<"������ѧ��������:";cin>>i;
	if(i<=0) {cout<<"�������.";goto a1;}
	stud p,q;
	for(int j=0;j<i;j++)
	{   
		int cj;char name[5], num[4];
        cout<<"����:";cin>>name;cout<<endl;
		cout<<"ѧ��:";cin>>num;cout<<endl;
		cout<<"�ɼ�:";cin>>cj;cout<<endl;
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


	
