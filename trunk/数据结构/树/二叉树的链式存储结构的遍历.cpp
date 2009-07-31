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


void initltree(ltree & l)   //��ʼ��������
{
	l.root=NULL;
}
void  creattree(ltree & l,datatype  str[]) ///����������
{
	node * p=NULL;  //p����ָ�����Ľڵ�
	int k=0,j=0,top=-1;  //k��Ϊһ��״̬��־λ,����ǰһ��Ԫ�ص�ֵ��ȷ��һ��Ԫ���������Һ���.������ջ��
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


//*********************��������//

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
	if(l.front==NULL)
	{
		cout<<"�ӿ�."<<endl;return 0;
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
	if(l.front==NULL)
	{
		
		l.front=l.rear=p;
	}
	else
	{
		l.rear->next=p;
		l.rear=p;
	}
}

//*********************������ջ//	

typedef struct snode  //����ջ�����ݽڵ�
{
	node * data;
	struct snode * next;
}snode;
typedef struct  //������ջ
{
	snode * top;
	int len;
}lstack;




void initstack(lstack & l)  //��ʼ��ջ�ռ�
{
	l.top=NULL;
	l.len=0;
}

node * read(lstack & l) //��ȡջ��Ԫ��
{
	return l.top->data;
}


node * pop(lstack & l)  //��ջ,����ָ�����Ľڵ��ָ��.
{
	snode *p=l.top;node * q;
	if(p==NULL) {cout<<"ջ��.";return 0;}
	else
	{
		l.top=p->next;
		q= p->data;
		l.len--;
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
	 l.len++;
}



//********************�������ı���--�ݹ��㷨//





void preorder(node *p)  //�ȸ�����--�ݹ��㷨 ,pָ��������ĸ��ڵ�
{
	
	if(p!=NULL)
	{
	cout<<p->data<<" ";   
	preorder(p->lch);
	preorder(p->rch);
	}
}

void inorder(node *p)   //�и�����--�ݹ��㷨
{
	
	if(p!=NULL)
	{
	inorder(p->lch);
	cout<<p->data<<" ";
	inorder(p->rch);
	}
}

void postorder(node *p)    //�������--�ݹ��㷨
{
	
	if(p!=NULL)
	{
	postorder(p->lch);
	postorder(p->rch);
	cout<<p->data<<" ";
	}
}


//********************��α���//


bool levelorder(ltree & l)    //��α���--��ʽ�洢.
{
	lqueue a;initlqueue(a);    
	node * p=NULL;
	if(l.root!=NULL) 
	{
		push(a,l.root);    //�Ƚ����ڵ�������ջ
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

//***************************���ı�����ջ�����㷨//


void spreorder(ltree & l)  //�ȸ������ĵ�ջ�����㷨.
{
	lstack a;initstack(a);
	node * p=l.root;
	if(p!=NULL)
	{   
		push(a,NULL); //Ҫ���Ƚ�һ��Ԫ�طŽ�ջ�еĵ�һ��λ��,Ϊ����ѭ������׼��.
		do              //����ʹ��while()ѭ��Ҳ����,����Ҫע��ѭ����ֹ��������ջ��,������һ��Ҫ���Ƚ�һ��Ԫ�طŽ�ջ�ס�
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
				
				if(p->rch!=NULL) p=p->rch; //������Ӳ�����,���Һ��Ӵ���,ֱ��ָ�����Һ���.������Һ��Ӷ�������,��ʼ��ջ.
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

void spostorder(ltree & l)   //���������ջ�����㷨.
{

 	lstack a;initstack(a);
	node * p=l.root,* q=NULL,*r=NULL;
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
			
				if(p->rch!=NULL) p=p->rch; //����Һ��Ӵ���,ֱ��ָ�����Һ���.������Һ��Ӷ�������,��ʼ��ջ.
				else 	
				{
					cout<<p->data<<" ";r=p;
					while(a.top!=NULL)//���δ�ջ�е���Ԫ��ֱ��ջ�ա�
					{
					p=read(a);
					if(p==NULL) {pop(a);break;} //�����������Ԫ��������Ԥ���ȥ��NULL��ô˵��վ�ڵĵ�Ԫ�ش�����ϣ��˳�ѭ����
					if(p->rch==q&&p->rch!=r)
					{
						p=pop(a);cout<<p->data<<" ";q=p;
					}
					else
					{
					 if(p->rch!=NULL) p=p->rch;
					}

					
				
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
	cout<<"��α���."<<endl;
	levelorder(m); 
	cout<<endl;
	cout<<"�ݹ����."<<endl;
	cout<<"�������:"<<endl;
	preorder(m.root);cout<<endl;
	cout<<"�������"<<endl;
	inorder(m.root);cout<<endl;
	cout<<"�������"<<endl;
	postorder(m.root);cout<<endl;
	cout<<"ջ�����㷨:"<<endl;
	cout<<"�������-ջ�����㷨."<<endl;
	spreorder(m);
	cout<<endl;
	cout<<"�������-ջ�����㷨."<<endl;
	sinorder(m);
	cout<<endl;
	cout<<"�������-ջ�����㷨."<<endl;
	spostorder(m);
	cout<<endl;
}





			














		

	
	



	