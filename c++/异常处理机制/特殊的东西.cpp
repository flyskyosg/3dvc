
#include<iostream>
using namespace std;


void f()throw(int)
{
     try
     {
        throw ;
     }
     catch(int)
     {
          cout<<"00"<<endl;
          getchar();
            
     }
 } 
                        

//������ 

int main()
{

    f();
	system("pause");
	return 0;
	
}
