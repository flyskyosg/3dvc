
#include<iostream.h> 
#include<iostream>           // 图的邻接矩阵存储结构
#define max 50
typedef char datatype;
typedef struct lnode
{

	int number,             //节点要存储自己编号
	    number1,            //存放该条链表的头节点前的数组节点的编号 //这一变量是为了实现后便的最小生成树所作的改造    
	    weight,             //节点存储边的权值
	    flag;               //状态标志位，      //这一变量是为了实现后便的最小生成树所作的改造             
	struct lnode *next;     //指向下一个节点
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

void creatgraph0(G & l)  //创建图
{
	int i=0,j=0,b=0,t=0,w=0;lnode * p,*q;
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
		p->flag=0;p->number1=b;      //这一行是为了实现后便的最小生成树所作的改造
		l.vex[b].first=p;
		
		q=(lnode *)malloc(sizeof(lnode));
        q->number=b;q->weight=w;
		q->next=l.vex[t].first;
		q->flag=0;q->number1=t;
		l.vex[t].first=q;
		
		
	
		
	}
	cout<<"建立邻接无向表完毕."<<endl;
}


void disp(G  l)      //输出图
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



//*******************************最小生成树（prime算法）*********************************//

typedef struct mintree         //定义最小生成树
{
	int n,e;
	node  vex[max];            //节点数组
}MT;
//***********************//
int visited[max];                     //存放已经找过的节点的序号 


void Exchange(G t,MT & l)             //该函数将邻接表转存入最小生成的存储中，分别将节点数组对应存入最小生成树的节点数组，在根据节点的单链表一次建议l的边，
{
	int i=0,j=0;lnode *p=NULL;        //i,j作为循环变量，p作为循环指针，
	for(i;i<t.n;i++)
	{
		l.vex[i].inf=t.vex[i].inf;
		l.vex[i].number=t.vex[i].number;
        l.vex[i].first=NULL;          //这里注意事先把最小生成树的节点集的first域置为空。
		
	
	}
	l.n=t.n;l.e=t.e;
}



void neibian(G & t)         //此函数根据visited数组将所有已经访问过的节点之间边的状态位置为1
{
	int i;lnode * p;
	for(i=0;i<t.n;i++)      //依次遍历节点数组的每个节点
	{
		p=t.vex[i].first;    
		while(p!=NULL)      //遍历每个数组节点后的单链表根据根据visited中的值将遍历过的节点之间的所有的边的状态标记为已经遍历
		{
			if(visited[i]==1&&visited[p->number]==1) //在当前数组节点以及单链表中的节点都已经被访问过的情况下，将改边的状态位标记为1，已经找过
				p->flag=1;
			p=p->next;
		}
		    	
		
	}
}


  
void px(lnode * p[])         //对存放访问过的所有节点到所有没有访问过的节点的边的数组依据边的权值进行排序，由大到晓排序
{
	int i=0;
	lnode * r=NULL;
	if(p[i]!=NULL)
	{
		while(p[i+1]!=NULL)
		{
		   if(p[i]->weight<p[i+1]->weight) //根据数组中地址所指向的边的权值进行排序
		   {
			r=p[i];
			p[i]=p[i+1];
			p[i+1]=r;
			
		   }
		   i++;
		}
	}

}




void MinTree(MT & l,G & t)       //生成最小生成树
{
	Exchange(t,l) ;   //将最小生成树的节点数组的节点域初始化为图的节点域
	int i,j;    //循环变量
    lnode * p,* q;  //临时指针	

	for(i=0;i<max;i++)             //初始化标记数组
		visited[i]=0;
	    visited[0]=1;              //事先将0号节点标记为访问过，从0号节点开始



	for(i=0;i<l.n-1;i++)           //这层循环表示要找到n-1条边
	{
		neibian(t);
     	int  k=0;                  //k为minb数组变量参数。
     	lnode * minb[max];         //存放每个访问过的节点到其他未访问过的节点之间的最小边的地址
        for(j=0;j<max;j++)
			minb[j]=NULL;          //初始化该数组


		for(j=0;j<l.n;j++)         //这层循环表示要从所有的访问过的节点中找出到所有未被访问过的节点之间的最小边。每次都依据visited数组找
		{
           

			if(visited[j]==1)      //在该节点背访问过的前提下
			{
			          
				p=t.vex[j].first;  //p从该节点的单链表域的第一个节点开始
			
		        while(p!=NULL)   
				{
					if(p->flag==0) //依次将该节点的单链表中没有被访问的边的地址存入ninb数组，
					{
						minb[k]=p;  
						k++;
					}
					p=p->next;
				}
			}

		}
		px(minb);             //对得到的每个访问过的节点到其他未访问过的节点之间的所有的边依据权值进行排序
		q=minb[k-1];          //这里要注意k要减1;
		q->flag=1;visited[q->number]=1; //当该边背访问过以后要把该边的标记位标记为1；而且把新存入访问过节点集合的新节点也要标记为已访问
		lnode * x=(lnode *)malloc(sizeof(lnode));  //然后将得到的该边挂入最小生成树中
		x->weight=q->weight;            //下边的操作是把得到的边挂载在最小生成树的节点数组的相应的单链表上
		x->number=q->number;
		x->next=l.vex[q->number1].first; //这里采用头插法
		l.vex[q->number1].first=x;
	}
}

void disp(MT  l)          //将得到的最小生成树输出
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
	MT l0;G l1;
	cout<<"创建图:"<<endl;
	creatgraph0( l1);
	cout<<"创建的图:"<<endl;
	disp(l1);
	cout<<"创建最小生成树:"<<endl;
	MinTree(l0,l1) ;
	cout<<"最小生成树:"<<endl;
	disp(l0);

}

           


		
		


	


				





				







   
	 
































