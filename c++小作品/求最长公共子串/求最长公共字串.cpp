#include<iostream.h>
#include<string.h>
void bijiao(char *p,char *q)
{
	char r[11];
	for(int i=0;i<=10;i++)
		r[i]='\0';
 
	for( i=0;i<=10;i++)
	{
		if(p[i]==q[i]) {r[i]=p[i];};
	}

	cout<<r<<" "<<endl<<"共"<<strlen(r)<<"个"<<endl;
	
}
void main()
{
	char *p=new char[11],*q=new char[11];
	cout<<"请输入两个字符:"<<endl;;cin>>p;cin>>q;
	bijiao(p,q);
	delete [11] p;delete[11] q;
}



	












						

				
