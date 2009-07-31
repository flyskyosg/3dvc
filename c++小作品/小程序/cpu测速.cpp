
#include "time.h" 
#include "iostream.h" 
#include<stdio.h>
void main()
{  

	time_t begin,end;
begin = clock ();
for(int i=0;i<10000000;i++) 
end = clock ();
cout<<"您的CPU速度为:"<<(end - begin )/18.2<<"\n\a";

cout<<"^_^谢谢使用^_^"<<endl;
cout<<"   作者:小小"<<endl;
cout<<"按任意键退出"<<endl;
getchar();
}