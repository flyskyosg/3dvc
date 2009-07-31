#include<iostream.h>            // 图的邻接矩阵存储结构
#define max 50
typedef char datatype;
typedef struct node 
{
	int number;             //节点要存储其编号及内容
	datatype inf;
}node;
typedef struct graph
{
	int n,e;
	node vex[max];         //存储节点的信息
	int edge[max][max];      //存储边的信息
}G;

void creatgraph(G & l)
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


void disp(G  l)
{
	int i=0,j=0;
	for(i;i<l.n;i++)
	{
		for(j=0;j<l.n;j++)
			cout<<" "<<l.edge[i][j];
		cout<<endl;
	}
}


void main()
{
	G l;
	creatgraph(l);
	disp(l);
}






