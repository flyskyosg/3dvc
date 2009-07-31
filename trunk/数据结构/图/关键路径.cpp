#include<iostream.h> 
#include<iostream>          // ͼ���ڽӾ���洢�ṹ
#define max 50
#define mweight 50
typedef char datatype;
typedef struct lnode
{
	int number,             //�ڵ�Ҫ�洢����
	    weight,             //�ڵ�洢�ߵ�Ȩֵ
	    ve,                 //�ߵ����緢��ʱ�� 
		vl;                 //�ߵ�������ʱ�� 
	struct lnode *next;     //ָ����һ���ڵ�
}lnode;

typedef struct node 
{
	int   number;           //�ڵ�Ҫ�洢����
	datatype inf;           //�ڵ���Ϣ
	int count,              //�ڵ����ȣ� 
	    ve,                 //�ڵ�����緢��ʱ��
		vl;                 //�ڵ��������ʱ��
	lnode *first;           //ָ��ڵ���ڽӵ�
}node;
typedef struct graph        //����ͼ
{
	int n,e;                //ͼ�Ľڵ��������
	node vex[max];          //�洢�ڵ����Ϣ�Լ����,first
	
}G;

//************************����ͼ*************************//

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
		l.vex[i].ve=0;                         //�����нڵ�ĳ�ʼ���緢��ʱ������Ϊ0�������߱Ƚ�ȡ�·���㷨ʵ��
		l.vex[i].vl=mweight;                    //�����нڵ�ĳ�ʼ������ʱ������Ϊweight,f������ıȽ�ȡ���·���㷨��ʵ��
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
//************************AOE���Ĺؼ�·��***************************//


  
void keyroad(G & l)
{

	//*************�ȴ���ڵ�����緢��ʱ���Լ��������ıߵ����緢��ʱ��
    int visited[max],                   //״̬���飬��¼�Ѿ����ʹ��Ľڵ㣬���ʹ���ȫ��λ��Ϊ1;
	    st[max],                        //������Ϊ0�Ľڵ��ջ
	    top=-1;  
   	for(int i=0;i<l.n;i++)              //��ʼ��״̬����
		visited[i]=0;
	for( i=0;i<l.n;i++)                 //���Ƚ����Ϊ0�Ľڵ���ջ�������ߵ�ѭ��
	{
		if(l.vex[i].count==0&& visited[i]==0)
		{
			top++;
			st[top]=i;
			visited[i]=1;
			break;                      //��ΪAOE���������Ϊ0�Լ�����Ϊ0�ĵ�ֻ��һ��������һ���ҵ��Ϳ���ֹͣѭ��
		}
	}
	l.vex[i].ve=0;l.vex[i].vl=0;        //ԭ������緢��ʱ���������ʱ��ض�Ϊ0


	lnode * p=NULL;
	int n=0,j=-1,                       //��Ϊ�洢�ڵ����ʱ����
	    order[max];                     //��¼���������˳���������.�����ߵ�������ʱ��Ĵ���ȫ������ 000000000000       
	while(top>=0)                       //���ѭ�����Ƶ�վ�յ�ʱ����ֹ��ѭ����˵�����е�Ԫ�ش������
	{
		while(top>=0)                   //���ƽ�ջ�ڵ����Ϊ��Ľڵ�������ҽ����Ϊ��Ľڵ�����е�ֱ�Ӻ󼴽ڵ����ȼ�һ
		{
			
			n=st[top];
			j++;
			order[j]=n;                 //��¼���������˳���������
			p=l.vex[n].first;
			visited[n]=1;               //����Ѿ����ʹ��Ľڵ� 
				
		          
			while(p!=NULL)              //���ýڵ�����е��ڽӵ����ȼ�1,
			{
				l.vex[p->number].count--;
				if(l.vex[n].ve+p->weight>l.vex[p->number].ve) l.vex[p->number].ve=l.vex[n].ve+p->weight; //�ؼ������θ�д�ýڵ�����緢��ʱ�䣬���������ڽ�·����ȡ�����·��
				p=p->next;
			}
			top--;                      //��top<0��ʱ�򣬳�ջ���
		}

		for( i=0;i<l.n;i++)             //�ٴ�ɨ�����Ϊ0�Ľڵ�;������ջ
		{
		    if(l.vex[i].count==0&&visited[i]==0)
			{
			
				top++;
			    st[top]=i;
			
			}
		}
	}

//************���洦��ڵ��������ʱ�䣬    �������������˳������ĵ�������Ϊ����
 l.vex[order[j]].vl=l.vex[order[j]].ve;       //�������緢��ʱ���������ʱ����ͬ 
 int m=0;                                     //��Ϊ�洢�ڵ���ŵ���ʱ����
 for(j;j>=0;j--)
 {
	 m=order[j];
	 for(i=0;i<l.n;i++)
	 {
		 p=l.vex[i].first;
		 while(p!=NULL)
		 {
			 if(p->number==m&&l.vex[m].vl-p->weight<l.vex[i].vl)        //�ؼ�����������������˴ӽڵ���ڽӵ����ѡ����С·�������θ�д�ٽӵ����С·����ѭ����Ϻ��������е��ڽ�·����ȡ��С·��
			 {
				 l.vex[i].vl=l.vex[m].vl-p->weight;                   
			 }
			 p=p->next;
		 }
	 }
 }


//******************�±ߴ���ߵ������Լ�������ʱ��**************//
 for(i=0;i<l.n;i++)
 {
	 p=l.vex[i].first;
	 while(p!=NULL)
	 {
		 p->ve=l.vex[i].ve;
		 p->vl=l.vex[p->number].vl-p->weight;
		 if(p->ve==p->vl) cout<<i<<"->"<<p->number<<"�ؼ��"<<endl;
		 p=p->next;
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
	cout<<"AOE�ؼ�·��:"<<endl;
	keyroad(l);
	cout<<endl;
}






