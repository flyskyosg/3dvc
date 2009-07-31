 #include<iostream.h>
 void main()
 {
	 int i,j,t,h,q,w,a1,a2,a3;
	 char b1[10],b2[10],b3[10],a[10];
	 cin>>a;
	 for(i=0,a1=1;a[i]!='.';i++,a1++)
		 b1[i]=a[i];
	 a1--;
	 h=i+1;
	 for(a2=1,t=0;a[h]!='e'||a[h]!='E';h++,a2++,t++)
		 b2[t]=a[h];
	 a2--;
	 q=h+1;
	 for(w=0,a3=1;a[q]!='\0';w++,q++,a3++)
		 b3[w]=a[q];
	 a3--;
	 
	 double sum1=0,sum2=0,sum3=0,k=1,m=a1;
	 for(i=0;i<=a1-1;i++)
	 {
		 for(j=1;j<=m;j++)
		 {
			 if(j=1) k=1.0;
			 else k*=10.0;
		 }
		 sum1+=b1[i]*k;
		 m--;
	 }
     
	 k=0.1;m=a2;
	 for(i=a2-1;i>=0;i--)
	 {
		 for(j=1;j<=m;j++)
		 {
			 if(j=1) k=.1;
			 else k*=.1;
		 }
		 sum2+=b2[i]*k;
		 m--;
	 }
	 sum1+=sum2;
     
	  k=1;m=a3;
	 for(i=0;i<=a3-1;i++)
	 {
		 for(j=1;j<=m;j++)
		 {
			 if(j=1) k=1;
			 else k*=10;
		 }
		 sum3+=b3[i]*k;
		 m--;
	 }
	 k=1;
	 for(i=1;i<=sum3;i++)
         k*=10;
	 sum1*=k;
	 cout<<sum1;
 }

