#include<iostream>
#include<conio.h>
#include<stdio.h>
//#include<malloc.h>
#include<stdlib.h>
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
     if(ptr==NULL)
     {
     	std::cout<<"Unable to create memory";
     	return;
	 }
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
      end=end->p; // or use /*end=ptr;*///
      }
      std::cout<<"Press any key to continue... 'n / N' to stop"<<std::endl;
      ch=getchar();
      if(ch=='n'|| ch=='N')
	{
	  break;
	}
   }while(1);
   //return 0;
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
  //return 0;
}

int main()
{
cls();
std::cout<<"\nEnter array element as your choice \n";
input();
std::cout<<"\n Given elements ";
display();
//getch();
return 0;
}
