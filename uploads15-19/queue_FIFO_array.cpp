// Queue using Array    FIFO ( First In First Out )

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size  5

#define cls() system("cls");

int front=-1;     // Global Declaration
int rear=-1;
int ar[size];

void insert()       // insert
{
  if(rear==size-1)
    { printf("\nQueue full ");
      return;
    }
  if(rear==-1)         // for the first time
      ++front;

  int n;
  printf("Enter the value ");
  scanf("%d",&n);
   ar[++rear]=n;
   printf("\nInsert success");
   return;
}

void del()        // delete
{
   if(front==-1)
    {  printf("\nEmpty Queue");
       return;
    }
    int x=ar[front];
    if(front==rear)
    { rear=-1;
      front=-1;
    }
    else
	  front++;

    printf("%d has been deleted ",x);
    return;
}

void display()
{
   if (rear==-1)
      {  printf("Empty Queue ");
	 return;
      }

    printf("\nQueue status \n");
    for(int i=front;i<=rear;i++)
      printf("%d ",ar[i]);
   return;
}

int main()
{
int ch;
do{
    cls();
printf("\n1. Insert \n2. Delete \n 3. View \n 4.Exit");
printf("\nEnter your choice ");
scanf("%d",&ch);
switch(ch)
{
	case 1:
	  insert();
	  break;
	case 2:
	  del();
	  break;
	case 3:
	  display();
	  break;
	case 4:
	    printf("\nThank you...");
	    break;
	default:
	    printf("\nWrong choice ");
}
getch();
} while(ch!=4);
return EXIT_SUCCESS;
}
