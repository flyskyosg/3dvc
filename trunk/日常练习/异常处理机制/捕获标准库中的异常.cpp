#include<vector>            //从标准模板库中继承与标准库中的异常捕获
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
			return at(i);             //从vector中继承来的at成员函数
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
	/*catch(out_of_range)             //out_of_range 是vector中的at函                                         //  数抛出的异常
	{
		cout<<"下标越界"<<endl;
	}*/
	catch(exception)                  //标准异常也可以处理
	{
		cout<<"捕获标准异常"<<endl;
	}

}