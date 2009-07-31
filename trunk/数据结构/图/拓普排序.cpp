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
	int count;              //节点的入度；                                  
	lnode *first;           //指向节点的邻接点
}node;
typedef struct graph        //定义图
{
	int n,e;                //图的节点数与边数
	node vex[max];          //存储节点的信息以及序号，first
	
}G;



void creatgraph(G & l)
{
	int i=0,j=0,b=0,t=0,w=0;lnode * p;
	cout<<"输入图的顶点数与边数:";
	cin>>l.n>>l.e;
	cout<<"该图有"<<l.n<<"个顶点"<<l.e<<"条边"<<endl;
	for(;i<l.n;i++)
	{
		cout<<"请输入第"<<i<<"个节点的信息,输入序号_节点内容_节点入度:";
		cin>>l.vex[i].number>>l.vex[i].inf>>l.vex[i].count;
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
	
    cout<<"输出格式:"<<"节点序号_节点信息_节点入度+邻接点序号_该边的权值+........."<<endl;
	for(i;i<l.n;i++)
	{
		
		cout<<l.vex[i].number<<" "<<l.vex[i].inf<<" "<<l.vex[i].count<<"  ";
		p=l.vex[i].first;
		while(p!=NULL)
		{
			cout<<p->number<<" "<<p->weight<<"  ";
			p=p->next;
		}
		cout<<endl;
	
	}
}
//************************AOV网的拓扑排序***************************//


  
void tuopu(G & l)
{
    int visited[max];                   //状态数组，记录已经访问过的节点，访问过后全部位置为1； 
	int st[max];                        //存放入度为0的节点的栈
	int top=-1;  
    
	for(int i=0;i<l.n;i++)              //初始化状态数组
		visited[i]=0;
	for( i=0;i<l.n;i++)              //事先将入度为0的节点入栈，方便后便的循环
	{
		if(l.vex[i].count==0&& visited[i]==0)
		{
			top++;
			st[top]=i;
			visited[i]=1;
		}
	}

	lnode * p=NULL;int n;
	while(top>=0)                       //这层循环控制当站空的时候终止大循环，说明所有的元素处理完毕
	{
		while(top>=0)                   //控制将栈内的入度为零的节点输出并且将入度为零的节点的所有的直接后即节点的入度减一
		{
			
			n=st[top];                  
			cout<<l.vex[n].inf<<" ";    //输出节点
		
			p=l.vex[n].first;           
			while(p!=NULL)              //将该节点的所有的邻接点的入度减1
			{
				l.vex[p->number].count--;
				p=p->next;
			}
			top--;                      //当top<0的时候，出栈完毕
		}

		for( i=0;i<l.n;i++)             //再次扫描入度为0的节点，并且入栈
		{
		    if(l.vex[i].count==0&&visited[i]==0)
			{
			top++;
			st[top]=i;
			visited[i]=1;
			}
		}
	}
}



//******************主函数******************//
			
void main()
{
	G l;
	cout<<"创建图:"<<endl;
	creatgraph(l);
	cout<<"创建好的图:"<<endl;
	disp(l);
	cout<<"拓扑排序:";
	tuopu(l);
	cout<<endl;
}






