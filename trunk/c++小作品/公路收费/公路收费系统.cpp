#include<iostream.h>
#include<stdio.h>
class tongji
{
	static int x,y,z,w; 
public:
   	tongji(int i)
	{
		w=i;
	}
	tongji(){}

static void jisuan()
{

    if(w==1) x++;
		else if(w==2) y++;
		else if(w==3) z++;
}
 static void output()
{
	cout<<"100/小汽车-200/大卡车-150/公汽车"<<endl;
	cout<<"小汽车:"<<x<<"辆"<<" "<<"费用:"<<x*100<<"元"<<endl;
    cout<<"大卡车:"<<y<<"辆"<<" "<<"费用:"<<y*200<<"元"<<endl;
	cout<<"公汽车:"<<z<<"辆"<<" "<<"费用:"<<z*150<<"元"<<endl;
	cout<<"总计费用:"<<x*100+y*200+z*150<<"元"<<endl;
}
};
int tongji::x=0;int tongji::y=0;int tongji::z=0;int tongji::w=0;

 void main()
 {
	 int *p=new int(4);tongji b;
	 cout<<"车型表:1-小汽车2-大卡车3-公汽车"<<endl;
	 for(int i=1;*p!=0;i++)
	 {    
		 cout<<"请输入车型,如果无输入,按0结束."<<endl;
		 cin>>*p;if(*p!=0&&*p!=1&&*p!=2&&*p!=3)  { cout<<"输入错误，请重新输入。"<<endl;  continue;}; tongji a(*p);a.jisuan();
	 }
	 b.output();
	 cout<<"谢谢使用，按任意键退出系统。"<<endl;getchar();
 }


	

	

 

