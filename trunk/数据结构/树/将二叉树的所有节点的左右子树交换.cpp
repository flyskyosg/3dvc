#include<iostream.h>   //链式存储结构
#include<iostream>
#define max 50 
typedef char datatype;

typedef struct node    //二叉链表的节点
{
	datatype data;
	struct node * lch;
	struct node * rch;
}node;
typedef struct         //二叉链表定义
{
	 struct node * root;
}ltree;


void initltree(ltree & l)   //初始化二叉树
{
	l.root=NULL;
}
//********************************括号法创建二叉树*********************//

void  creattree(ltree & l,datatype  str[])  //括号法建立二叉树
{
	node * p=NULL;  //p用来指向树的节点
	int k=0,j=0,top=-1;  //k作为一个状态标志位,根据前一个元素的值来确定一个元素是左还是右孩子.或者退栈
	node * a[max];    //作为存储双亲节点的顺序栈使用。
	datatype t=str[j];   //t作为暂存数组元素值的中间变量。

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

//*********************凹入法显示二叉树*********************************//
void show(ltree & l) //基本算法是事先入栈根节点，然后循环，判断当前节点的左右子树并入栈，这种如站顺寻实现了凹入法的特点
{
	node * p=l.root,* st[max];        //p为临时存储节点的变量,初始时指向根节点，st为存储节点的栈
	int top=-1,elem[max][2],w=4,n=0;  //top栈顶指针，elem数组存储节点元素的参数，0号为存储节点的类型（根，左子树，右子树）,1号为存储节点之前需要输出的空格的个数。w为事先设定的单位输出宽度，n为保存宽度的临时变量。
	char type='\0';      //type保存输出节点的类型，根据elem数组的0号位来取值位（L-左子树，R-右子树，B-根节点）
	if(p!=NULL)  
	{
		top++;          
		st[top]=p;               //事先将根节点如栈，
		elem[top][0]=2;          //并且在elem数组中相应的位置存入当前节点的信息（类型，输出宽度）
		elem[top][1]=w;
		while(top>-1)            //在栈不空的条件下循环
		{
			p=st[top];           //出栈
			n=elem[top][1];      //这里用n来存储宽度，
			for(int i=1;i<=n;i++) //输出节点前的宽度
				cout<<" ";
			switch(elem[top][0])  //根据0号位确定type的值
			{
			case 0:type='L';break;
			case 1:type='R';break;
            case 2:type='B';break; 
			}
			cout<<p->data<<"("<<type<<")"; //输出元素后的“-”；
			for(i=1;i<=max-n;i++)
				cout<<"-";
			cout<<endl;
			top--;  //出栈
			if(p->rch!=NULL)  //左子树存在入栈，并且在elem存储相应的信息
			{
				top++;
		        st[top]=p->rch;
	            elem[top][0]=1;
		        elem[top][1]=n+w;
			}
			if(p->lch!=NULL) //右子树存在入栈，并且在elem存储相应的信息
			{
				top++;
		        st[top]=p->lch;
	            elem[top][0]=0;
		        elem[top][1]=w+n;
			}
		}
	}
}

//*****************将二茶树的每个节点的左右子树交换*************//

void exchange(node *p)  //先根遍历交换每个节点的左右子树--递归算法 ,p指向的是树的根节点
{
	node * t; 
	if(p!=NULL)
	{
     t=p->lch;
	 p->lch=p->rch;
	 p->rch=t;
	 exchange(p->lch);
	 exchange(p->rch);
	}
	
}

void main()
{
	ltree a;a.root=NULL;
    cout<<"输入数据(树的括号表示法,限100个字符以内)."<<endl;
    datatype p[max];
    cin>>p;
	cout<<p<<endl;
	creattree(a,p);
	cout<<"创建后的二叉树:"<<endl;
    show(a);
    cout<<endl;
    exchange(a.root);
	cout<<"交换后的二叉树:"<<endl;
	show(a);
}


