#include<iostream.h>
#include<iomanip.h>
template <class t>
class xiao
{
	t *x;int n;
	public:
		xiao(t *i,int m)                       //�൱�к�����������ʱ���ö�̬�ķ���ռ䣬�ڹ��캯����ֻ����ռ䣬���������ĺ�����//
		{
		  x=i;n=m;                             //�������������ʽָ���������е�����,����Ҫ��������Ԫ�صĸ���//
		  
		}
		void px()
		{
			t a;
			for(int i=1;i<=n-1;i++)
				for(int j=1;j<=n-i;j++)    //�����㷨����n�����ݣ�����Ҫ����i=n-1����ѭ����ÿ�αȽϵĴ�����ÿ�ε���ѭ���Ĵ���Ϊn-i�Ρ�//
				{
					if(x[j-1]>x[j])
					{a=x[j-1];x[j-1]=x[j];x[j]=a;};
				}
		}
		void he()
		{
			t sum=0;
			for(int i=0;i<=n-1;i++)
				sum+=x[i];
			cout<<sum<<endl;
		}
		bool operator [](int m)                     //���õ����ģ���ʱ��Ҫ����һ���±���������غ�����������������±�Խ��//
		{
			if(m>=0&&m<=9)	return 1;        
			
			else return 0;
		}
		
		void cha(int m)                              //�±���������������������Ĳ�ѯ�����У�����ֹ��������������Ԫ���±�Խ��//
		{
			if(x[m]) cout<<x[m-1]<<endl;           //�±������ֻ��ͨ������Ԫ�ص���ʽ������[]�е����ݣ�������Ƿ�Խ��,//
			else cout<<"�±�Խ��"<<endl;           //�±������ͨ������Щ�������ʵ��//
		}
		void disp()
		{
			for(int i=0;i<=n-1;i++)
				cout<<setw(3)<<x[i];
			cout<<endl;
		}
};
void main()
{
	int q;
	int *a=new int [10];char b[11]={"kfijfkdfkk"};
	cout<<"������������"<<endl;
	for(int i=0;i<=9;i++)
	{
		cout<<"�����"<<i+1<<"������:";
			cin>>a[i];
			cout<<endl;
	}
	xiao <int> c(a,10);xiao <char> d(b,10);
	c.px();
	c.disp();
	c.he();
	cout<<"������Ҫ��ѯ������";cin>>q;
	c.cha(q-1);
    

}

  

