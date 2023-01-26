#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
//#include<alloc.h>
//using namespace std;
#define cls() system("cls");

struct node
{ int n;
  node *p;
};
node *front=NULL,*end=NULL;

void input()
{  node *ptr;
   char ch='n';
   int no;
   do
   {
     ptr=(node *) malloc(sizeof(node));
     std::cout<<"Enter the value of array element ";
     std::cin>>no;
     ptr->n=no;
     ptr->p=NULL;
     if(front==NULL)
     {
     front=ptr;
     end=ptr;
     }
     else
     {
      end->p=ptr;
      end=end->p;
      }
      std::cout<<"Press any key to continue... 'n / N' to stop"<<std::endl;
      ch=getchar();
      if(ch=='n'|| ch=='N')
	{
	  break;
	}
   }while(1);
}
void display()
{
  node *ptr;
  ptr=front;
  if (front==NULL)
    {  std::cout<<"Empty array ";
       return;
    }
  do
  {
   std::cout<<ptr->n<<" ";
   ptr=ptr->p;
  }while(ptr!=NULL);
}

int main()
{
cls();
std::cout<<"\nEnter array element as your choice \n";
input();
std::cout<<"\n Given elements ";
display();
getch();
return EXIT_SUCCESS;
}