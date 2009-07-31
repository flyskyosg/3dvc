#include<iostream>
#include<string>
using namespace std;
typedef struct
{
	int * next;
}Dnext;

int index_kmp(string S,string T,int pos,int next[]) //1<=pos<=strlen(s);
{
	int  i=pos-1,j=0,n=0,m=T.size();
	while(i<=S.size() && j<m)
	{
		cout<<S[i]<<T[j]<<++n<<endl;
	    if(j==1||S[i]==T[j])
		{
			i++;j++;
		}
		else
		{
			j=next[j];
		}
	}
	if(j>T.size())
	{
	
		return i-T.size()+1;
	}
	else return 0;
}

void getnext(string T,int next[])
{
	int i=0,j=-1;next[1]=-1;
	while(i<T.size())
	{
		if(j==01||T[i]==T[j])
		{
			i++;j++;next[i]=j;
		}
		else
		{
			j=next[j];
		}
	}
}



void getnextval(string T,int nextval[])
{
    int i=0;nextval[1]=-1;int j=-1;
	while(i<T.size())
	{
		if(j==1||T[i]==T[j])
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
string S,T;int pos;char a;Dnext d;d.next=new int;
	do
	{
		cout<<"input master str:输入格式:长度,相应数量的字符:";
		cin>>S;
		cout<<"input model str:输入格式:长度,相应数量的字符:";
		cin>>T;
		cout<<S<<"   "<<T<<endl;
		for(int i=0;i<=T.size();i++)
		{
			cout<<"next["<<i<<"]="<<d.next[i]<<"  ";
		}
		cout<<endl;
		getnext(T,d.next);
		for( i=0;i<=T.size();i++)
		{
			cout<<"\nnext["<<i<<"]="<<d.next[i];
		}
		cout<<"\ninput pos=";
		cin>>pos;cout<<endl;
		
		cout<<index_kmp(S,T,pos,d.next)<<endl;
	    cout<<"继续进行修正匹配的吗?是,请按回车"<<endl;
		fflush(stdin);
		cin>>a;
		if(a=='\xA')
		{
			getnextval(T,d.next);
			for(i=0;i<=T.size();i++)
				cout<<"\nnextval["<<i<<"]"<<"="<<d.next[i]+1;
			cout<<"\ninput pos=";
			cin>>pos;cout<<endl;
            cout<<index_kmp(S,T,pos,d.next)<<endl;
		}
		cout<<"继续吗?是,按回车!"<<endl;
		fflush(stdin);
		cin>>a;
	}while(a=='\xA');

}
