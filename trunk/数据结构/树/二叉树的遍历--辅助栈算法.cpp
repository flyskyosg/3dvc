#include<iostream.h>   //��ʽ�洢�ṹ
#include<iostream>  
typedef char datatype;
#define max 100
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


void  creattree(ltree & l,datatype  str[]) ///����������
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

void initltree(ltree & l)   //��ʼ��������
{
	l.root=NULL;
}

typedef struct snode  //����ջ�����ݽڵ�
{
	node * data;
	struct snode * next;
}snode;
typedef struct  //������ջ
{
	snode * top;
}lstack;

void initstack(lstack & l)//��ʼ��ջ�ռ�
{
	l.top=NULL;
}

node * pop(lstack & l)  //��ջ,����ָ�����Ľڵ��ָ��.
{
	snode *p=l.top;node * q;
	if(p==NULL) {cout<<"ջ��.";return 0;}
	else
	{
		l.top=p->next;
		q= p->data;
		free(p);
		return q;

	}
}

void push(lstack & l,node * x) //��ջ����
{
	 snode * p=(snode *)malloc(sizeof(snode ));
	 p->data=x;
	 p->next=l.top;
	 l.top=p;
}



void spreorder(ltree & l)  //�ȸ������ĵ�ջ�����㷨.
{
	lstack a;initstack(a);
	node * p=l.root;
	if(p!=NULL)
	{   
		push(a,p); //Ҫ���Ƚ�һ��Ԫ�طŽ�ջ�еĵ�һ��λ��,Ϊ����ѭ������׼��.
		do              //����ʹ��while()ѭ��Ҳ����,����Ҫע��ѭ����ֹ��������ջ��,������һ��Ҫ���Ƚ�һ��Ԫ�طŽ�ջ��
		{
			cout<<p->data<<" ";  //�ȸ�����ʱ�����ڵ�ʱ�Ƚ��ڵ��ֵ���.
			if(p->lch!=NULL)       //������Ӵ��ڽ�pָ��������,������������ֺ���,���ֺ��ӽ�ջ����.
			{
				if(p->rch!=NULL)
				push(a,p->rch);
				p=p->lch;
			}

			else
			{
				
				if(p->rch!=NULL) p=p->rch; //������Ӳ�����,���Һ��Ӵ���,ֱ��ָ�����Һ���.�������Һ��Ӷ�������,��ʼ��ջ.
				else p=pop(a);
					 
			}
		}while(a.top!=NULL);//�ж�������ջ�Ƿ�Ϊ��.
	}
	else cout<<"��Ϊ��."<<endl;
}

void sinorder(ltree & l)   //�и�������ջ�����㷨.
{

 	lstack a;initstack(a);
	node * p=l.root;
	if(p!=NULL)
	{   
	    push(a,NULL);       //Ҫ���Ƚ�һ��Ԫ�طŽ�ջ�еĵ�һ��λ��,Ϊ��ߵ�ѭ����׼��.
		while(a.top!=NULL)       //�ж�������:ջ�Ƿ�Ϊ��.  ����ʹ�� while()ѭ��Ҳ����,����Ҫע��ѭ����ֹ��������ջ��,������һ��Ҫ���Ƚ�һ��Ԫ�طŽ�ջ��
		{
			
			if(p->lch!=NULL)     //������Ӵ���;
			{
				push(a,p);       //����ǰ�ĸ��ڵ���ջ.
				p=p->lch;        //����ָ��������.
			}

			else
			{
				cout<<p->data<<" ";
				if(p->rch!=NULL) p=p->rch; //����Һ��Ӵ���,ֱ��ָ�����Һ���.������Һ��Ӷ�������,��ʼ��ջ.
				else 	
				{
					while(a.top!=NULL)//���δ�ջ�е���Ԫ��֪��ֱ��վ��
					{
					p=pop(a);
					if(p==NULL) break;  //�����������Ԫ��������Ԥ���ȥ��NULL��ô˵��վ�ڵĵ�Ԫ�ش�����ϣ��˳�ѭ����
					cout<<p->data<<" "; //��Ϊ��������������Գ�վ��������ýڵ㡣
					if(p->rch!=NULL) {p=p->rch;break;}//���������Ԫ�ؾ����Һ��ӣ���ôָ�����Һ��Ӳ��˳���ʼ�µ��жϡ�
				
					}
				}
				
			}
			
		
				
		

		}
	}
	else cout<<"��Ϊ��."<<endl;


}


void main()
{
	ltree m;initltree(m);
	cout<<"��������(�������ű�ʾ��,��100���ַ�����)."<<endl;
    datatype p[max];
    cin>>p;
	cout<<p<<endl;
	creattree(m,p);
	cout<<"�ȸ�����-ջ�����㷨."<<endl;
	spreorder(m);
	cout<<"�и�����-ջ�����㷨."<<endl;
	sinorder(m);


}