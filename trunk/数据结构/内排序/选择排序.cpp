#include<iostream.h>
#include<fstream.h>
#define max 10
int st[]={9,4,6,8,5,1,3,5,4,8};

void disp()
{
	for(int i=0;i<max;i++)
		cout<<st[i]<<" ";
}
void main()
{
	 int i=0,j=0,k=-1,t=-1;
	 for(i=0;i<max;i++)
	 {
		
		 t=st[i];
		 for(j=i;j<max;j++)
		 {
			
			 if(st[j]<st[i]){st[i]=st[j];k=j;}
		 }
		 st[k]=t;

		
	 }
	 disp();
}


	
