#include<iostream>         //for_each 函数 
#include<algorithm>
#include<vector>

using namespace std;

void disp(int & a )       //这里只能有一个参数 
{
     a+=10; 
     cout<<a<<endl; 
} 
     
     
     
     


int main()
{
    vector<int> vec(20,0);
    for(int i=0;i<10;i++)
      vec[i]=i;
      
      for_each( vec.begin(),vec.end(),disp);  //for_each函数 
      system("pause");
}
      
     
      
      
      
      
      
      
      
      
      

 
