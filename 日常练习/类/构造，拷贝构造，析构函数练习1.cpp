#include<iostream.h>
class t
{
private:
	int x,y;
public:
	 t(int a,int b)
	{
		x=a;y=b;cout<<"��ʱ���ù��캯��1"<<endl;        
	}
	 t()
	 {
		 cout<<"��ʱ���ù��캯��2"<<endl;
	 }
	 t(int a)
	 {
		 x=a;
		 y=a;
		 cout<<"��ʱ���ù��캯��3"<<endl;
	 }

	int jia( );
	int jian(int x,int y )
	{
		return(x+y);
	}
t(const t &k)
{
	x=k.x;
	y=k.y;
	cout<<"��ʱ���ÿ������캯��"<<endl;
}
~t()
{
	cout<<"��ʱ������������"<<endl;
}

};


int t:: jia( )
{ 
  return (x+y);
}



void main()
{
	int i;
    
	t a(1,1);

	t b;
	
	t c(a);	

	t s[2]={t(0),t(1)};

	t d[2]={t(0,0),t(1,1)};
    
	cout<<a.jia()<<endl;
	
	cout<<b.jian(1,1)<<endl;


	cout<<c.jia()<<endl;
		for(i=0;i<=1;i++)
        cout<<s[i].jia()<<endl;


		for(i=0;i<=1;i++)
        cout<<d[i].jia()<<endl;



}
