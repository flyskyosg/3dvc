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
     printf("\n\n\t\t\t 二叉树子系统\n");
	 printf("\n\t\t******************************************");
	 printf("\n\t\t*       1----------建二叉树              *");
     printf("\n\t\t*       2----------凹入显出              *");
	 printf("\n\t\t*       3----------先序遍历              *");
     printf("\n\t\t*       4----------中序遍历              *");
     printf("\n\t\t*       5----------后序遍历              *");
     printf("\n\t\t*       6----------层次遍历              *");
     printf("\n\t\t*       7----------求叶个数              *");
     printf("\n\t\t*       8----------求结点数              *");
     printf("\n\t\t*       9----------求树深度              *");
	 printf("\n\t\t*       a---------交换左右子树          *");
	 printf("\n\t\t*       b---------求第k个节点           *");
     printf("\n\t\t*       0----------返　　回              *");
     printf("\n\t\t******************************************");
	 printf("\n\t\t请选择菜单号(0--9):");
	 scanf("%c",&ch2);
	 getchar();
	 printf("\n");
	 switch(ch2)
	 { 
		 case '1':
			 printf("\n\t\t 请输入按先序建立二叉树的结点序列:");
             printf("\n\t\t说明:'0'代表后继结点为空,请逐个输入,按回车输入下一个结点。");
             printf("\n\t\t请输入根结点:");
			 T=CreateBT();
			 printf("\n\t\t二叉树成功建立!\n");break;

case'2':
	ShowTree(T);break;
case'3':
	printf("\n\t\t该二叉树的先序遍历序列为:");
	Preorder(T);break;
case'4':
	printf("\n\t\t该二叉树的中序遍历序列为:");
	Inorder(T);break;
case'5':
	printf("\n\t\t该二叉树的后序遍历序列为:");
    Postorder(T);break;
case'6':
	printf("\n\t\t该二叉树的层次遍历序列为:");break;
case'7':
	count=0;Leafnum(T);
	printf("\n\t\t该二叉树有%d个叶子。\n",count);break;
case'8':
	count=0;Nodenum(T);
    printf("\n\t\t该二叉树总共有%d个结点。\n",count);break;
case'9':
	printf("\n\t\t该数的深度是:%d",TreeDepth(T));break;
case'a':
	cout<<"交换左右子树."<<endl;exchange(T);break;
case'b':
	cout<<"求第k个节点."<<endl;knode(T);break;
case'0':
	ch1='n';break;
default:
	printf("\n\t\t***请注意：输入有误!***");
}
if(ch2!='0')
{ printf("\n\t\t按回车键继续，按任意键返回主菜单！");
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
   printf("\n\t\t请输入%c结点的左子结点:",t->data);
   t->lchild=CreateBT();
   printf("\n\t\t请输入%c结点的右子结点:",t->data);
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
		printf("\n\t\t二叉树的凹入表示法: \n\t\t");
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
				printf("—");
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
//先根遍历交换每个节点的左右子树--递归算法 ,p指向的是树的根节点
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

//**********求第k个节点******************//

int t=0;

int  knode(BT *p)  //先根遍历--递归算法 ,p指向的是树的根节点
{
	
	if(p!=NULL)
	{
    t++;
	if(t==k){	cout<<p->data<<"为第"<<k<<"个位置上的节点."<<endl; return 1;  }

	knode(p->lchild);
	knode(p->rchild);
	}
	else
	{
		return 0;
	}
}
