#include<iostream.h> 
#include<iostream>           // ͼ���ڽӾ���洢�ṹ
#define max 50
typedef char datatype;
typedef struct lnode
{
	int number;             //�ڵ�Ҫ�洢����
	int weight;             //�ڵ�洢�ߵ�Ȩֵ
	struct lnode *next;      //ָ����һ���ڵ�
}lnode;

typedef struct node 
{
	int   number;           //�ڵ�Ҫ�洢����
	datatype inf;           //�ڵ���Ϣ         
	lnode *first;           //ָ��ڵ���ڽӵ�
}node;
typedef struct graph        //����ͼ
{
	int n,e;                //ͼ�Ľڵ��������
	node vex[max];          //�洢�ڵ����Ϣ�Լ���ţ�first
	
}G;

void creatgraph0(G & l)
{
	int i=0,j=0,b=0,t=0,w=0;lnode * p,* q;
	cout<<"����ͼ�Ķ����������:";
	cin>>l.n>>l.e;
	cout<<"��ͼ��"<<l.n<<"������"<<l.e<<"����"<<endl;
	for(;i<l.n;i++)
	{
		cout<<"�������"<<i<<"���ڵ����Ϣ,�������_�ڵ�����:";
		cin>>l.vex[i].number>>l.vex[i].inf;
		l.vex[i].first=NULL;
	}
	

    for(j=0;j<l.e;j++)
	{
		cout<<"����ߵ���Ϣ,������_�յ�_Ȩֵ:";
		cin>>b>>t>>w;
        
		if(b<0||b>=l.n) cout<<"��㲻��������Χ��."<<endl;
        
		if(t<0||t>=l.n) cout<<"�յ㲻��������Χ��."<<endl;
        
		p=(lnode *)malloc(sizeof(lnode));
        p->number=t;p->weight=w;
		p->next=l.vex[b].first;
		l.vex[b].first=p;
		
		q=(lnode *)malloc(sizeof(lnode));
        q->number=b;q->weight=w;
		q->next=l.vex[t].first;
		l.vex[t].first=q;
		
		
	}
	cout<<"�����ڽ���������."<<endl;
}

void creatgraph1(G & l)
{
	int i=0,j=0,b=0,t=0,w=0;lnode * p;
	cout<<"����ͼ�Ķ����������:";
	cin>>l.n>>l.e;
	cout<<"��ͼ��"<<l.n<<"������"<<l.e<<"����"<<endl;
	for(;i<l.n;i++)
	{
		cout<<"�������"<<i<<"���ڵ����Ϣ,�������_�ڵ�����:";
		cin>>l.vex[i].number>>l.vex[i].inf;
		l.vex[i].first=NULL;
	}
	

    for(j=0;j<l.e;j++)
	{
		cout<<"����ߵ���Ϣ,������_�յ�_Ȩֵ:";
		cin>>b>>t>>w;
        
		if(b<0||b>=l.n) cout<<"��㲻��������Χ��."<<endl;
        
		if(t<0||t>=l.n) cout<<"�յ㲻��������Χ��."<<endl;
        p=(lnode *)malloc(sizeof(lnode));
        p->number=t;p->weight=w;
		p->next=l.vex[b].first;
		l.vex[b].first=p;
		
		
		
	}
	cout<<"���������ڽӱ����."<<endl;
}
void disp(G  l)
{
	int i=0;lnode * p;
	
    cout<<"�����ʽ:"<<"�ڵ����_�ڵ���Ϣ+�ڽӵ����_�ñߵ�Ȩֵ+........."<<endl;
	for(i;i<l.n;i++)
	{
		
		cout<<l.vex[i].number<<" "<<l.vex[i].inf<<"  ";
		p=l.vex[i].first;
		while(p!=NULL)
		{
			cout<<p->number<<" "<<p->weight<<"  ";
			p=p->next;
		}
		cout<<endl;
	
	}
}

void main()
{
	G l;
	creatgraph0(l);
	disp(l);
}






