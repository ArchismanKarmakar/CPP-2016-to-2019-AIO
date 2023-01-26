#include<stdio.h>
#include<stdlib.h>
#define cls() system("cls");

struct record{

    record *fwd;
    int val;
}*top,*end;

//node *start;

void insbeg()
{
    int data;
    record *ptr;
    ptr=(record*)malloc(sizeof(record));
    if(ptr==NULL)
    { printf("\nStack full ");
      return;
    }
    printf("\nEnter data:");
    scanf("%d",&data);
    ptr->val=data;
    ptr->fwd=NULL;
    if (end==NULL)
    {
        top=ptr;
        end=ptr;
    }
    else
    {
        /* code */
        ptr->fwd=top;
        top=ptr;

    }
    
    printf("\nIns success");
    //getch();
    return;

}

void delbeg()
{

    //record *ptr;
    //ptr=(record*)malloc(sizeof(record));
    //ptr=top;
    if(top==NULL)
    {
        printf("Empty");
        return;
    }

    printf("\nDeleted %d ",top->val);
    if(top==end){
        top=NULL;
        end=NULL;}
        else
        top=top->fwd;
    
    //ptr=NULL;
    
    //getch();
    //free(ptr);
    return;
}

void insend(){

    int data;
    record *ptr;
    ptr=(record*)malloc(sizeof(record));
    if(ptr==NULL)
    { printf("\nQueue full ");
      return;
    }
    printf("\nEnter data:");
    scanf("%d",&data);
    
    ptr->val=data;
    ptr->fwd=NULL;

    if(end==NULL)
    {
        top=ptr;
        end=ptr;
    }
    else
    {
        end->fwd=ptr;
        end=end->fwd;
    }

    return;
}

void delend(){

    if(top==end){
        top=end=NULL;
        return;
    }
    record *ptr;
    ptr=top;
    if(ptr==end)
        end=ptr=NULL;
    else
        ptr=ptr->fwd;
    return;
}

void display()
{

    if(top==NULL)
        {
            printf("Empty");
            return;
        }
    record *ptr;
    ptr=top;
    printf("Queue stat:\n\n");
    do{
        printf("%d  ",ptr->val);
        ptr=ptr->fwd;
    }while(ptr!=NULL);
    return;
    
}


int main()
{
    int opt;
    do{
    //cls();
    printf("\n\n");
    printf("\n1. Insbeg");
    printf("\n2. Insmid");
    printf("\n3. Insend");
    printf("\n4. Delbeg");
    printf("\n5. Delmid");
    printf("\n6. Delend");
    printf("\n7. Display");
    printf("\n8. Quit");
    printf("\nEnter your choice");
    scanf("%d",&opt);
    switch(opt){

        case 1:
            insbeg();
        break;
        case 2:

        break;
        case 3:
            insend();
        break;
        case 4:
            delbeg();
        break;
        case 5:

        break;
        case 6:

        break;
        case 7:
            display();
        break;
        case 8:

        break;
        default:
        printf("\n\nError");
    }
    }while(opt!=8);
    return EXIT_SUCCESS;

}