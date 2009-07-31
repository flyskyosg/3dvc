#include<iostream.h>                                 //程序默认从2000一月一号开始计算，2000年一月一号是周6//
#include<stdio.h>
#include<iomanip.h>
int jisuan(int n)                                 //判断是否润年，n为年份
{
	if(n%4==0) return 366;else return 365;
}
int chatian(int n)                                //确定某年的一月一号是周几,返回0，周六，返回一，周日，一次类推.....,n为年份//
{
	long int sum=0,t;
	for(int i=2000;i<n;i++)                       //加上2000年之所求年份之间的所有天数，//
		  sum+=jisuan(i);
	t=sum%7;                                       //除7求余是为了确定该年第一天是周几//
	return t;
}
void yuefen(int yue[12],int n)                     //确定每月的天数，n为 年份，yue[12]为地址传递//
{
	if(jisuan(n)==366) 
	{yue[0]=31;yue[1]=29;yue[2]=31;yue[3]=30;yue[4]=31;yue[5]=30;yue[6]=31;yue[7]=31;yue[8]=30;yue[9]=31;yue[10]=30;yue[11]=31;}
	else 
	{yue[0]=31;yue[1]=28;yue[2]=31;yue[3]=30;yue[4]=31;yue[5]=30;yue[6]=31;yue[7]=31;yue[8]=30;yue[9]=31;yue[10]=30;yue[11]=31;};
} 
void diyitian(int p[12],int n)                     //确定某月的第一天是周几，n为年份，p[12]为地址传递//
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
if(jisuan(n)==366)                              //根据是否闰年来确定每个月的一号是周几//
{
	p[1]=p[0]+3;if(p[1]>=7) p[1]-=7;
    p[2]=p[1]+1;if(p[2]>=7) p[2]-=7;            //减7是为了防止加过后大于7，在减7后做了一个循环，效果一样 //
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
void xianshi(int p[12],int yue[12],int y)                //显示在屏幕上
{
	int i=1,j=1;                                         //i是用来控制输出的空格数.j是用来控制换行
	cout<<" 日 一 二 三 四 五 六"<<endl;
	
	                                                     //作为中间的转接，确定输出对应情况。//
    cout<<endl;
    cout<<"   ";                                         //输出后在调试，增加或减少空格的个数，//
	switch(p[y-1])     
	{
	case 1:for(i;i<1;i++){j++;cout<<setw(3)<<" ";};break;//根据每月一号是周几来确定起始输入位置//
	case 2:for(i;i<2;i++){j++;cout<<setw(3)<<" ";};break;      
	case 3:for(i;i<3;i++){j++;cout<<setw(3)<<" ";};break;
	case 4:for(i;i<4;i++){j++;cout<<setw(3)<<" ";};break;
    case 5:for(i;i<5;i++){j++;cout<<setw(3)<<" ";};break;
	case 6:for(i;i<6;i++){j++;cout<<setw(3)<<" ";};break;
	case 0:for(i;i<7;i++){j++;cout<<setw(3)<<" ";};break;
	default:break;
	}
	for(i=1;i<=yue[y-1];i++)                              //根据每月的天数来确定输出的天数。j为控制换行//
	{
		if(j%7==0) cout<<endl;
		cout<<setw(3)<<i;
		j++;
	}
}
void main()
{
	cout<<"    ^_^欢迎使用^_^"<<endl;
	cout<<"======================="<<endl;
	int yue[12],p[12],n,y;
	cout<<"请输入年份于月份"<<endl;
	cout<<"年份:";cin>>n;cout<<endl;
	cout<<"月份:";cin>>y;cout<<endl;
    cout<<"======================="<<endl;
	yuefen(yue,n);
	diyitian(p,n);
	xianshi(p,yue,y);
	cout<<endl;
    cout<<"======================="<<endl;
    cout<<"     ^_^谢谢使用^_^"<<endl<<endl;
    cout<<"按任意健退出"<<endl;
	getchar();

}




   









    









		




		
	


