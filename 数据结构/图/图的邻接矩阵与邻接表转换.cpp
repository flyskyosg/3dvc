#include<iostream.h>  
#include<iostream>          // 图的邻接矩阵存储结构
#define max 50
typedef char datatype;
typedef struct node0 
{
	int number;             //节点要存储其编号及内容
	datatype inf;
}node0;
typedef struct graph0
{
	int n,e;
	node0 vex[max];         //存储节点的信息
	int edge[max][max];      //存储边的信息
}G0;

//邻接表节点

typedef struct lnode
{
	int number;             //节点要存储其编号
	int weight;             //节点存储边的权值
	struct lnode *next;      //指向下一个节点
}lnode;

typedef struct node1 
{
	int   number;           //节点要存储其编号
	datatype inf;           //节点信息         
	lnode *first;           //指向节点的邻接点
}node1;
typedef struct graph1        //定义图
{
	int n,e;                //图的节点数与边数
	node1 vex[max];          //存储节点的信息以及序号，first
	
}G1;






void creatgraph0(G0 & l)       //建立邻接矩阵
{
	int i=0,j=0,b=0,t=0,w=0;
	cout<<"收入图的顶点数与边数:";
	cin>>l.n>>l.e;
	cout<<"该图有"<<l.n<<"个顶点"<<l.e<<"条边"<<endl;
	for(;i<l.n;i++)
	{
		cout<<"请输入第"<<i<<"个节点的信息,输入序号_节点内容:";
		cin>>l.vex[i].number>>l.vex[i].inf;
	}
	for(i=0;i<l.n;i++)
		for(j=0;j<l.n;j++)
			l.edge[i][j]=0;

    for(j=0;j<l.e;j++)
	{
		cout<<"输入边的信息,起点序号_终点_权值:";
		cin>>b>>t>>w;
        
		if(b<0||b>=l.n) cout<<"起点不在搜索范围内."<<endl;
        
		if(t<0||t>=l.n) cout<<"终点不在搜索范围内."<<endl;

		l.edge[b][t]=w;
	}
	cout<<"建立矩阵完毕."<<endl;
}



void creatgraph1(G1 & l1,G0 & l0) //建立无向邻接表
{
	int i=0,j=0,t=0;lnode * p;
	

		for(i;i<l0.n;i++)
		{
			l1.vex[i].inf=l0.vex[i].inf;
			l1.vex[i].number=l0.vex[i].number;
			l1.vex[i].first=NULL;
			
		}
		l1.n=l0.n;
		l1.e=l0.e;		
	   for(i=0;i<l0.n;i++)
		   for(j=0;j<l0.n;j++)
		   {
			   t=l0.edge[i][j];
			   if(t!=0)
			   {
				   p=(lnode *)malloc(sizeof(lnode));
                   p->number=j;p->weight=t;
		           p->next=l1.vex[i].first;
		           l1.vex[i].first=p;
			   }
		   }
		   cout<<"建立邻接表完毕."<<endl;
}
		
		          
		    
	
	
   
	
void disp(G0  l)
{
	int i=0,j=0;
	for(i;i<l.n;i++)
	{
		for(j=0;j<l.n;j++)
			cout<<" "<<l.edge[i][j];
		cout<<endl;
	}
}




void disp(G1  l)
{
	int i=0;lnode * p;
	
    
	for(i;i<l.n;i++)
	{
		
		cout<<l.vex[i].inf<<" "<<l.vex[i].number<<"  ";
		p=l.vex[i].first;
		while(p!=NULL)
		{
			cout<<p->number<<" "<<p->weight<<"  ";
			p=p->next;
		}
		cout<<endl;
	
	}
}


void main()
{
	G0 l0;G1 l1;
	creatgraph0(l0);
	cout<<"邻接矩阵:"<<endl;
	disp(l0);
	cout<<"转换成邻接表:"<<endl;
	creatgraph1(l1,l0);
	disp(l1);
}
















