
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
                        

//Ö÷º¯Êý 

int main()
{

    f();
	system("pause");
	return 0;
	
}
