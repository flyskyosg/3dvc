#include<iostream.h>   //��ʽ�洢�ṹ
#include<iostream>  
#include<string.h>
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

void  creattree(ltree & l,datatype  str[])
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





void aoru(node * p,int n)
{
	if(p)
	{
	   for(int i=1;i<=n;i++)
		   cout<<"-";
	   cout<<p->data<<endl;
	  
	   if(p->lch) aoru(p->lch,n+1);
	   if(p->rch) aoru(p->rch,n+1);
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
	cout<<"���뷨��ʾ:"<<endl;
	aoru(m.root,1);

	
}



