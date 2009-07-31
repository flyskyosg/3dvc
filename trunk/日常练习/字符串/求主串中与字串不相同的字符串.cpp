//求主串中与字串不相同的字符串
/*
基本算法：
      进行基本的串匹配，遇到不同输出，形同保留
*/
#include<iostream>
#include<string>
using namespace std;

void delchar(const char * p,const char * q)
{
	if(!p) return;
	string::size_type len = strlen(p); //主串的长度
	string::size_type i,j;             //主串游标
	for(i = 0;i < len; )                    
	{
		j = i;						   //i每次移动，j和付串比较
		string::size_type k = 0;
		for(k = 0;(k < strlen(q)) && j < len && (q[k] == p[j]); k++,j++); //传统的子串匹配
		
		if(k == strlen(q)) i+=strlen(q);        //根据k值判断是否相等
		else
		{
			if(i == j)           //判断是否是第一不同相等
			{
				cout << i << p[i] << endl;
				i++;
			}
			else
			{
			   while(i<j)            //第一个相同，后边的不同
			   {
				   cout<< i << p[i] << endl;
				   i++;
			   }
			}//else
		}//else
	}//for
}


		






int main()
{
	/*
	int a[4];
	cout << (int)&a << endl;
	cout << (int)&b << endl;
    */

	/*
	char c[] = {'c','h','i','n','\0'};
	char d[5];
	char * e = "china";
	strcpy(d,e);
	cout << d << endl;
	*/
    char * p = "askdaskaskdaskg";
	char * q = "ask";
	delchar(p,q);


	getchar();
}