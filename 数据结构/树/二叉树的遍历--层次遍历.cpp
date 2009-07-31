#include<iostream.h>   //��ʽ�洢�ṹ
#include<iostream>  
#include<string.h>
#define max 100
typedef char datatype;

typedef struct node    //��������Ľڵ�
{
	datatype data;
	struct node * lch;
	struct node * rch;
}node;
typedef struct         //����������
{
	 struct node * root;
}ltree;


void initltree(ltree & l)   //��ʼ��������
{
	l.root=NULL;
}

void  creattree(ltree & l,datatype  str[]) //���ŷ�����������
{
	node * p=NULL;  //p����ָ�����Ľڵ�
	int k=0,j=0,top=-1;  //k��Ϊһ��״̬��־λ,����ǰһ��Ԫ�ص�ֵ��ȷ��һ��Ԫ���������Һ���.������ջ
	node * a[max];    //��Ϊ�洢˫�׽ڵ��˳��ջʹ�á�
	datatype t=str[j];   //t��Ϊ�ݴ�����Ԫ��ֵ���м������

	while(t!='\0')
	{
		switch(t)
		{
		case '(':top++;a[top]=p;k=1;break;
		case ')':top--;break;
		case ',':k=2;break;
		default:
			{
				p=(node *)malloc(sizeof(node));
				p->data=t;p->lch=NULL;p->rch=NULL;
				if(l.root==NULL){ l.root=p;break;}
				else
				{
					switch(k)
					{
					case 1:a[top]->lch=p;break;
					case 2:a[top]->rch=p;break;
				
					}
				}

			}
			
		}
		j++;
		t=str[j];
	}
}

typedef struct lnode  //�������ӵĽڵ�
{
	node * data;
	struct lnode * next;
}lnode;
typedef struct        //����������
{
	lnode * front;
	lnode * rear;
}lqueue;

void initlqueue(lqueue & l) //��ʼ������.
{
	l.rear=l.front=NULL;
}


node * pop(lqueue & l)    //����
{
	if(l.front==NULL) //����Ҫע���ж�ջ��ջΪ�յ������Ƕ�ͷָ���Ƿ�Ϊ��.
	{
		cout<<"�ӿ�."<<endl;return NULL;
	}
	else
	{
	lnode * p=l.front;node * q;
	l.front=p->next;
    q=p->data;
	free(p);
	return q;
	}
}

void push(lqueue & l,node * x)//���
{
	lnode * p=(lnode *)malloc(sizeof(lnode));
	p->data=x;
	p->next=NULL;
	if(l.front==NULL)  //����Ҫע���ж�ջ��ջΪ�յ������Ƕ�ͷָ���Ƿ�Ϊ��.
	{
		
		l.front=l.rear=p;
	}
	else
	{
		l.rear->next=p;
		l.rear=p;
	}	

}



bool levelorder(ltree & l)    //��α���--��ʽ�洢.
{
	lqueue a;initlqueue(a);    
	node * p=l.root;
	if(p!=NULL) 
	{
		push(a,p);    //�Ƚ����ڵ�������ջ
		while(a.front!=NULL)//ջ��Ϊѭ����ֹ������
		{
		p=pop(a);       
		cout<<p->data<<" "; //��ջ��Ԫ��
		if(p->lch!=NULL) push(a,p->lch);//����Ԫ�ص����Ӽ��к�����ջ,(�������);
		if(p->rch!=NULL) push(a,p->rch);
		}
		return 1;
	}
	else 
	{
		cout<<"����";return 0;
	}
	
}



void main()
{
	ltree m;initltree(m);
    cout<<"��������(�������ű�ʾ��,��100���ַ�����)."<<endl;
    datatype p[max];
    cin>>p;
	cout<<p<<endl;
	creattree(m,p);
	cout<<"��α���."<<endl;
	levelorder(m);
}