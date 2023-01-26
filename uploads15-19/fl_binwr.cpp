#include<iostream.h>
#include<fstream.h>
#include<stdio.h>

class pub
{
  char nm[20];
  int age;
  public:
  void input()
  { cout<<"Enter the name ";
	 gets(nm);
	 cout<<"Enter the age ";
	 cin>>age;
  }
};

void main()
{
  ofstream wf("stu.dat",ios::out,ios::binary);
  pub ob;
  char ch='y';
  do
  {
  ob.input();
  wf.write((char*)&ob,sizeof(ob));
  cout<<"want to add new record y/n ";
  cin>>ch;
  }while(ch=='y'|| ch=='Y');

  wf.close();
}

