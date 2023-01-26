#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class Empl
{
  int eno,bsal;
  char enam[20],dept[15];
  float da,hra,gross;
  void calc()
  {
	da=(float) bsal*30/100;
	hra=(float) bsal*10/100;
	gross=bsal+da+hra;
  }
  public:
  void input()
  {
	cout<<"Enter employee no ";
	cin>>eno;
	fflush(stdin);
	cout<<"Enter empl. name ";
	gets(enam);           // cin.getline(enam,20)
	cout<<"Enter dept. ";
	cin>>dept;
	cout<<"Enter basic salary ";
	cin>>bsal;

  }
  void display()
  {
	calc();
	cout<<"\nEmp. no "<<eno;
	cout<<"\nEmp. name "<<enam;
	cout<<"\nEmp. dept "<<dept;
	cout<<"\nEmp. basic salaryt "<<bsal;
	cout<<"\nDearness Allow. "<<da;
	cout<<"\nHouse Rent allow. "<<hra;
	cout<<"\nGross salary "<<gross;
  }
};
void main()
{
clrscr();
Empl ob;
  ob.input();
  ob.display();
getch();
}