#include<iostream.h>                                 //����Ĭ�ϴ�2000һ��һ�ſ�ʼ���㣬2000��һ��һ������6//
#include<stdio.h>
#include<iomanip.h>
int jisuan(int n)                                 //�ж��Ƿ����꣬nΪ���
{
	if(n%4==0) return 366;else return 365;
}
int chatian(int n)                                //ȷ��ĳ���һ��һ�����ܼ�,����0������������һ�����գ�һ������.....,nΪ���//
{
	long int sum=0,t;
	for(int i=2000;i<n;i++)                       //����2000��֮�������֮�������������//
		  sum+=jisuan(i);
	t=sum%7;                                       //��7������Ϊ��ȷ�������һ�����ܼ�//
	return t;
}
void yuefen(int yue[12],int n)                     //ȷ��ÿ�µ�������nΪ ��ݣ�yue[12]Ϊ��ַ����//
{
	if(jisuan(n)==366) 
	{yue[0]=31;yue[1]=29;yue[2]=31;yue[3]=30;yue[4]=31;yue[5]=30;yue[6]=31;yue[7]=31;yue[8]=30;yue[9]=31;yue[10]=30;yue[11]=31;}
	else 
	{yue[0]=31;yue[1]=28;yue[2]=31;yue[3]=30;yue[4]=31;yue[5]=30;yue[6]=31;yue[7]=31;yue[8]=30;yue[9]=31;yue[10]=30;yue[11]=31;};
} 
void diyitian(int p[12],int n)                     //ȷ��ĳ�µĵ�һ�����ܼ���nΪ��ݣ�p[12]Ϊ��ַ����//
{  
switch(chatian(n))
{
case 0: p[0]=6;break;
case 1: p[0]=0;break;
case 2: p[0]=1;break;
case 3: p[0]=2;break;
case 4: p[0]=3;break;
case 5: p[0]=4;break;
case 6: p[0]=5;break;
default:break;
}
if(jisuan(n)==366)                              //�����Ƿ�������ȷ��ÿ���µ�һ�����ܼ�//
{
	p[1]=p[0]+3;if(p[1]>=7) p[1]-=7;
    p[2]=p[1]+1;if(p[2]>=7) p[2]-=7;            //��7��Ϊ�˷�ֹ�ӹ������7���ڼ�7������һ��ѭ����Ч��һ�� //
    p[3]=p[2]+3;if(p[3]>=7) p[3]-=7;
    p[4]=p[3]+2;if(p[4]>=7) p[4]-=7;
    p[5]=p[4]+3;if(p[5]>=7) p[5]-=7;
    p[6]=p[5]+2;if(p[6]>=7) p[6]-=7;
    p[7]=p[6]+3;if(p[7]>=7) p[7]-=7;
    p[8]=p[7]+3;if(p[8]>=7) p[8]-=7;
    p[9]=p[8]+2;if(p[9]>=7) p[9]-=7;
    p[10]=p[9]+3;if(p[10]>=7) p[10]-=7;
    p[11]=p[10]+2;if(p[11]>=7) p[11]-=7;            
}
else
 {
	p[1]=p[0]+3;if(p[1]>=7) p[1]-=7;
    p[2]=p[1]+0;if(p[2]>=7) p[2]-=7;
    p[3]=p[2]+3;if(p[3]>=7) p[3]-=7;
    p[4]=p[3]+2;if(p[4]>=7) p[4]-=7;
    p[5]=p[4]+3;if(p[5]>=7) p[5]-=7;
    p[6]=p[5]+2;if(p[6]>=7) p[6]-=7;
    p[7]=p[6]+3;if(p[7]>=7) p[7]-=7;
    p[8]=p[7]+3;if(p[8]>=7) p[8]-=7;
    p[9]=p[8]+2;if(p[9]>=7) p[9]-=7;
    p[10]=p[9]+3;if(p[10]>=7) p[10]-=7;
    p[11]=p[10]+2;if(p[11]>=7) p[11]-=7;
};
}
void xianshi(int p[12],int yue[12],int y)                //��ʾ����Ļ��
{
	int i=1,j=1;                                         //i��������������Ŀո���.j���������ƻ���
	cout<<" �� һ �� �� �� �� ��"<<endl;
	
	                                                     //��Ϊ�м��ת�ӣ�ȷ�������Ӧ�����//
    cout<<endl;
    cout<<"   ";                                         //������ڵ��ԣ����ӻ���ٿո�ĸ�����//
	switch(p[y-1])     
	{
	case 1:for(i;i<1;i++){j++;cout<<setw(3)<<" ";};break;//����ÿ��һ�����ܼ���ȷ����ʼ����λ��//
	case 2:for(i;i<2;i++){j++;cout<<setw(3)<<" ";};break;      
	case 3:for(i;i<3;i++){j++;cout<<setw(3)<<" ";};break;
	case 4:for(i;i<4;i++){j++;cout<<setw(3)<<" ";};break;
    case 5:for(i;i<5;i++){j++;cout<<setw(3)<<" ";};break;
	case 6:for(i;i<6;i++){j++;cout<<setw(3)<<" ";};break;
	case 0:for(i;i<7;i++){j++;cout<<setw(3)<<" ";};break;
	default:break;
	}
	for(i=1;i<=yue[y-1];i++)                              //����ÿ�µ�������ȷ�������������jΪ���ƻ���//
	{
		if(j%7==0) cout<<endl;
		cout<<setw(3)<<i;
		j++;
	}
}
void main()
{
	cout<<"    ^_^��ӭʹ��^_^"<<endl;
	cout<<"======================="<<endl;
	int yue[12],p[12],n,y;
	cout<<"������������·�"<<endl;
	cout<<"���:";cin>>n;cout<<endl;
	cout<<"�·�:";cin>>y;cout<<endl;
    cout<<"======================="<<endl;
	yuefen(yue,n);
	diyitian(p,n);
	xianshi(p,yue,y);
	cout<<endl;
    cout<<"======================="<<endl;
    cout<<"     ^_^ллʹ��^_^"<<endl<<endl;
    cout<<"�����⽡�˳�"<<endl;
	getchar();

}




   









    









		




		
	


