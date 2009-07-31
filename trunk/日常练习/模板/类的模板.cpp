#include<iostream>
#include<string>  


using namespace std;          

template <class t ,class r>            //注意：此处类型形参表可以为两个，或多个//
class xiao
{
	t a;r m;double q;             //类中也可以有基本的数据类行，但被定义的变量必须一直用 该类型//
	public:
		
	xiao(t i,r n);

	
    r  disp()
	{
     return (a*m);            
	}
	r dou();
	
	
};

template<class t,class r>           //在类外定义的成员函数的开头格式//
xiao<t,r>::xiao(t i,r n)         //构造函数也可以类内声明，类外定义//
	{
	   a=i;m=n;q=a+m;
	}
template<class t,class r>           //每一个在类外定义的成员函数的开头都必须加上这些文件头//
r xiao<t,r>:: dou()
	{
		return(a+m);
	}
int  main()
{
    //template xiao<int,double>;
    xiao<int,double> a(10,10.0);
	cout<<a.disp()<<endl;
	cout<<a.dou()<<endl;
	
	system("pause");
	return 0;
}

