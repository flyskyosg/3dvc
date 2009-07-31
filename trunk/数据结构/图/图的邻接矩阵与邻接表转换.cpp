#include<iostream.h>  
#include<iostream>          // ͼ���ڽӾ���洢�ṹ
#define max 50
typedef char datatype;
typedef struct node0 
{
	int number;             //�ڵ�Ҫ�洢���ż�����
	datatype inf;
}node0;
typedef struct graph0
{
	int n,e;
	node0 vex[max];         //�洢�ڵ����Ϣ
	int edge[max][max];      //�洢�ߵ���Ϣ
}G0;

//�ڽӱ�ڵ�

typedef struct lnode
{
	int number;             //�ڵ�Ҫ�洢����
	int weight;             //�ڵ�洢�ߵ�Ȩֵ
	struct lnode *next;      //ָ����һ���ڵ�
}lnode;

typedef struct node1 
{
	int   number;           //�ڵ�Ҫ�洢����
	datatype inf;           //�ڵ���Ϣ         
	lnode *first;           //ָ��ڵ���ڽӵ�
}node1;
typedef struct graph1        //����ͼ
{
	int n,e;                //ͼ�Ľڵ��������
	node1 vex[max];          //�洢�ڵ����Ϣ�Լ���ţ�first
	
}G1;






void creatgraph0(G0 & l)       //�����ڽӾ���
{
	int i=0,j=0,b=0,t=0,w=0;
	cout<<"����ͼ�Ķ����������:";
	cin>>l.n>>l.e;
	cout<<"��ͼ��"<<l.n<<"������"<<l.e<<"����"<<endl;
	for(;i<l.n;i++)
	{
		cout<<"�������"<<i<<"���ڵ����Ϣ,�������_�ڵ�����:";
		cin>>l.vex[i].number>>l.vex[i].inf;
	}
	for(i=0;i<l.n;i++)
		for(j=0;j<l.n;j++)
			l.edge[i][j]=0;

    for(j=0;j<l.e;j++)
	{
		cout<<"����ߵ���Ϣ,������_�յ�_Ȩֵ:";
		cin>>b>>t>>w;
        
		if(b<0||b>=l.n) cout<<"��㲻��������Χ��."<<endl;
        
		if(t<0||t>=l.n) cout<<"�յ㲻��������Χ��."<<endl;

		l.edge[b][t]=w;
	}
	cout<<"�����������."<<endl;
}



void creatgraph1(G1 & l1,G0 & l0) //���������ڽӱ�
{
	int i=0,j=0,t=0;lnode * p;
	

		for(i;i<l0.n;i++)
		{
			l1.vex[i].inf=l0.vex[i].inf;
			l1.vex[i].number=l0.vex[i].number;
			l1.vex[i].first=NULL;
			
		}
		l1.n=l0.n;
		l1.e=l0.e;		
	   for(i=0;i<l0.n;i++)
		   for(j=0;j<l0.n;j++)
		   {
			   t=l0.edge[i][j];
			   if(t!=0)
			   {
				   p=(lnode *)malloc(sizeof(lnode));
                   p->number=j;p->weight=t;
		           p->next=l1.vex[i].first;
		           l1.vex[i].first=p;
			   }
		   }
		   cout<<"�����ڽӱ����."<<endl;
}
		
		          
		    
	
	
   
	
void disp(G0  l)
{
	int i=0,j=0;
	for(i;i<l.n;i++)
	{
		for(j=0;j<l.n;j++)
			cout<<" "<<l.edge[i][j];
		cout<<endl;
	}
}




void disp(G1  l)
{
	int i=0;lnode * p;
	
    
	for(i;i<l.n;i++)
	{
		
		cout<<l.vex[i].inf<<" "<<l.vex[i].number<<"  ";
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
	G0 l0;G1 l1;
	creatgraph0(l0);
	cout<<"�ڽӾ���:"<<endl;
	disp(l0);
	cout<<"ת�����ڽӱ�:"<<endl;
	creatgraph1(l1,l0);
	disp(l1);
}
















