
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



void WFSthread(G  t) //������ȱ���
{
	int i=0,j=0,k=0,f=-1,r=-1;//i,j,k�ֱ�����ѭ��������f,r��Ϊ˳����еĶ�ͷ���β��
	int visited[max];    //ȫ�����飬������Ÿ����ڵ�ı�ǣ���ǽڵ��Ƿ񱻷��ʹ���
    int qu[max+1];     //˳�����


	for( i=0;i<t.n;i++)  //��ʼ��������飬ȫ������Ϊ0��δ�����ʡ�
		visited[i]=0;
    
    
	for( i=0;i<t.n;i++)  //Ϊ�˱�֤��ͨͼ�ͷ���ͨͼ�е�ÿ���ڵ㶼���ʵ��������ÿ���ڵ㶼��Ϊ��ʼ��һ�ο�ʼ���ʡ�
	{
		if(visited[i]==0)    //ÿ���ڵ㿪ʼ������ʱ���ȼ���Ƿ����������û�б�����������´Ӹýڵ㿪ʼ���α���
		{
		  r++;
	      qu[r]=t.vex[0].number;        //���Ƚ���һ���ڵ���ӣ�Ϊ����ѭ����׼����
		  while(r!=f)       //�ڶӲ��յ������½���ѭ����
		  {
			  f++;
			  j=qu[f];
			  cout<<t.vex[j].inf<<" ";      //�Ƚ���ͷ�ڵ���ԣ�Ȼ���жϽڵ��Ƿ��� �ڽӽڵ㣬�������
			  visited[j]=1;
			
		      for(k=0;k<t.n;k++)         //�ø�ѭ�������е�Ϊ���ʵ��ڽ���ӡ�
			  {
				  if(visited[k]==0&&t.edge[j][k]!=0) //����Ҫע�⣬��Ϊ�ڽӾ���洢���Ǳߵ�Ȩֵ����������Ӧ��Ϊ��=0Ϊ�ж�������
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
	cout<<"����ͼ:"<<endl;
	creatgraph(l);
	cout<<"���ͼ:"<<endl;
	disp(l);
	cout<<"����ͼ:";
	WFSthread(l);

}






