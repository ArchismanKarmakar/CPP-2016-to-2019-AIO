#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//#include<alloc.h>

#define cls() system("cls");

struct node
{  int val;
   node *link;
   } *front,*rear;

void insbeg()       // insert  beg
{
  node *ptr;
  ptr=(node *)malloc(sizeof(node));

  if(ptr==NULL)
    { printf("\nQueue full ");
      return;
    }
  int n;
  printf("Enter the value ");
  scanf("%d",&n);

  ptr->val=n;
  ptr->link=NULL;

  if (rear==NULL)
  {  front=ptr;
     rear=ptr;
  }
  else
  {
    ptr->link=front;
    front=ptr;
  }
   printf("\nInsert success");
   return;
}
void insmid(int pos)       // insert  mid
{
  node *ptr,*tmp;
  ptr=(node *)malloc(sizeof(node));
  if(ptr==NULL)
    { printf("\nQueue full ");
      return;
    }
  tmp=front;
  while(tmp->link!=NULL)
  {  pos--;
     if(pos==1)
       break;
     tmp=tmp->link;
   }
   if(pos!=1)
     {  printf("\nOut of list");
	return;
     }
  int n;
  printf("Enter the value ");
  scanf("%d",&n);

  ptr->val=n;
  ptr->link=tmp->link;
  tmp->link=ptr;
  printf("\nInsert success");
  return;
}

void insend()       // insert  end
{
  node *ptr;
  ptr=(node *)malloc(sizeof(node));

  if(ptr==NULL)
    { printf("\nQueue full ");
      return;
    }
  int n;
  printf("Enter the value ");
  scanf("%d",&n);

  ptr->val=n;
  ptr->link=NULL;

  if (rear==NULL)
  {  front=ptr;
     rear=ptr;
  }
  else
  {
    rear->link=ptr;
    rear=rear->link;
  }
   printf("\nInsert success");
   return;
}

void delbeg()        // delete beg
{
   node *ptr;

   if(front==NULL)
    {  printf("\nEmpty Queue");
       return;
    }
    int x=front->val;
    ptr=front;
    if(front==rear)
    { rear=NULL;
      front=NULL;
    }
    else
	front=front->link;

    printf("%d has been deleted ",x);
    free(ptr);
    return;
}
void delend()        // delete end
{
   node *tmp1,*tmp2;

   if(front==NULL)
    {  printf("\nEmpty Queue");
       return;
    }
    tmp1=front;
    while(tmp1->link!=NULL)
    {
      tmp2->link=tmp1;
      tmp1=tmp1->link;
    }

    int x=tmp1->val;

    tmp2->link=tmp1->link;
    tmp1->link=NULL;
   // rear=tmp2;
    printf("%d has been deleted ",x);
    free(tmp1);
    return;
}

void display()
{
   if (rear==NULL)
      {  printf("Empty Queue ");
	 return;
      }
    node *ptr;
    ptr=front;
    printf("\nQueue status \n");
    do
    {
       printf("%d ",ptr->val);
       ptr=ptr->link;
    } while(ptr!=NULL);
   return;
}

int main()
{
front=NULL;
rear=NULL;

int ch,pos;
do{
cls();
printf("\n1. Insert Beginning");
printf("\n2. Insert Eng");
printf("\n3. Insert Middle");
printf("\n4. Delete Beginning");
printf("\n5. Delete Eng");
printf("\n6. Delete Middle");
printf("\n7. Display ");
printf("\n8. Exit");
printf("\nEnter your choice ");
scanf("%d",&ch);
switch(ch)
{
	case 1:
	  insbeg();
	  break;
	case 2:
	  insend();
	  break;
	case 3:
	  printf("Enter the position ");
	  scanf("%d",&pos);
	  insmid(pos);
	  break;
	case 4:
	  delbeg();
	  break;
	case 5:
	  delend();
	  break;
	case 6:
	 // delmid();
	  break;
	case 7:
	  display();
	  break;
	case 8:
	    printf("\nThank you...");
	    break;
	default:
	    printf("\nWrong choice ");
}
getch();
} while(ch!=8);
return EXIT_SUCCESS;
}