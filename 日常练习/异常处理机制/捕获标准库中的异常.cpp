#include<vector>            //�ӱ�׼ģ����м̳����׼���е��쳣����
#include<iostream>
#include<exception>

using namespace std;

template <typename T>
class vec:public vector<T>
{
	
    public:
	    vec(){}
   //	vec():vector<T>(){}
		vec(T s):vector<T>(s){};
		T & operator [] (int i)
		{
			return at(i);             //��vector�м̳�����at��Ա����
		}

		const T & operator [] (int i) const
		{
			return at(i);
		}
};

void main()
{
	vec<int> v;
	v.push_back(10);
		v.push_back(10);
			v.push_back(10);
	try
	{
	cout<<v[2]<<endl;
	cout<<v[3]<<endl;
	}
	/*catch(out_of_range)             //out_of_range ��vector�е�at��                                         //  ���׳����쳣
	{
		cout<<"�±�Խ��"<<endl;
	}*/
	catch(exception)                  //��׼�쳣Ҳ���Դ���
	{
		cout<<"�����׼�쳣"<<endl;
	}

}