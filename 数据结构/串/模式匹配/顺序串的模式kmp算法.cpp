#include<iostream.h>
#define maxlen 10
typedef char sstring[maxlen];
typedef struct sqstring
{
	char data[10];
	int len;
}sqtr;

void initsq(sqtr & l)//��ʼ����
{
	for(int i=0;i<maxlen;i++)
		l.data[i]='\0';
	l.len=0;
}

void creatstr(sqtr &  l) //������
{
	char t='\0';int i=0;
	cout<<"�����"<<i+1<<"������,����E����:";
	cin>>t;
	
	while(t!='E')
	{
		
		
		l.data[i]=t;
		i++;l.len++;
		cout<<"�����"<<i+1<<"������,����E����:";
		cin>>t;
	}
}

		


void getnext(sqtr & l,int next[])     //��ô�l��next����.
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

int kmp(sqtr & s,sqtr & t) //�����Ӵ���ģʽ���е�λ��.ʹ�õ���kmp�㷨.
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
	cout<<"��������."<<endl;
	creatstr(s);
	cout<<"����ģʽ��."<<endl;
	creatstr(t);
	if(kmp(s,t)==-1)cout<<"�Ӵ�����ģʽ����."<<endl;
	else
	{

	cout<<"ģʽ���������ĵ�"<<kmp(s,t)<<"��λ��."<<endl;
	}
}
	

	























	