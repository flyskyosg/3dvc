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
		{
			if(l.edge[i][j]!=0)
			cout<<" "<<l.edge[i][j];
		}
		cout<<endl;
	}
}



//*******************最小生成树（克鲁斯卡尔算法）***********************//

typedef struct edge
{
	int number0, //头节点
		number1, //尾节点
		weight;  //权值
}edge;

edge l[max];        //存放边的信息
int visited[max];   //存储对应节点所在的连通分量的编号

void px(int n) //对存放边的数组按照由小到大进行排序 ,n为边的个数
{
	edge t;int i=0,j=0;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(l[j].weight>l[j+1].weight)   
			{
				t=l[j];
				l[j]=l[j+1];
				l[j+1]=t;
			}
		}
}

void exchange(G & t,G & mt) //该函数有两个作用，一个是用存在的图的节点数组初始化最小生成树的节点数组（这里用邻接矩阵存储最小生成树）
{                           //令一个是把图的边数组转存入l[max]数组，方便后便的排序以及查找使用
	int i=0,j=0,k=0;        //循环变量
	for(i=0;i<t.n;i++)
	{
		mt.vex[i]=t.vex[i]; //用存在的图的节点数组初始化最小生成树的节点数组（这里用邻接矩阵存储最小生成树）

		for(j=0;j<t.n;j++)
		{

			if(t.edge[i][j]!=0)  //查到该边后存入l[max]
			{
				l[k].number0=i;
				l[k].number1=j;
				l[k].weight=t.edge[i][j];
				k++;
			}
		
		}
	}
}




void mintree(G & t ,G & mt)
{
    
	exchange(t,mt);              
	px(t.n);
	for(int i=0;i<t.n;i++)	  //出示化visited数组，每个节点所在的连通分量序号初始化为本节点的序号，访问后将对应的visited数组的对应位置置为-1；表示他们同处于-1序号的连通分量内
	   visited[i]=i;
	
	int j=0,k=0;              //循环变量
   	
	for(i=0;i<t.n;i++)        //初始化mt的边数组，全部置为0;
	for(j=0;j<t.n;j++)
 	 mt.edge[i][j]=0;

    j=0;   //这里注意要把j初始化为0；作为下边的循环标记位 



	while(j!=t.n-1)           //这里在j=n-1的时候终止循环，表示要找到n-1条边，那个定点的图的最小生成树有n-1个边
	{
		if(visited[l[k].number0]!=visited[l[k].number1])        //在该边的两个节点不再同一个连通分量中的时候将改变存入mt的边数组。
		{
			mt.edge[l[k].number0][l[k].number1]=l[k].weight;    //存入mt的边数组
			j++;
			visited[l[k].number0]=-1;visited[l[k].number1]=-1;  //这里要注意存入便后要把边的两个节点的对应的连通分量状态位置为-1；
		}
		k++;   //然后一次向后判断边，知道j达到n-1；
	}
	mt.n=t.n;  //最后要把对应的节点数目初始化


	


}
//**************************************//


void main()
{
	G t,l;
	cout<<"创建图:"<<endl;
	creatgraph(t);
	cout<<"创建后的图:"<<endl;
	disp(t);
	cout<<"创建最小生成树:"<<endl;
	mintree(t,l);
	cout<<"最小生成树:"<<endl;
	disp(l);
}






