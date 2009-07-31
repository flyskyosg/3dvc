#include<iostream.h>   //��ʽ�洢�ṹ
#include<iostream>
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


void  creattree(ltree & l,datatype  str[])  //���ŷ�����������
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

int t=0,k;

int  preorder(node *p)  //�ȸ�����--�ݹ��㷨 ,pָ��������ĸ��ڵ�
{
	
	if(p!=NULL)
	{
    t++;
	if(t==k){	cout<<p->data<<"Ϊ��"<<k<<"��λ���ϵĽڵ�."<<endl; return 1;  }

	preorder(p->lch);
	preorder(p->rch);
	}
	else
	{
		return 0;
	}
}

void main()
{
	ltree a;a.root=NULL;
    cout<<"��������(�������ű�ʾ��,��100���ַ�����)."<<endl;
    datatype p[max];
    cin>>p;
	cout<<p<<endl;
	creattree(a,p);
	cout<<"����λ��:";
	cin>>k;
	cout<<endl;
    preorder(a.root);
}


