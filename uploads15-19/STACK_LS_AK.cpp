#include<stdio.h>
#include<stdlib.h>
#define cls() system("cls");

struct node{
    node *link;
    int val;
}*top;


void insbeg(){
    int n;
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL){
        printf("\nFailed");
        return;
    }
    printf("\nEnter data: ");
    scanf("%d",&n);
    ptr->val=n;
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
    //node *ptr;
    int x=top->val;
    top=top->link;
    printf("\n%d Deleted",x);
    return;
}

void disp(){
    node *ptr;
    if(top==NULL){
        printf("\nEmpty");
        return;
    }
    printf("\nStack stat:\n\n");
    ptr=top;
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
            delbeg();
            break;
        case 3:
            disp();
            break;
        case 4:
            printf("\nClosing");
            break;
        default:
            printf("\nError");
    }}while(ch!=4);
    return EXIT_SUCCESS;
}