//��Դ���·����һ���㵽�������е�����·��





#include<iostream.h>           // ͼ���ڽӾ���洢�ṹ
#include<iomanip.h>
#define max 50
#define mweight 50           //��Ϊ���Ȩֵʹ�ã��������ڵ�֮��û�бߵ�ʱ�򣬽��ߵ�Ȩֵ����Ϊmweight�������㷨��ʵ��
typedef char datatype;
typedef struct node 
{
	int number;                //�ڵ�Ҫ�洢���ż�����
	datatype inf;
}node;
typedef struct graph
{
	int n,e;
	node vex[max];             //�洢�ڵ����Ϣ
	int edge[max][max];        //�洢�ߵ���Ϣ
}G;

void creatgraph(G & l)
{
	int i=0,j=0,b=0,t=0,w=0;
	cout<<"����ͼ�Ķ����������:";
	cin>>l.n>>l.e;
	cout<<"��ͼ��"<<l.n<<"������"<<l.e<<"����"<<endl;
	for(;i<l.n;i++)
	{
		cout<<"�������"<<i<<"���ڵ����Ϣ,�������_�ڵ�����:";
		cin>>l.vex[i].number>>l.vex[i].inf;
	}
	for(i=0;i<l.n;i++)
		for(j=0;j<l.n;j++)
			l.edge[i][j]=mweight;

    for(j=0;j<l.e;j++)
	{
		cout<<"����ߵ���Ϣ,������_�յ�_Ȩֵ:";
		cin>>b>>t>>w;
        
		if(b<0||b>=l.n) cout<<"��㲻��������Χ��."<<endl;
        
		if(t<0||t>=l.n) cout<<"�յ㲻��������Χ��."<<endl;

		l.edge[b][t]=w;
	}
	cout<<"�����������."<<endl;
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


//************���·��********************//
void shortroad(G & l,int b)
{
	int i=0,j=0;                            
	int dist[max],       //���ԭ�㵽��ǰ�ڵ�����·��
		s[max],          //��¼�Ѿ����ʹ��Ľڵ�
		path[max];       //��ŵ�ǰ�ڵ��ǰһ�����·���Ľڵ�      
	for(i;i<l.n;i++)     //��ʼ����������

	{
		s[i]=0;
		dist[i]=l.edge[b][i];
		if(l.edge[b][i]<mweight) path[i]=b;
		else path[i]=-1;
	}

	s[b]=1;path[b]=0;           //��ԭ����Ϊ�Ѿ����ʹ�����ԭ���ǰһ�����ʹ��Ľڵ�����Ϊ0��ԭ��û��ǰһ���ڵ㣩

	for(i=0;i<l.n;i++)          //��ѭ��������ѭ���ҵ���ԭ�㵽ÿ���յ�����·�� 
	{
		int mindist=mweight,u=-1;         //������������ÿ��ѭ�����г�ʼ��
		for(j=0;j<l.n;j++)                //�ҵ�����һ�����·��
		{
			if(s[j]==0&&dist[j]<mindist)  //�ýڵ�û�б����ʹ����һ������к�ͷԴ�ڵ�֮�����·��
			{
				mindist=dist[j];
				u=j;
			
			}
		}
		if(u!=-1)
		{
			s[u]=1;                        //���õ��Ľڵ�ı�־λ��Ϊ1��
			for(j=0;j<l.n;j++)             //��ѭ�������к��ҵ��ĸ���̽ڵ��бߵĽڵ��dist���е���
			{
				if(s[j]==0&&l.edge[u][j]<mweight&&(dist[u]+l.edge[u][j])<dist[j])
				{
					dist[j]=dist[u]+l.edge[u][j];
					path[j]=u;             //���ѵõ���ǰ�ڵ�u��Ϊ���ڽӽڵ��ǰһ�����·���ڵ�
				}

			}
		}
	}
	int pre=0;int st[max],top=-1;;
	for(i=0;i<l.n;i++)                     //����ڵ�����·�������Լ�·���ϵĽڵ�
	{
		if(s[i]==1&&i!=b)
		{
			cout<<" "<<b<<"->"<<i<<"�����·��������:"<<dist[i];
			cout<<" "<<b<<"->"<<i<<"�����·����:";
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
			cout<<" "<<b<<"->"<<i<<"���·��������."<<endl;
	}
		
}

void main()
{
	G l;
	cout<<"�봴������ͼ:"<<endl;
	creatgraph(l);
	cout<<"����������ͼ:"<<endl;
	disp(l);
	cout<<"���·��:"<<endl;
	shortroad(l,0);
}






