
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



void WFSthread(G  t) //广度优先遍历
{
	int i=0,j=0,k=0,f=-1,r=-1;//i,j,k分别用做循环变量，f,r作为顺序队列的对头与队尾。
	int visited[max];    //全局数组，用来存放各个节点的标记，标记节点是否被访问过，
    int qu[max+1];     //顺序队列


	for( i=0;i<t.n;i++)  //初始化标记数组，全部设置为0；未被访问。
		visited[i]=0;
    
    
	for( i=0;i<t.n;i++)  //为了保证连通图和非连通图中的每个节点都访问到，这里把每个节点都做为起始点一次开始访问。
	{
		if(visited[i]==0)    //每个节点开始遍历的时候先检查是否遍历过，在没有遍历过的情况下从该节点开始依次遍历
		{
		  r++;
	      qu[r]=t.vex[0].number;        //事先将第一个节点入队，为后便的循环做准备，
		  while(r!=f)       //在队不空的条件下进行循环，
		  {
			  f++;
			  j=qu[f];
			  cout<<t.vex[j].inf<<" ";      //先将队头节点出对，然后判断节点是否还有 邻接节点，，如果有
			  visited[j]=1;
			
		      for(k=0;k<t.n;k++)         //用该循环将所有的为访问的邻接入队。
			  {
				  if(visited[k]==0&&t.edge[j][k]!=0) //这里要注意，因为邻接矩阵存储的是边的权值，所以这里应该为！=0为判断条件。
				  {
					  r++;
					  qu[r]=k;
					 
				  }
				  
			  }
		  }
		}
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
	WFSthread(l);

}






