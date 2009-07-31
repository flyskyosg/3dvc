#include<iostream>


using namespace std;

void inssort(int * data,int num)      //²åÈëÅÅĞò
{
 
	   for(int i = 1;i < num;i++)
	   {
		   int temp = data[i];
		   int j = i-1;
		   while(j >= 0 && data[j] > temp)
		   {
			   data[j+1] = data[j];
			   j--;
		   }
		   data[j+1] = temp;
	   }
}

void shell(int * data,int num) //shell ÅÅĞò
{
	int gap = 5;
	while(gap >= 1 )
	{
	   for(int i = gap;i < num;i++)
	   {
		   
			   int temp = data[i];
			   int j = i - gap;
			   while(j >= 0 && data[j] > temp)
			   {
				   data[j+gap] = data[j];
				   j-=gap;
			   }
			   data[j+gap] = temp;
	   }

	   gap-=2;
	}
}


int main()
{
	int i = 10;
	int data[10];
	while(i)
	{
		data[i-1] = i;
		i--;
	}

	shell(data,10);
	for(int j = 0; j < 10; j++)
		cout << data[j] << endl;
	getchar();
}

