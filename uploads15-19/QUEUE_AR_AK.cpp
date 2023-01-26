#include<stdio.h>
#include<stdlib.h>
#define cls() system("cls");

int arr[5];
int top,end;

void insend(){
    if(top==4){
        printf("\nFailed");
        return;
    }
    int n;
    printf("\nEnter data: ");
    scanf("%d",&n);
    arr[++top]=n;
    if(top==0){
        end=top;
    }
    printf("\nSuccess");
    return;
}

void delbeg(){
    if(top==-1){
        printf("\nEmpty");
        return;
    }
    int n=arr[end];
    if(end==top){
        end=-1;
        top=-1;
        printf("\n%d deleted",n);
        return;
    }
    end++;
    printf("\n%d deleted",n);
    return;
}

void disp(){
    if(top==-1){
        printf("\nEmpty");
        return;
    }
    printf("\nQueue stat\n\n");
    for(int i=end;i<=top;i++){
        printf("%d ",arr[i]);
    }
    return;
}

int main(){
    top=-1;
    end=-1;
    int ch;
    do{
    printf("\n1.Ins \n2.Del \n3.Disp \nExit \n\nEnter choice:");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            insend();
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