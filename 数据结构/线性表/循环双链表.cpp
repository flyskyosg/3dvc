#include<iostream.h>     //ѭ��˫����
typedef struct node         //����ڵ�����ݽṹ
{
	int data;
	struct node *prior;
	struct node *next;
}Node;
typedef struct list  //���������ݽṹ
{
	Node *head;
	int length;
}List;
void initlist(List & l)      //��ʼ��˫����
{
	l.head=NULL;
	l.length=0;
}
void creatlist(List & l)
{
	Node *p,*q;int i=1;

	cout<<"����������,����0��������:"<<endl;
	while(i!=0)
	{
	p=new Node;
	cin>>i;
	if(i==0) break;
	p->data=i;
    if(l.head==NULL)     //����Ҫ�жϱ��Ƿ�Ϊ�ձ�,����ǿձ�,
	{
		
		p->next=p;
		p->prior=p;
		l.head=p;
		q=l.head;
	
	}
	else
	{
		q->next=p;  //�����ǿձ��ʱ�����ʾ�ձ��ʱ��ͬ//
		p->prior=q;
		p->next=l.head;
		(l.head)->prior=p;
		q=p;
	}
	l.length++;
	
	}
	cout<<"�������."<<endl;
}
void putin(List & l)           //��ĳһλ���ϲ���Ԫ��//
{
	int i=1,j=1;Node *q=l.head,*p,*r;
	p=new Node;
	cout<<"���������Ԫ�ص�ֵ:";
	cin>>p->data;
	cout<<"���������λ��:";cin>>i;cout<<endl;
	if(i<1||i>l.length+1) cout<<"position error.";
	else
	{
        while(j!=i)          //Ѱ�Ҳ���Ԫ�ص�λ��//
		{
			q=(*q).next;
			j++;
		}
	
			r=(*q).prior;       //ʵ�ֲ����㷨//
		    p->next=q;p->prior=r;
		    q->prior=p;r->next=p;
			if(i==1) l.head=p;
	}
	l.length++;      //����������ǰѱ�����
}
	
void deletelist(List & l) //ɾ��ĳһλ���ϵ�Ԫ��
{
	int i=1,j=1;Node *q=l.head,*r,*p;
	cout<<"����ɾ��Ԫ�ص�λ��:";cin>>i;
	if(i<1||i>l.length) cout<<"position error.";
	else 
	{
		while(j!=i)      //Ѱ��ɾ��Ԫ�ص�λ��,
		{
			q=q->next;
			j++;
		}
		r=q->prior;        
		p=q->next;
		r->next=p;
		p->prior=r;
		if(q==l.head)     //��Ҫ�ж�һ���Ƿ�ѵ�һ��Ԫ��ɾ��,���ɾ����һ��Ԫ��,��Ҫ��ͷָ��ָ����һ��Ԫ��.
		{
			l.head=p;
		}
	}
	l.length--;
}
void lookfor(List &l) //������Ų���Ԫ��
{
	int i=1,j=1;Node *q=l.head;
    cout<<"������Ԫ��λ��:";cin>>i;cout<<endl;
	if(i<1||i>l.length) cout<<"position error.";
	else
	{
        while(j!=i)
		{
			q=q->next;
			j++;
		}
	
		cout<<"��Ԫ����:"<<q->data<<endl;
	}
}
void disp(List &l)  //�����������Ԫ��
{
	Node *p=l.head;
	cout<<"�ñ��Ԫ���б���:"<<endl;
	for(int i=1;i<=l.length;i++)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

void main()          
{
	List l;
	initlist(l);
	creatlist(l);
	disp(l);
	putin(l);
    disp(l);
	deletelist(l);
	disp(l);
	lookfor(l);
}
	



	
		




	

	



		
	




