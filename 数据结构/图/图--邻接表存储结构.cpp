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
	
    cout<<"输出格式:"<<"节点序号_节点信息+邻接点序号_该边的权值+........."<<endl;
	for(i;i<l.n;i++)
	{
		
		cout<<l.vex[i].number<<" "<<l.vex[i].inf<<"  ";
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
	G l;
	creatgraph0(l);
	disp(l);
}






