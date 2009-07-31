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


//**********************����*************************//



void WFSthread(G  t) //������ȱ���
{
	int i=0,j=0,f=-1,r=-1;lnode * p=NULL; ////i,j�ֱ�����ѭ��������f,r��Ϊ˳����еĶ�ͷ���β��p��Ϊ������ʱָ��
	int visited[max];  //ȫ�����飬������Ÿ����ڵ�ı�ǣ���ǽڵ��Ƿ񱻷��ʹ���
    int qu[max+1];      //˳�����


	for( i=0;i<t.n;i++)  //��ʼ��������飬ȫ������Ϊ0��δ�����ʡ�
		visited[i]=0;
    
    
	for( i=0;i<t.n;i++)  //Ϊ�˱�֤��ͨͼ�ͷ���ͨͼ�е�ÿ���ڵ㶼���ʵ��������ÿ���ڵ㶼��Ϊ��ʼ��һ�ο�ʼ���ʡ�
	{
		if(visited[i]==0)   //ÿ���ڵ㿪ʼ������ʱ���ȼ���Ƿ����������û�б�����������´Ӹýڵ㿪ʼ���α���
		{
		  r++;
	      qu[r]=t.vex[0].number;     //���Ƚ���һ���ڵ���ӣ�Ϊ����ѭ����׼����  
		  while(r!=f)           //�ڶӲ��յ������½���ѭ����
		  {
			  f++;
			  j=qu[f];   
			  cout<<t.vex[j].inf<<" ";//�Ƚ���ͷ�ڵ���ԣ�Ȼ���жϽڵ��Ƿ��� �ڽӽڵ㣬�������
			  visited[j]=1;
			  p=t.vex[j].first;
			  while(p!=NULL)   //�ø�ѭ�������е�δ�ʵ��ڽ���ӡ�
			  {
				  if(visited[p->number]==0)
				  {
					  r++;
					  qu[r]=p->number;
					 
				  }
				  p=p->next;
			  }
		  }
		}
	}
}

			 


//************************������*********************//

void main()
{
	G l1,l0;

      

	cout<<"��������ͼ:"<<endl;
	creatgraph1(l1);
	disp(l1);
	
	cout<<"���������ڽӱ�:";
	WFSthread(l1);
	cout<<endl;

	cout<<"��������ͼ:"<<endl;
	creatgraph1(l0);
	disp(l0);
	cout<<"�����������ڽӱ�:";
	WFSthread(l0);
	cout<<endl;
}






