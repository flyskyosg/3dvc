#include<iostream.h>
#include<string.h>
#include<iostream>
#define max 10
typedef struct node
{
	char data;
	struct node * next;
}node;
typedef struct sqstring
{
	node * head;
	int len;
}sqtr;

void initsq(sqtr & l)//��ʼ����
{
  l.head=NULL;
  l.len=0;
}

void creatstr(sqtr &  l) //������
{
	char t='\0';node *p,*q;int i=0;
	cout<<"�����"<<i+1<<"������,����E����:";
	cin>>t;
	
	while(t!='E')
	{
           p=(node *)malloc(sizeof(node));
		   p->data=t;
		   p->next=NULL;
		   if(l.head==NULL)
		   {
			   l.head=p;
			   q=p;
		   }
		   else
		   {
			   q->next=p;
				q=p;
		   }
		i++;l.len++;
		cout<<"�����"<<i+1<<"������,����E����:";
		cin>>t;
	}
}

void exchange(sqtr & l,char t[])
{
	node * p=l.head;
	for(int i=0;i<l.len;i++)
	{
		t[i]=p->data;
		p=p->next;
		
	}
}


		


void getnext(char t[],int next[])     //��ô�l��next����.
{
	int i=0,j=-1;next[0]=-1;
	while(i<strlen(t)-1)
	{
		if(j==-1||t[i]==t[j])
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
int kmp(char  s[],char  t[]) //�����Ӵ���ģʽ���е�λ��.ʹ�õ���kmp�㷨.
{
	
	int i=0,j=0;int  next[max];
	getnext(t,next);
	while(i<strlen(s) && j<strlen(t))
	{
		if(j==-1||s[i]==t[j])	
		{
			i++;j++;
		}
		else
		{
			j=next[j];
		}
	}
		if(j>=strlen(t)) return -(i-strlen(t)+1);
		else
			return -1;
}
void disp(sqtr &  l)
{
	node *p=l.head;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

void disp(char t[])
{
	for(int i=0;i<strlen(t);i++)
	{
		cout<<t[i]<<" ";
	}
	cout<<endl;
}



void main()
{
	sqtr s,t;int m=0;
	initsq(s);initsq(t);
	cout<<"��������."<<endl;
	creatstr(s);
	cout<<"����ģʽ��."<<endl;
	creatstr(t);
    
char s1[max];char t1[max];
for(int i=0;i<max;i++)
{
	s1[i]='\0';t1[i]='\0';
}
 disp(s);
 exchange(s,s1);
 disp(s1);
 disp(t);
 exchange(t,t1); 
 disp(t1);



    m=kmp(s1,t1);
	if(m==-1)cout<<"�Ӵ�����ģʽ����."<<endl;
	else
	{

	cout<<"ģʽ���������ĵ�"<<m<<"��λ��."<<endl;
	}
}
	

	