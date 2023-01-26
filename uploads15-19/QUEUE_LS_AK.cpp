#include<stdio.h>
#include<stdlib.h>
#define cls() system("cls");

struct node{
    node *link;
    int val;
}*top,*end;

void insend(){
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL){
        printf("\nFailed");
        return;
    }
    int n;
    printf("\nEnter data: ");
    scanf("%d",&n);
    ptr->val=n;
    ptr->link=NULL;
    if(top==NULL){
        top=ptr;
        end=ptr;
    }
    end->link=ptr;
    end=end->link;
    printf("\nSuccess");
    return;
}

void qurev(){
    struct node *prevNode, *curNode;

    if(top != NULL)
    {
        prevNode = top;
        curNode = top->link;
        top = top->link;

        prevNode->link = NULL; // Make first node as last node

        while(top != NULL)
        {
            top = top->link;
            curNode->link = prevNode;

            prevNode = curNode;
            curNode = top;
        }

        top = prevNode; // Make last node as head

        printf("SUCCESSFULLY REVERSED LIST\n");
    }
}

void insbeg(){
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL){
        printf("\nFailed");
        return;
    }
    int n;
    printf("\nEnter data: ");
    scanf("%d",&n);
    ptr->val=n;
    if(top==NULL)
    {
        //top=ptr;
        end=ptr;
    }
    ptr->link=top;
    top=ptr;
    printf("\nSuccess");
    return;
}

void delbeg(){
    if(top==NULL){
        printf("\nEmpty");
        return;
    }
    int n=top->val;
    top=top->link;
    printf("\n%d deleted",n);
    return;
}

void delend(){
    if(end==NULL){
        printf("\nEmpty");
        return;
    }
    node *ptr;
    ptr=top;
    if(top==end)
    {
        printf("\n%d deleted",top->val);
        top=NULL;
        end=NULL;
        return;
    }
    else if(top->link==end){
        printf("\n%d deleted",end->val);
        end=top;
        end->link=NULL;
        return;
    }
    do{
    ptr=ptr->link;
    }while(ptr->link!=end);
    printf("\n%d deleted",end->val);
    end=ptr;
    ptr->link=NULL;
    return;
}

void disp(){
    if(top==NULL){
        printf("\nEmpty");
        return;
    }
    node *ptr;
    ptr=top;
    printf("\nQueue stat\n\n");
    do{
        printf("%d ",ptr->val);
        ptr=ptr->link;
    }while(ptr!=NULL);
    return;
}



int main(){
    int ch;
    do{
    printf("\n1.Ins \n2.Del \n3.Disp \nExit \n\nEnter choice:");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            insbeg();
            break;
        case 2:
            delend();
            break;
        case 3:
            disp();
            break;
        case 4:
            printf("\nClosing");
            break;
        default:
            printf("\nError");
        case 5:
            qurev();
            break;
    }}while(ch!=4);
    return EXIT_SUCCESS;
}