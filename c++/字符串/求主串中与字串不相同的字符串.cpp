//�����������ִ�����ͬ���ַ���
/*
�����㷨��
      ���л����Ĵ�ƥ�䣬������ͬ�������ͬ����
*/
#include<iostream>
#include<string>
using namespace std;

void delchar(const char * p,const char * q)
{
	if(!p) return;
	string::size_type len = strlen(p); //�����ĳ���
	string::size_type i,j;             //�����α�
	for(i = 0;i < len; )                    
	{
		j = i;						   //iÿ���ƶ���j�͸����Ƚ�
		string::size_type k = 0;
		for(k = 0;(k < strlen(q)) && j < len && (q[k] == p[j]); k++,j++); //��ͳ���Ӵ�ƥ��
		
		if(k == strlen(q)) i+=strlen(q);        //����kֵ�ж��Ƿ����
		else
		{
			if(i == j)           //�ж��Ƿ��ǵ�һ��ͬ���
			{
				cout << i << p[i] << endl;
				i++;
			}
			else
			{
			   while(i<j)            //��һ����ͬ����ߵĲ�ͬ
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