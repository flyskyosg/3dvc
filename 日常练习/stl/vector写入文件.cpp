  
  #include   <iostream>   
  #include   <string>   
  #include   <vector>   
  #include   <cstdlib>   
  #include   <fstream>   
  using   namespace   std;   
 
  typedef   struct   {   
  int   index;   
  string   offset;   
  }   Widx;   


   vector<Widx>   wt;   
  void   add_Widx(Widx   _wt)   {wt.push_back(_wt);   } 

int   main()   
  {   
  Widx   idx   =   {1,"abc"};   
  add_Widx(idx);   
  Widx   idx1   =   {3,"def"};   
  add_Widx(idx1);   
  //写入文件   
  ofstream   outfile("test.dat",ios_base::binary);   
  int   iS=wt.size();   
  //写入数组大小   
  outfile.write((char*)&iS,sizeof(int));   
  //写入数据   
  for(int   i=0;i<wt.size();i++)   
    outfile.write((char*)&wt[i],sizeof(Widx));   
  for(int   i   =   0;   i   <   wt.size();i++)   //输出结构体   
  cout<<"wt:"<<wt[i].index<<"   "<<wt[i].offset<<endl; 
  outfile.close();
    
  //读出文件   
  int   iS2=0;//数组大小   
  ifstream   infile("test.dat",ios_base::binary);   
  infile.read((char*)&iS2,sizeof(int));//读取数组大小   
  //根据文件中的的数组大小，分配数组存储空间   
  std::vector<Widx>   arrayo(iS2);   
  //读取数据   
  for(int   i=0;i<iS2;i++)   
    infile.read((char*)&arrayo[i],sizeof(Widx));   
  //ok,验证  

  cout<<"验证"<<endl;
  for(int i=0;i<iS2;i++)
  {
	  cout<<arrayo[i].index<<arrayo[i].offset<<endl;
  }
    
  infile.close();
  system("pause");   
  return   0;   
  } 