#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class pub
{
  char nm[20];
  int age;
  public:
  void display()
  { cout<<"Name "<<strlwr(nm)<<endl;
	 cout<<"Age "<<age<<endl;
  }
};

void main()
{
  ifstream rf("stu.dat",ios::in);
  pub ob;
 while(rf)
  {
  rf.read((char*)&ob,sizeof(ob));
  if(rf.eof())
  break;
  ob.display();

  }

  rf.close();
}

