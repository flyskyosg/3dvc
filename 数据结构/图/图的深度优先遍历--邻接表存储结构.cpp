#include<iostream.h> 
#include<iostream>           // 图的邻接矩阵存储结构
#define max 50
typedef char datatype;
typedef struct lnode
{
	int number;             //节点要存储其编号
	int weight;             //节点存储边的权值
	struct lnode *next;      //指向下一个节点
}lnode;

typedef struct node 
{
	int   number;           //节点要存储其编号
	datatype inf;           //节点信息         
	lnode *first;           //指向节点的邻接点
}node;
typedef struct graph        //定义图
{
	int n,e;                //图的节点数与边数
	node vex[max];          //存储节点的信息以及序号，first
	
}G;

void creatgraph0(G & l)
{
	int i=0,j=0,b=0,t=0,w=0;lnode * p,* q;
	cout<<"输入图的顶点数与边数:";
	cin>>l.n>>l.e;
	cout<<"该图有"<<l.n<<"个顶点"<<l.e<<"条边"<<endl;
	for(;i<l.n;i++)
	{
		cout<<"请输入第"<<i<<"个节点的信息,输入序号_节点内容:";
		cin>>l.vex[i].number>>l.vex[i].inf;
		l.vex[i].first=NULL;
	}
	

    for(j=0;j<l.e;j++)
	{
		cout<<"输入边的信息,起点序号_终点_权值:";
		cin>>b>>t>>w;
        
		if(b<0||b>=l.n) cout<<"起点不在搜索范围内."<<endl;
        
		if(t<0||t>=l.n) cout<<"终点不在搜索范围内."<<endl;
        
		p=(lnode *)malloc(sizeof(lnode));
        p->number=t;p->weight=w;
		p->next=l.vex[b].first;
		l.vex[b].first=p;
		
		q=(lnode *)malloc(sizeof(lnode));
        q->number=b;q->weight=w;
		q->next=l.vex[t].first;
		l.vex[t].first=q;
		
		
	}
	cout<<"建立邻接无向表完毕."<<endl;
}

void creatgraph1(G & l)
{
	int i=0,j=0,b=0,t=0,w=0;lnode * p;
	cout<<"输入图的顶点数与边数:";
	cin>>l.n>>l.e;
	cout<<"该图有"<<l.n<<"个顶点"<<l.e<<"条边"<<endl;
	for(;i<l.n;i++)
	{
		cout<<"请输入第"<<i<<"个节点的信息,输入序号_节点内容:";
		cin>>l.vex[i].number>>l.vex[i].inf;
		l.vex[i].first=NULL;
	}
	

    for(j=0;j<l.e;j++)
	{
		cout<<"输入边的信息,起点序号_终点_权值:";
		cin>>b>>t>>w;
        
		if(b<0||b>=l.n) cout<<"起点不在搜索范围内."<<endl;
        
		if(t<0||t>=l.n) cout<<"终点不在搜索范围内."<<endl;
        p=(lnode *)malloc(sizeof(lnode));
        p->number=t;p->weight=w;
		p->next=l.vex[b].first;
		l.vex[b].first=p;
		
		
		
	}
	cout<<"建立有向邻接表完毕."<<endl;
}
void disp(G  l)
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


//**********************遍历*************************//
int visited[max];  //全局数组，用来存放各个节点的标记，标记节点是否被访问过，

void DFS(G  t,int i)  //递归函数
{
	lnode * p=NULL;
	cout<<t.vex[i].inf<<" ";         //首先将节点内容输出
	visited[i]=1;                      //节点输出后将对应的visited数组的对应标记为设置为1;
	p=t.vex[i].first;                          
    while(p!=NULL) 
	{
		if(visited[p->number]==0) DFS(t,p->number);
		p=p->next;
	}
}
void DFSthread(G  t)
{
	for(int i=0;i<t.n;i++)  //初始化标记数组，全部设置为0；未被访问。
		visited[i]=0;
	for(int j=0;j<t.n;j++)  //为了保证连通图和非连通图中的每个节点都访问到，这里把每个节点都做为起始点一次开始访问。
	{
		if(visited[j]==0) DFS(t,j);   //在该节点未被访问的情况下对该节点遍历

	}
}





//************************主函数*********************//

void main()
{
	G l0,l1;
	cout<<"创建无向图:"<<endl;
	creatgraph0(l0);
	disp(l0);
	cout<<"创建有向图:"<<endl;
	creatgraph1(l1);
	disp(l1);
	cout<<"遍历无向邻接表:";
	DFSthread(l0);
	cout<<endl;
	cout<<"遍历有向邻接表:";
	DFSthread(l1);
	cout<<endl;
}






