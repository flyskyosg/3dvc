
#include<iostream.h> 
#include<iostream>           // ͼ���ڽӾ���洢�ṹ
#define max 50
typedef char datatype;
typedef struct lnode
{

	int number,             //�ڵ�Ҫ�洢�Լ����
	    number1,            //��Ÿ��������ͷ�ڵ�ǰ������ڵ�ı�� //��һ������Ϊ��ʵ�ֺ�����С�����������ĸ���    
	    weight,             //�ڵ�洢�ߵ�Ȩֵ
	    flag;               //״̬��־λ��      //��һ������Ϊ��ʵ�ֺ�����С�����������ĸ���             
	struct lnode *next;     //ָ����һ���ڵ�
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

void creatgraph0(G & l)  //����ͼ
{
	int i=0,j=0,b=0,t=0,w=0;lnode * p,*q;
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
		p->flag=0;p->number1=b;      //��һ����Ϊ��ʵ�ֺ�����С�����������ĸ���
		l.vex[b].first=p;
		
		q=(lnode *)malloc(sizeof(lnode));
        q->number=b;q->weight=w;
		q->next=l.vex[t].first;
		q->flag=0;q->number1=t;
		l.vex[t].first=q;
		
		
	
		
	}
	cout<<"�����ڽ���������."<<endl;
}


void disp(G  l)      //���ͼ
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



//*******************************��С��������prime�㷨��*********************************//

typedef struct mintree         //������С������
{
	int n,e;
	node  vex[max];            //�ڵ�����
}MT;
//***********************//
int visited[max];                     //����Ѿ��ҹ��Ľڵ����� 


void Exchange(G t,MT & l)             //�ú������ڽӱ�ת������С���ɵĴ洢�У��ֱ𽫽ڵ������Ӧ������С�������Ľڵ����飬�ڸ��ݽڵ�ĵ�����һ�ν���l�ıߣ�
{
	int i=0,j=0;lnode *p=NULL;        //i,j��Ϊѭ��������p��Ϊѭ��ָ�룬
	for(i;i<t.n;i++)
	{
		l.vex[i].inf=t.vex[i].inf;
		l.vex[i].number=t.vex[i].number;
        l.vex[i].first=NULL;          //����ע�����Ȱ���С�������Ľڵ㼯��first����Ϊ�ա�
		
	
	}
	l.n=t.n;l.e=t.e;
}



void neibian(G & t)         //�˺�������visited���齫�����Ѿ����ʹ��Ľڵ�֮��ߵ�״̬λ��Ϊ1
{
	int i;lnode * p;
	for(i=0;i<t.n;i++)      //���α����ڵ������ÿ���ڵ�
	{
		p=t.vex[i].first;    
		while(p!=NULL)      //����ÿ������ڵ��ĵ�������ݸ���visited�е�ֵ���������Ľڵ�֮������еıߵ�״̬���Ϊ�Ѿ�����
		{
			if(visited[i]==1&&visited[p->number]==1) //�ڵ�ǰ����ڵ��Լ��������еĽڵ㶼�Ѿ������ʹ�������£����ıߵ�״̬λ���Ϊ1���Ѿ��ҹ�
				p->flag=1;
			p=p->next;
		}
		    	
		
	}
}


  
void px(lnode * p[])         //�Դ�ŷ��ʹ������нڵ㵽����û�з��ʹ��Ľڵ�ıߵ��������ݱߵ�Ȩֵ���������ɴ�������
{
	int i=0;
	lnode * r=NULL;
	if(p[i]!=NULL)
	{
		while(p[i+1]!=NULL)
		{
		   if(p[i]->weight<p[i+1]->weight) //���������е�ַ��ָ��ıߵ�Ȩֵ��������
		   {
			r=p[i];
			p[i]=p[i+1];
			p[i+1]=r;
			
		   }
		   i++;
		}
	}

}




void MinTree(MT & l,G & t)       //������С������
{
	Exchange(t,l) ;   //����С�������Ľڵ�����Ľڵ����ʼ��Ϊͼ�Ľڵ���
	int i,j;    //ѭ������
    lnode * p,* q;  //��ʱָ��	

	for(i=0;i<max;i++)             //��ʼ���������
		visited[i]=0;
	    visited[0]=1;              //���Ƚ�0�Žڵ���Ϊ���ʹ�����0�Žڵ㿪ʼ



	for(i=0;i<l.n-1;i++)           //���ѭ����ʾҪ�ҵ�n-1����
	{
		neibian(t);
     	int  k=0;                  //kΪminb�������������
     	lnode * minb[max];         //���ÿ�����ʹ��Ľڵ㵽����δ���ʹ��Ľڵ�֮�����С�ߵĵ�ַ
        for(j=0;j<max;j++)
			minb[j]=NULL;          //��ʼ��������


		for(j=0;j<l.n;j++)         //���ѭ����ʾҪ�����еķ��ʹ��Ľڵ����ҳ�������δ�����ʹ��Ľڵ�֮�����С�ߡ�ÿ�ζ�����visited������
		{
           

			if(visited[j]==1)      //�ڸýڵ㱳���ʹ���ǰ����
			{
			          
				p=t.vex[j].first;  //p�Ӹýڵ�ĵ�������ĵ�һ���ڵ㿪ʼ
			
		        while(p!=NULL)   
				{
					if(p->flag==0) //���ν��ýڵ�ĵ�������û�б����ʵıߵĵ�ַ����ninb���飬
					{
						minb[k]=p;  
						k++;
					}
					p=p->next;
				}
			}

		}
		px(minb);             //�Եõ���ÿ�����ʹ��Ľڵ㵽����δ���ʹ��Ľڵ�֮������еı�����Ȩֵ��������
		q=minb[k-1];          //����Ҫע��kҪ��1;
		q->flag=1;visited[q->number]=1; //���ñ߱����ʹ��Ժ�Ҫ�Ѹñߵı��λ���Ϊ1�����Ұ��´�����ʹ��ڵ㼯�ϵ��½ڵ�ҲҪ���Ϊ�ѷ���
		lnode * x=(lnode *)malloc(sizeof(lnode));  //Ȼ�󽫵õ��ĸñ߹�����С��������
		x->weight=q->weight;            //�±ߵĲ����ǰѵõ��ı߹�������С�������Ľڵ��������Ӧ�ĵ�������
		x->number=q->number;
		x->next=l.vex[q->number1].first; //�������ͷ�巨
		l.vex[q->number1].first=x;
	}
}

void disp(MT  l)          //���õ�����С���������
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
	MT l0;G l1;
	cout<<"����ͼ:"<<endl;
	creatgraph0( l1);
	cout<<"������ͼ:"<<endl;
	disp(l1);
	cout<<"������С������:"<<endl;
	MinTree(l0,l1) ;
	cout<<"��С������:"<<endl;
	disp(l0);

}

           


		
		


	


				





				







   
	 
































