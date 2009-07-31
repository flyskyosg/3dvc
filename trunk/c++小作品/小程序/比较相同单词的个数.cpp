#include<iostream.h>
#include<string.h>
class world
{
 static  char name1[11], name2[11];
public:	
	world(char *p,char *q)
		{
			strcpy(name1,p);strcpy(name2,q);
		}
static void worlds()
{
	
	for(int i=0,j=0;name1[i]!='\0'&& name2[i]!='\0';i++)
	{
		 if(name1[i]==name2[i]) {cout<<name1[i]; j++;};		               
	}
	cout<<endl;cout<<"共有"<<j--<<"个相同的单词"<<endl;
}
};
char world::name1[11]={"\0\0\0\0\0\0\0\0\0\0"};char world:: name2[11]={"\0\0\0\0\0\0\0\0\0\0"};
void main()
{
	char *p1=new char, *p2=new char;
	cout<<"输入比较的两个单词"<<" ";
	cin>>p1>>p2;
	world s(p1,p2);
	s.worlds();
}



			
