#include<iostream.h> 
#include<iostream>          // 图的邻接矩阵存储结构
#define max 50
#define mweight 50
typedef char datatype;
typedef struct lnode
{
	int number,             //节点要存储其编号
	    weight,             //节点存储边的权值
	    ve,                 //边的最早发生时间 
		vl;                 //边的最晚发生时间 
	struct lnode *next;     //指向下一个节点
}lnode;

typedef struct node 
{
	int   number;           //节点要存储其编号
	datatype inf;           //节点信息
	int count,              //节点的入度； 
	    ve,                 //节点的最早发生时间
		vl;                 //节点的最晚发生时间
	lnode *first;           //指向节点的邻接点
}node;
typedef struct graph        //定义图
{
	int n,e;                //图的节点数与边数
	node vex[max];          //存储节点的信息以及序号,first
	
}G;

//************************创建图*************************//

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
		l.vex[i].ve=0;                         //把所有节点的初始最早发生时间设置为0，方便后边比较取最长路径算法实现
		l.vex[i].vl=mweight;                    //把所有节点的初始最晚发生时间设置为weight,f方便后便的比较取最短路径算法的实现
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
//************************AOE网的关键路径***************************//


  
void keyroad(G & l)
{

	//*************先处理节点的最早发生时间以及所关联的边的最早发生时间
    int visited[max],                   //状态数组，记录已经访问过的节点，访问过后全部位置为1;
	    st[max],                        //存放入度为0的节点的栈
	    top=-1;  
   	for(int i=0;i<l.n;i++)              //初始化状态数组
		visited[i]=0;
	for( i=0;i<l.n;i++)                 //事先将入度为0的节点入栈，方便后边的循环
	{
		if(l.vex[i].count==0&& visited[i]==0)
		{
			top++;
			st[top]=i;
			visited[i]=1;
			break;                      //因为AOE网络中如度为0以及初度为0的点只有一个，所以一旦找到就可以停止循环
		}
	}
	l.vex[i].ve=0;l.vex[i].vl=0;        //原点的最早发生时间和最晚发生时间必定为0


	lnode * p=NULL;
	int n=0,j=-1,                       //作为存储节点的临时变量
	    order[max];                     //记录拓扑排序的顺序输出序列.方便后边的最晚发生时间的处理，全局数组 000000000000       
	while(top>=0)                       //这层循环控制当站空的时候终止大循环，说明所有的元素处理完毕
	{
		while(top>=0)                   //控制将栈内的入度为零的节点输出并且将入度为零的节点的所有的直接后即节点的入度减一
		{
			
			n=st[top];
			j++;
			order[j]=n;                 //记录拓扑排序的顺序输出序列
			p=l.vex[n].first;
			visited[n]=1;               //标记已经访问过的节点 
				
		          
			while(p!=NULL)              //将该节点的所有的邻接点的入度减1,
			{
				l.vex[p->number].count--;
				if(l.vex[n].ve+p->weight>l.vex[p->number].ve) l.vex[p->number].ve=l.vex[n].ve+p->weight; //关键，依次改写该节点的最早发生时间，最后从所有邻接路径中取的最大路径
				p=p->next;
			}
			top--;                      //当top<0的时候，出栈完毕
		}

		for( i=0;i<l.n;i++)             //再次扫描入度为0的节点;并且入栈
		{
		    if(l.vex[i].count==0&&visited[i]==0)
			{
			
				top++;
			    st[top]=i;
			
			}
		}
	}

//************下面处理节点的最晚发生时间，    利用拓扑排序的顺序输出的的逆序作为条件
 l.vex[order[j]].vl=l.vex[order[j]].ve;       //汇点的最早发生时间和最晚发生时间相同 
 int m=0;                                     //作为存储节点序号的临时变量
 for(j;j>=0;j--)
 {
	 m=order[j];
	 for(i=0;i<l.n;i++)
	 {
		 p=l.vex[i].first;
		 while(p!=NULL)
		 {
			 if(p->number==m&&l.vex[m].vl-p->weight<l.vex[i].vl)        //关键，这里的条件决定了从节点的邻接点边重选出最小路径，依次改写临接点的最小路径，循环完毕后最后从所有的邻接路径中取得小路径
			 {
				 l.vex[i].vl=l.vex[m].vl-p->weight;                   
			 }
			 p=p->next;
		 }
	 }
 }


//******************下边处理边的最早以及最晚发生时间**************//
 for(i=0;i<l.n;i++)
 {
	 p=l.vex[i].first;
	 while(p!=NULL)
	 {
		 p->ve=l.vex[i].ve;
		 p->vl=l.vex[p->number].vl-p->weight;
		 if(p->ve==p->vl) cout<<i<<"->"<<p->number<<"关键活动"<<endl;
		 p=p->next;
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
	cout<<"AOE关键路径:"<<endl;
	keyroad(l);
	cout<<endl;
}






