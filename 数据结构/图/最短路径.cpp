//单源最短路径，一个点到其他所有点的最短路径





#include<iostream.h>           // 图的邻接矩阵存储结构
#include<iomanip.h>
#define max 50
#define mweight 50           //作为最大权值使用，当两个节点之间没有边的时候，将边得权值设置为mweight，方便算法的实现
typedef char datatype;
typedef struct node 
{
	int number;                //节点要存储其编号及内容
	datatype inf;
}node;
typedef struct graph
{
	int n,e;
	node vex[max];             //存储节点的信息
	int edge[max][max];        //存储边的信息
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
			l.edge[i][j]=mweight;

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
	cout<<" ";
	for(i=0;i<l.n;i++)
		cout<<setw(3)<<i;
	cout<<endl;
	for(i=0;i<l.n;i++)
	{
		cout<<i;
		for(j=0;j<l.n;j++)
		{
		    if(l.edge[i][j]==50) cout<<setw(3)<<0;
			else
		    cout<<setw(3)<<l.edge[i][j];
		   
		}
		cout<<endl;
	}
}


//************最短路径********************//
void shortroad(G & l,int b)
{
	int i=0,j=0;                            
	int dist[max],       //存放原点到当前节点的最短路径
		s[max],          //记录已经访问过的节点
		path[max];       //存放当前节点的前一个最短路径的节点      
	for(i;i<l.n;i++)     //初始化三个数组

	{
		s[i]=0;
		dist[i]=l.edge[b][i];
		if(l.edge[b][i]<mweight) path[i]=b;
		else path[i]=-1;
	}

	s[b]=1;path[b]=0;           //将原点标记为已经访问过，将原点的前一个访问过的节点设置为0（原点没有前一个节点）

	for(i=0;i<l.n;i++)          //大循环，控制循环找到从原点到每个终点的最短路径 
	{
		int mindist=mweight,u=-1;         //这里两个变量每次循环进行初始化
		for(j=0;j<l.n;j++)                //找到其中一个最短路径
		{
			if(s[j]==0&&dist[j]<mindist)  //该节点没有被访问过而且还必须有和头源节点之间存在路径
			{
				mindist=dist[j];
				u=j;
			
			}
		}
		if(u!=-1)
		{
			s[u]=1;                        //将得到的节点的标志位置为1；
			for(j=0;j<l.n;j++)             //做循环把所有和找到的该最短节点有边的节点的dist进行调整
			{
				if(s[j]==0&&l.edge[u][j]<mweight&&(dist[u]+l.edge[u][j])<dist[j])
				{
					dist[j]=dist[u]+l.edge[u][j];
					path[j]=u;             //并把得到当前节点u作为其邻接节点的前一个最短路径节点
				}

			}
		}
	}
	int pre=0;int st[max],top=-1;;
	for(i=0;i<l.n;i++)                     //输出节点的最短路径长度以及路径上的节点
	{
		if(s[i]==1&&i!=b)
		{
			cout<<" "<<b<<"->"<<i<<"的最短路径长度是:"<<dist[i];
			cout<<" "<<b<<"->"<<i<<"的最短路径是:";
            pre=i;
			while(pre!=b)
			{
				top++;st[top]=pre;
				pre=path[pre];
			}
			top++;st[top]=b;
			for(top;top>=0;top--)
				cout<<setw(3)<<st[top];
			cout<<endl;
		
		}
		else
			cout<<" "<<b<<"->"<<i<<"最短路径不存在."<<endl;
	}
		
}

void main()
{
	G l;
	cout<<"请创建有向图:"<<endl;
	creatgraph(l);
	cout<<"创建的有向图:"<<endl;
	disp(l);
	cout<<"最短路径:"<<endl;
	shortroad(l,0);
}






