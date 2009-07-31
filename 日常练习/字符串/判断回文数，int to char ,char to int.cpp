//判断回文数，int to char ,char to int
/*
基本算法：
      转换为字符，然后前后同时迭代比较
*/
#include<iostream>
#include<string>
using namespace std;
#define MAX 10

void inttoa(int data,char  * p = NULL)  //数据转字符
{
	if(p == NULL) return;
	char store[MAX];
	int num = 0;
	while(data)
	{
		store[num++] = data % 10 + '0';
		data /= 10;
	}

	for(int i = num-1; i >= 0;i--)
	{
		*p++ = store[i];
	}
	*p = '\0';
	
}

int atoint(const char * p)      //字符转数字
{
	//string::size_type num = strlen(p);
	int sum = 0;
	while(*p != '\0')
	{
		sum = sum * 10 + (*p - '0');
		p++;
	}
	return sum;
}


bool isHuiwen(const char * p = NULL)    // 回文比较
{
	if(p == NULL) return false;
	else
		cout << p << endl;
	string::size_type  begin = 0, end = strlen(p) - 1;
	while(begin < end)
	{
		if(p[begin] != p[end]) break;
		begin++;end--;
	}

	if(begin < end) return false;
	else
		 return true;
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
    
	int data = 1234321;
	char * p = new char [8];
	cout << "data to char" << endl;
	inttoa(data,p);

	cout << "判断回文" << endl;
	cout << (isHuiwen(p) ? "yes" : "no")<< endl;

    cout << "char to int" << endl << atoint(p) << endl;
    
	getchar();
}