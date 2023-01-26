#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class Empl
{
 private:
  int eno,bsal;
  char enam[20],dept[15];
  float da,hra,gross;
  void calc();
 public:
  Empl();
  Empl(int,char[],char[],int);
  Empl(Empl *);
  void input();
  void display();
  ~Empl(){ cout<<"\nRecord deleted "<<eno;}
};

Empl::Empl()      // default constructor
{
  strcpy(enam,"");
  strcpy(dept,"");
  eno=bsal=da=hra=gross=0;
}
Empl::Empl(int a,char b[],char c[],int d)  // Parameterized constructor
{
 eno=a;
 strcpy(enam,b);
 strcpy(dept,c);
 bsal=d;
}
Empl::Empl(Empl *obb)
{
  eno=obb->eno+1;
  strcpy(enam,obb->enam);
  strcpy(dept,obb->dept);
  bsal=obb->bsal;
}

void Empl::calc()
{
	da=(float) bsal*30/100;
	hra=(float) bsal*10/100;
	gross=bsal+da+hra;
}

void Empl::input()
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
  void Empl::display()
  {
	calc();
	cout<<"\nEmp. no "<<eno;
	cout<<"\nEmp. name "<<enam;
	cout<<"\nEmp. dept "<<dept;
	cout<<"\nEmp. basic salaryt "<<bsal;
	cout<<"\nDearness Allow. "<<da;
	cout<<"\nHouse Rent allow. "<<hra;
	cout<<"\nGross salary "<<gross;
	cout<<"\n------------------------------------------";
  }

void main()
{
clrscr();
Empl ob1(111,"S Roy","comp",24000);
  //ob.input();
  ob1.display();
Empl ob2(&ob1);
  ob2.display();
getch();
}