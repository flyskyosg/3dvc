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
	int count;              //�ڵ����ȣ�                                  
	lnode *first;           //ָ��ڵ���ڽӵ�
}node;
typedef struct graph        //����ͼ
{
	int n,e;                //ͼ�Ľڵ��������
	node vex[max];          //�洢�ڵ����Ϣ�Լ���ţ�first
	
}G;



void creatgraph(G & l)
{
	int i=0,j=0,b=0,t=0,w=0;lnode * p;
	cout<<"����ͼ�Ķ����������:";
	cin>>l.n>>l.e;
	cout<<"��ͼ��"<<l.n<<"������"<<l.e<<"����"<<endl;
	for(;i<l.n;i++)
	{
		cout<<"�������"<<i<<"���ڵ����Ϣ,�������_�ڵ�����_�ڵ����:";
		cin>>l.vex[i].number>>l.vex[i].inf>>l.vex[i].count;
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
	
    cout<<"�����ʽ:"<<"�ڵ����_�ڵ���Ϣ_�ڵ����+�ڽӵ����_�ñߵ�Ȩֵ+........."<<endl;
	for(i;i<l.n;i++)
	{
		
		cout<<l.vex[i].number<<" "<<l.vex[i].inf<<" "<<l.vex[i].count<<"  ";
		p=l.vex[i].first;
		while(p!=NULL)
		{
			cout<<p->number<<" "<<p->weight<<"  ";
			p=p->next;
		}
		cout<<endl;
	
	}
}
//************************AOV������������***************************//


  
void tuopu(G & l)
{
    int visited[max];                   //״̬���飬��¼�Ѿ����ʹ��Ľڵ㣬���ʹ���ȫ��λ��Ϊ1�� 
	int st[max];                        //������Ϊ0�Ľڵ��ջ
	int top=-1;  
    
	for(int i=0;i<l.n;i++)              //��ʼ��״̬����
		visited[i]=0;
	for( i=0;i<l.n;i++)              //���Ƚ����Ϊ0�Ľڵ���ջ���������ѭ��
	{
		if(l.vex[i].count==0&& visited[i]==0)
		{
			top++;
			st[top]=i;
			visited[i]=1;
		}
	}

	lnode * p=NULL;int n;
	while(top>=0)                       //���ѭ�����Ƶ�վ�յ�ʱ����ֹ��ѭ����˵�����е�Ԫ�ش������
	{
		while(top>=0)                   //���ƽ�ջ�ڵ����Ϊ��Ľڵ�������ҽ����Ϊ��Ľڵ�����е�ֱ�Ӻ󼴽ڵ����ȼ�һ
		{
			
			n=st[top];                  
			cout<<l.vex[n].inf<<" ";    //����ڵ�
		
			p=l.vex[n].first;           
			while(p!=NULL)              //���ýڵ�����е��ڽӵ����ȼ�1
			{
				l.vex[p->number].count--;
				p=p->next;
			}
			top--;                      //��top<0��ʱ�򣬳�ջ���
		}

		for( i=0;i<l.n;i++)             //�ٴ�ɨ�����Ϊ0�Ľڵ㣬������ջ
		{
		    if(l.vex[i].count==0&&visited[i]==0)
			{
			top++;
			st[top]=i;
			visited[i]=1;
			}
		}
	}
}



//******************������******************//
			
void main()
{
	G l;
	cout<<"����ͼ:"<<endl;
	creatgraph(l);
	cout<<"�����õ�ͼ:"<<endl;
	disp(l);
	cout<<"��������:";
	tuopu(l);
	cout<<endl;
}






