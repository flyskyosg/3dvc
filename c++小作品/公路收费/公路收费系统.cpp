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
	cout<<"100/С����-200/�󿨳�-150/������"<<endl;
	cout<<"С����:"<<x<<"��"<<" "<<"����:"<<x*100<<"Ԫ"<<endl;
    cout<<"�󿨳�:"<<y<<"��"<<" "<<"����:"<<y*200<<"Ԫ"<<endl;
	cout<<"������:"<<z<<"��"<<" "<<"����:"<<z*150<<"Ԫ"<<endl;
	cout<<"�ܼƷ���:"<<x*100+y*200+z*150<<"Ԫ"<<endl;
}
};
int tongji::x=0;int tongji::y=0;int tongji::z=0;int tongji::w=0;

 void main()
 {
	 int *p=new int(4);tongji b;
	 cout<<"���ͱ�:1-С����2-�󿨳�3-������"<<endl;
	 for(int i=1;*p!=0;i++)
	 {    
		 cout<<"�����복��,���������,��0����."<<endl;
		 cin>>*p;if(*p!=0&&*p!=1&&*p!=2&&*p!=3)  { cout<<"����������������롣"<<endl;  continue;}; tongji a(*p);a.jisuan();
	 }
	 b.output();
	 cout<<"ллʹ�ã���������˳�ϵͳ��"<<endl;getchar();
 }


	

	

 

