#include<iostream>
#include<string>  


using namespace std;          

template <class t ,class r>            //ע�⣺�˴������βα����Ϊ����������//
class xiao
{
	t a;r m;double q;             //����Ҳ�����л������������У���������ı�������һֱ�� ������//
	public:
		
	xiao(t i,r n);

	
    r  disp()
	{
     return (a*m);            
	}
	r dou();
	
	
};

template<class t,class r>           //�����ⶨ��ĳ�Ա�����Ŀ�ͷ��ʽ//
xiao<t,r>::xiao(t i,r n)         //���캯��Ҳ�����������������ⶨ��//
	{
	   a=i;m=n;q=a+m;
	}
template<class t,class r>           //ÿһ�������ⶨ��ĳ�Ա�����Ŀ�ͷ�����������Щ�ļ�ͷ//
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

