#include<iostream>     //sizeof �ĸ߼�Ӧ���Լ�ָ�����͵Ĵ�С

using namespace std;

int main()
{


	double s=10.20,* p=& s;
	int n=10,* q=& n;
	char  w,* u=& w;
	void * e=p;
	cout<<sizeof(s)<<"=="<<sizeof(double)<<endl;
    cout<<sizeof(int)<<" "<<sizeof(p)<<" "<<sizeof(q)<<" "<<sizeof(u)<<" "<<sizeof(e)<<endl;
       cout<<sizeof(wchar_t)<<endl;  //2���ֽ�
	cout<<*(double *)e<<" "<<*p<<endl;
	 
	//��vc6.0�У�ָ�����͵�������ռ�õĿռ��С��int�����ݵĴ�Сһ�£���ָ�����ָ���κε����ͣ������ڶԿ�ָ����м�õ�ʱ��Ҫ
	//��������ת��
	
	
	
	
	
	
	
	return 0;





}