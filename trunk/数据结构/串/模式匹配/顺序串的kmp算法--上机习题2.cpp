#include<iostream>
#include<string.h>
using namespace std;
#define maxlen 255
typedef char SString[maxlen+1];
int index_kmp(SString S,SString T,int pos,int next[]) //1<=pos<=strlen(s);
{
	int  i=pos,j=1,n=0;
	while(i<=S[0]-0x30 && j<=T[0]-0x30)
	{
		cout<<S[i]<<T[j]<<++n<<endl;
	    if(j==0||S[i]==T[j])
		{
			i++;j++;
		}
		else
		{
			j=next[j];
		}
	}
	if(j>T[0]-0x30)
	{
	
		return i-T[0]+0x30;
	}
	else return 0;
}

void getnext(char T[],int next[])
{
	int i=1,j=0, n=0;next[1]=0;
	while(i<T[0]-0x30)
	{
		if(j==0 ||T[i]==T[j])                 
		{
			i++;j++;next[i]=j;
		}
		else
		{
			j=next[j];
		}
	}
}



void getnextval(char T[],int nextval[])
{
    int i=1;nextval[1]=0;int j=0,n=0;
	while(i<T[0]-0x30)
	{
		if(j==0||T[i]==T[j])
		{
			i++;j++;
			if(T[i]!=T[j]) nextval[i]=j;
			else nextval[i]=nextval[j];
		}
		else
		{
			j=nextval[j];
		}
	}
}




void main()
{
	SString S,T;int pos,next[maxlen];char a;
	do
	{
		cout<<"input master str:输入格式:长度,相应数量的字符:";
		cin>>S;
		cout<<"input master str:输入格式:长度,相应数量的字符:";
		cin>>T;
		cout<<S<<"   "<<T<<endl;
		for(int i=0;i<=T[0]-0x30;i++)
		{
			cout<<"next["<<i<<"]="<<next[i]<<"  ";
		}
		cout<<endl;
		getnext(T,next);
		for( i=1;i<=T[0]-0x30;i++)
		{
			cout<<"\nnext["<<i<<"]="<<next[i];
		}
		cout<<"\ninput pos=";
		cin>>pos;cout<<endl;
		cout<<index_kmp(S,T,pos,next)<<endl;
	    cout<<"继续进行修正匹配的吗?是,请按回车"<<endl;
		fflush(stdin);
		cin>>a;
		if(a=='\xA')
		{
			getnextval(T,next);
			for(i=1;i<=T[0]-0x30;i++)
				cout<<"\nnextval["<<i<<"]"<<"="<<next[i];
			cout<<"\ninput pos=";
			cin>>pos;cout<<endl;
            cout<<index_kmp(S,T,pos,next)<<endl;
		}
		cout<<"继续吗?是,按回车!"<<endl;
		fflush(stdin);
		cin>>a;
	}while(a=='\xA');

}













































































