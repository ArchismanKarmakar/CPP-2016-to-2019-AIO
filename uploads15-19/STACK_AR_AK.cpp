#include<stdio.h>
#include<stdlib.h>
#define cls() system("cls");

int arr[5];
int top;

void insbeg(){
    if(top==4){
        printf("\nFailed");
        return;
    }
    int n;
    printf("\nEnter data: ");
    scanf("%d",&n);
    arr[++top]=n;
    printf("\nSuccess");
    return;
}

void delbeg(){
    if(top==-1){
        printf("\nEmpty");
        return;
    }
    int n=arr[top];
    top--;
    printf("\n%d deleted",n);
    return;
}

void disp(){
    if(top==-1){
        printf("\nEmpty");
        return;
    }
    printf("\nStack Stat: \n\n");
    for(int i=0;i<=top;i++){
        printf("%d ",arr[i]);
    }
    return;
}

int main(){
    int ch,top=-1;
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