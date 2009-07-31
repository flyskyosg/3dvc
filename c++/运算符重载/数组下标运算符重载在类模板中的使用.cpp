#include<iostream.h>
#include<iomanip.h>
template <class t>
class xiao
{
	t *x;int n;
	public:
		xiao(t *i,int m)                       //类当中含有整形数组时，用动态的分配空间，在构造函数中只分配空间，在用其他的函数赋//
		{
		  x=i;n=m;                             //或者用这里的形式指向主函数中的数组,但是要传递数组元素的个数//
		  
		}
		void px()
		{
			t a;
			for(int i=1;i<=n-1;i++)
				for(int j=1;j<=n-i;j++)    //排序算法：有n个数据，共需要进行i=n-1次外循环，每次比较的次数即每次的内循环的次数为n-i次。//
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
		bool operator [](int m)                     //在用到类的模板的时候，要附带一个下标运算符重载函数，来限制数组的下标越界//
		{
			if(m>=0&&m<=9)	return 1;        
			
			else return 0;
		}
		
		void cha(int m)                              //下标运算符常用在输出或输入的查询函数中，来防止输入或输出的数组元素下标越界//
		{
			if(x[m]) cout<<x[m-1]<<endl;           //下标运算符只能通过数组元素的形式来限制[]中的数据，来检测是否越界,//
			else cout<<"下标越界"<<endl;           //下标运算符通常和这些函数混合实用//
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
	cout<<"输入整型数据"<<endl;
	for(int i=0;i<=9;i++)
	{
		cout<<"输入第"<<i+1<<"个数据:";
			cin>>a[i];
			cout<<endl;
	}
	xiao <int> c(a,10);xiao <char> d(b,10);
	c.px();
	c.disp();
	c.he();
	cout<<"输入您要查询的数据";cin>>q;
	c.cha(q-1);
    

}

  

