
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


void disp(G  l)           //输出建立好的图的邻接矩阵
{
	int i=0,j=0;
	for(i;i<l.n;i++)
	{
		for(j=0;j<l.n;j++)
			cout<<" "<<l.edge[i][j];
		cout<<endl;
	}
}

//**********************遍历*************************//
int visited[max];  //全局数组，用来存放各个节点的标记，标记节点是否被访问过，

void DFS(G  t,int i)  //递归函数
{
	cout<<t.vex[i].inf<<" ";         //首先将节点内容输出
	visited[i]=1;                    //节点输出后将对应的visited数组的对应标记为设置为1;
	for(int j=0;j<t.n;j++)
		if(t.edge[i][j]!=0&&visited[j]==0) DFS(t,j);  //在节点存在邻接点并且该邻接点没有被访问过的情况下从新该节点开始遍
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





void main()
{
	G l;
	cout<<"创建图:"<<endl;
	creatgraph(l);
	cout<<"输出图:"<<endl;
	disp(l);
	cout<<"遍历图:";
	DFSthread(l);

}






