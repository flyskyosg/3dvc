  
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
  //д���ļ�   
  ofstream   outfile("test.dat",ios_base::binary);   
  int   iS=wt.size();   
  //д�������С   
  outfile.write((char*)&iS,sizeof(int));   
  //д������   
  for(int   i=0;i<wt.size();i++)   
    outfile.write((char*)&wt[i],sizeof(Widx));   
  for(int   i   =   0;   i   <   wt.size();i++)   //����ṹ��   
  cout<<"wt:"<<wt[i].index<<"   "<<wt[i].offset<<endl; 
  outfile.close();
    
  //�����ļ�   
  int   iS2=0;//�����С   
  ifstream   infile("test.dat",ios_base::binary);   
  infile.read((char*)&iS2,sizeof(int));//��ȡ�����С   
  //�����ļ��еĵ������С����������洢�ռ�   
  std::vector<Widx>   arrayo(iS2);   
  //��ȡ����   
  for(int   i=0;i<iS2;i++)   
    infile.read((char*)&arrayo[i],sizeof(Widx));   
  //ok,��֤  

  cout<<"��֤"<<endl;
  for(int i=0;i<iS2;i++)
  {
	  cout<<arrayo[i].index<<arrayo[i].offset<<endl;
  }
    
  infile.close();
  system("pause");   
  return   0;   
  } 