
#include<iostream.h>            // ͼ���ڽӾ���洢�ṹ
#define max 50
typedef char datatype;
typedef struct node 
{
	int number;             //�ڵ�Ҫ�洢���ż�����
	datatype inf;
}node;
typedef struct graph
{
	int n,e;
	node vex[max];         //�洢�ڵ����Ϣ
	int edge[max][max];      //�洢�ߵ���Ϣ

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
			l.edge[i][j]=0;

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


void disp(G  l)           //��������õ�ͼ���ڽӾ���
{
	int i=0,j=0;
	for(i;i<l.n;i++)
	{
		for(j=0;j<l.n;j++)
			cout<<" "<<l.edge[i][j];
		cout<<endl;
	}
}

//**********************����*************************//
int visited[max];  //ȫ�����飬������Ÿ����ڵ�ı�ǣ���ǽڵ��Ƿ񱻷��ʹ���

void DFS(G  t,int i)  //�ݹ麯��
{
	cout<<t.vex[i].inf<<" ";         //���Ƚ��ڵ��������
	visited[i]=1;                    //�ڵ�����󽫶�Ӧ��visited����Ķ�Ӧ���Ϊ����Ϊ1;
	for(int j=0;j<t.n;j++)
		if(t.edge[i][j]!=0&&visited[j]==0) DFS(t,j);  //�ڽڵ�����ڽӵ㲢�Ҹ��ڽӵ�û�б����ʹ�������´��¸ýڵ㿪ʼ��
}
void DFSthread(G  t)
{
	for(int i=0;i<t.n;i++)  //��ʼ��������飬ȫ������Ϊ0��δ�����ʡ�
		visited[i]=0;
	for(int j=0;j<t.n;j++)  //Ϊ�˱�֤��ͨͼ�ͷ���ͨͼ�е�ÿ���ڵ㶼���ʵ��������ÿ���ڵ㶼��Ϊ��ʼ��һ�ο�ʼ���ʡ�
	{
		if(visited[j]==0) DFS(t,j);   //�ڸýڵ�δ�����ʵ�����¶Ըýڵ����

	}
}





void main()
{
	G l;
	cout<<"����ͼ:"<<endl;
	creatgraph(l);
	cout<<"���ͼ:"<<endl;
	disp(l);
	cout<<"����ͼ:";
	DFSthread(l);

}






