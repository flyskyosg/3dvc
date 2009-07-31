#include<iostream.h>
#define maxlen 10
typedef char sstring[maxlen];
typedef struct sqstring
{
	char data[10];
	int len;
}sqtr;

void initsq(sqtr & l)//初始化串
{
	for(int i=0;i<maxlen;i++)
		l.data[i]='\0';
	l.len=0;
}

void creatstr(sqtr &  l) //创建串
{
	char t='\0';int i=0;
	cout<<"输入第"<<i+1<<"个数据,输入E结束:";
	cin>>t;
	
	while(t!='E')
	{
		
		
		l.data[i]=t;
		i++;l.len++;
		cout<<"输入第"<<i+1<<"个数据,输入E结束:";
		cin>>t;
	}
}

		


void getnext(sqtr & l,int next[])     //求得串l的next数组.
{
	int i=0,j=-1;next[0]=-1;
	while(i<l.len-1)
	{
		if(j==-1||l.data[i]==l.data[j])
		{
			i++;j++;
			next[i]=j;
		}
		else
		{
		    j=next[j];
		}
	}
}

int kmp(sqtr & s,sqtr & t) //查找子串在模式串中的位置.使用的是kmp算法.
{
	int i=0,j=0;int next[maxlen];
	getnext(t,next);
	while(i<s.len && j<t.len)
	{
		if(j==-1||s.data[i]==t.data[j])
		{
			i++;j++;
		}
		else
		{
			j=next[j];
		}
	}
		if(j>=t.len) return i-t.len+1;
		else
			return -1;
}

void main()
{
	sqtr s,t;
	initsq(s);initsq(t);
	cout<<"创建主串."<<endl;
	creatstr(s);
	cout<<"创建模式串."<<endl;
	creatstr(t);
	if(kmp(s,t)==-1)cout<<"子串不再模式串中."<<endl;
	else
	{

	cout<<"模式串在主串的第"<<kmp(s,t)<<"个位置."<<endl;
	}
}
	

	























	