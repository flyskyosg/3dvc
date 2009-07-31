#include<iostream.h> 
void main() 
{ 
char string[81]; 
int i,num; 
cin>>string; 
for(i=0,num=0;string[i]!='\0';i++,num++); 
cout<<num<<endl;
} 