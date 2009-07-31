#define max 50
#include<iostream>
#include<iostream.h>
#include<string.h>
typedef char datatype; 

typedef struct node  //定义节点
{
	datatype data;
	int weight;
	struct node * lch,* rch;
}node;
//***********************************构造叶子数组*************************//
node * st[max];  //全局数组，用于存放所有的叶子节点
int top=-1;      //top为数组的长度，也可做为当前栈顶的指针 

void creatleaf()  //创建叶子节点的数组
{
	node *p=NULL;
	datatype data;
	int weight;
	cout<<"请输入叶子节点的数据及权值(格式:数据+回车 权值+回车),输入$结束操作:"<<endl;
	cin>>data;cin>>weight;
	cout<<data<<" "<<weight<<endl;
	while(data!='$')
	{
		p=(node *)malloc(sizeof(node));
		p->data=data;
		p->weight=weight;
		p->lch=p->rch=NULL;
		top++;
		st[top]=p;
		cout<<"请输入叶子节点的数据及权值(格式:数据+回车 权值+回车),输入$结束操作:"<<endl;
    	cin>>data;cin>>weight;
    	cout<<data<<" "<<weight<<endl;
	}
	for(int i=0;i<=top;i++)
		cout<<st[i]->data<<" "<<st[i]->weight;
	cout<<endl;
	cout<<"创建结束。"<<endl;
}
//***********************排序函数*******************************//
void px()  //对该数组进行排序（由大到小排序）
{
	int i=0,j=0;node * t;static int k=1; //i，j为循环变量，k为静态变量，用来显示状态
	for(;i<top;i++)
		for(j=0;j<top-i;j++)
		{
			if(st[j]->weight<st[j+1]->weight)  //根据权值由达到小排序
			{
				t=st[j];
				st[j]=st[j+1];
				st[j+1]=t;
			}
		}
		cout<<"第"<<k<<"次"<<"排序."<<endl;k++;  //用来查看排序的状态
		for( i=0;i<=top;i++)
		cout<<st[i]->data<<" "<<st[i]->weight;
		cout<<endl;

}
//***********先序遍历*****************//
void preorder(node * p)
{
	if(p!=NULL)
	{
		cout<<p->data<<" ";
		preorder(p->lch);
		preorder(p->rch);
	}
}
//*****************************构造哈夫慢树***********************//
node * creathaff()  //构造哈夫慢树
{
	creatleaf();
    cout<<"构造叶子节点结束."<<endl;
	node * r;
	while(top>=0)    //在数组不空的条件下循环
	{ 
	px();           //将数组由大到小排序
	r=(node *)malloc(sizeof(node)); //将数组的最后两个元素分别挂在当前根节点的左右子树上
	r->data='A';
	r->lch=st[top];
	if(top-1>=0) r->rch=st[top-1];  //这里要注意在top-1>0的时候执行。
	else   break;                  
	
	r->weight=st[top]->weight+st[top-1]->weight;//将左右子树的权重和存在新的根节点中
	if(top-2<0) break;    //如果当前的数组里只剩下两个元素，做好节点后直接退出，不用再将做好的新节点入数组

	top--;                //将数组的长度减一
	st[top]=r;             //将新做好的节点存入数组
	}
	return r;
}


//********************************哈夫慢编码**************************//
//********************//	
int hcode[max];
int len=-1;

void haffcode(node * p)  //哈夫慢编码  ，根据先跟遍历的递归算法改造。
{
	if(p!=NULL)    //在树不空的条件下执行，同时也是递归的出口
	{
		if(p->lch==NULL&&p->rch==NULL)   //当一个节点满足该条件的时候，说明该节点为叶子节点，应该输出其haffcode。
		{
			cout<<p->data<<" ";
			for(int i=0;i<=len;i++)         //数组中存放的数据依次输出就是其haffcode。
				cout<<hcode[i];
			len--;             //这里注意输出编码后，因为是递归的调用，要返回一级，所以要将数组中的元素删除一个，这里表示为把数组的长度减少1           
			cout<<endl;

		}
		if(p->lch!=NULL)       
		{
			len++;hcode[len]=0;        //如果左子树存在，将一个0压入数组，然后进入左子树
			haffcode(p->lch);
		}
		
		
		if(p->rch!=NULL)              
		{
			len++;hcode[len]=1;           //如果右子树存在，将一个1压入数组，然后进入左子树
			haffcode(p->rch);
		}
		if(p->lch!=NULL||p->rch!=NULL)    //最后要注意，因为递归，当一个节点遍历完毕后要返回上级的时候要将数组长度减1；其实是处理完右子树后减1
			len--;
	}
}


//************************主函数********************//
void main()
{
	node * root;
    cout<<"构造哈夫慢树:"<<endl;
	root=creathaff();
	cout<<"构造的哈夫慢树为:"<<endl;
    preorder(root);
	cout<<"构造的哈夫慢编码为:"<<endl;
	haffcode(root);



}













	













