#include <stdio.h>
#include<iostream.h>
#define MAXLEN 100
#define k 3
typedef struct BT
{  char data;
   BT* lchild;
   BT*rchild;
}BT;
BT *CreateBT();
int knode(BT * p);
void exchange(BT *p);
void ShowTree(BT *T);
void Preorder(BT *T);
void Postorder(BT *T);
void Levelorder(BT *T);
void Inorder(BT *T);
void Leafnum(BT *T);
void Nodenum(BT *T);
int TreeDepth(BT *T);
int count=0;
void main()
{ BT *T=NULL;
  char ch1,ch2,a;
  ch1='y';
  while(ch1=='y'||ch1=='Y')
  {  printf("\n\n\n\n");
     printf("\n\n\t\t\t ��������ϵͳ\n");
	 printf("\n\t\t******************************************");
	 printf("\n\t\t*       1----------��������              *");
     printf("\n\t\t*       2----------�����Գ�              *");
	 printf("\n\t\t*       3----------�������              *");
     printf("\n\t\t*       4----------�������              *");
     printf("\n\t\t*       5----------�������              *");
     printf("\n\t\t*       6----------��α���              *");
     printf("\n\t\t*       7----------��Ҷ����              *");
     printf("\n\t\t*       8----------������              *");
     printf("\n\t\t*       9----------�������              *");
	 printf("\n\t\t*       a---------������������          *");
	 printf("\n\t\t*       b---------���k���ڵ�           *");
     printf("\n\t\t*       0----------��������              *");
     printf("\n\t\t******************************************");
	 printf("\n\t\t��ѡ��˵���(0--9):");
	 scanf("%c",&ch2);
	 getchar();
	 printf("\n");
	 switch(ch2)
	 { 
		 case '1':
			 printf("\n\t\t �����밴�������������Ľ������:");
             printf("\n\t\t˵��:'0'�����̽��Ϊ��,���������,���س�������һ����㡣");
             printf("\n\t\t����������:");
			 T=CreateBT();
			 printf("\n\t\t�������ɹ�����!\n");break;

case'2':
	ShowTree(T);break;
case'3':
	printf("\n\t\t�ö������������������Ϊ:");
	Preorder(T);break;
case'4':
	printf("\n\t\t�ö������������������Ϊ:");
	Inorder(T);break;
case'5':
	printf("\n\t\t�ö������ĺ����������Ϊ:");
    Postorder(T);break;
case'6':
	printf("\n\t\t�ö������Ĳ�α�������Ϊ:");break;
case'7':
	count=0;Leafnum(T);
	printf("\n\t\t�ö�������%d��Ҷ�ӡ�\n",count);break;
case'8':
	count=0;Nodenum(T);
    printf("\n\t\t�ö������ܹ���%d����㡣\n",count);break;
case'9':
	printf("\n\t\t�����������:%d",TreeDepth(T));break;
case'a':
	cout<<"������������."<<endl;exchange(T);break;
case'b':
	cout<<"���k���ڵ�."<<endl;knode(T);break;
case'0':
	ch1='n';break;
default:
	printf("\n\t\t***��ע�⣺��������!***");
}
if(ch2!='0')
{ printf("\n\t\t���س�����������������������˵���");
  a=getchar();
  if(a!='\xA')
  {getchar();ch1='n';}
}
}
}
BT *CreateBT()
{ BT *t;
  char x;
  scanf("%c",&x);
  getchar();
  if(x=='0')
      t=NULL;
  else
  {t=new BT;
   t->data=x;
   printf("\n\t\t������%c�������ӽ��:",t->data);
   t->lchild=CreateBT();
   printf("\n\t\t������%c�������ӽ��:",t->data);
   t->rchild=CreateBT();
  }
  return t;
}
void Preorder(BT *T)
{ if(T)
{ printf("%3c",T->data);
  Preorder(T->lchild);
  Preorder(T->rchild);
}
}

void Inorder(BT *T)
{ if(T)
{ Inorder(T->lchild);
  printf("%3c",T->data);
  Inorder(T->rchild);
}
}

void Postorder(BT *T)
{ if(T)
{  Postorder(T->lchild);
   Postorder(T->rchild);
   printf("%3c",T->data);
}
}

void Levelorder(BT *T)
{  
	 int i,j;
	 BT *q[100],*P;
	 P=T;
	 if(P!=NULL)
	 {
		 i=1;q[i]=P;j=2;
	 }
	 while(i!=j)
	 {
		 P=q[i];printf("%3c",P->data);
		 if(P->lchild!=NULL)
		 {
			 q[j]=P->lchild;j++;}
		 if(P->rchild!=NULL)
		 {
			 q[j]=P->rchild;j++;
		 }
		 i++;
	 }
}
void Leafnum(BT *T)
{
	if(T)
	{
		if(T->lchild==NULL&&T->rchild==NULL)
			count++;
		    Leafnum(T->lchild);
            Leafnum(T->rchild);
	}
}

void Nodenum(BT *T)
{
	if(T)
	{
		count++;
		Nodenum(T->lchild);
		Nodenum(T->rchild);
	}
}

int TreeDepth(BT *T)
{
	int ldep,rdep;
	if(T==NULL)
		return 0;
	else
	{ldep=TreeDepth(T->lchild);
	 rdep=TreeDepth(T->rchild);
	 if(ldep>rdep)
		 return ldep+1;
	 else
		 return rdep+1;
	}
}

void ShowTree(BT *T)
{
	BT *stack[MAXLEN],*p;
	int level[MAXLEN][2],top,n,i,width=4;
	if(T!=NULL)
	{
		printf("\n\t\t�������İ����ʾ��: \n\t\t");
		top=1;
		stack[top]=T;
		level[top][0]=width;
		while(top>0)
		{
			p=stack[top];
			n=level[top][0];
			for(i=1;i<=n;i++)
				printf(" ");
			printf("%c",p->data);
			for(i=n+1;i<50;i+=2)
				printf("��");
			printf("\n\t\t");
			top--;
			if(p->rchild!=NULL)
			{
				top++;
				stack[top]=p->rchild;
				level[top][0]=n+width;
				level[top][1]=2;
			}
			if(p->lchild!=NULL)
			{
			  top++;
			  stack[top]=p->lchild;
			  level[top][0]=n+width;
			  level[top][1]=1;
		}
	}
}
}
//�ȸ���������ÿ���ڵ����������--�ݹ��㷨 ,pָ��������ĸ��ڵ�
void exchange(BT *p)  
{
	BT * t; 
	if(p!=NULL)
	{
     t=p->lchild;
	 p->lchild=p->rchild;
	 p->rchild=t;
	 exchange(p->lchild);
	 exchange(p->rchild);
	}
	
}

//**********���k���ڵ�******************//

int t=0;

int  knode(BT *p)  //�ȸ�����--�ݹ��㷨 ,pָ��������ĸ��ڵ�
{
	
	if(p!=NULL)
	{
    t++;
	if(t==k){	cout<<p->data<<"Ϊ��"<<k<<"��λ���ϵĽڵ�."<<endl; return 1;  }

	knode(p->lchild);
	knode(p->rchild);
	}
	else
	{
		return 0;
	}
}
