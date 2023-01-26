#include<stdio.h>
#include<iostream>
#include<conio.h>

#define cls() system("cls");

using namespace std;

class empl
{
    int eno,bsal;
    char enam[20], dept[15];

    public:
    void input()
    {
        std::cout<<"Enter employee no:";
        std::cin>>eno;
        std::cout<<"Enter employee name:";
        fflush(stdin);
        gets(enam);                         //cin.getline(enam,20);
        std::cout<<"Enter department:";
        std::cin>>dept;
        std::cout<<"Enter basic salary";
        std::cin>>bsal;

    }

    
    void display()
    {

        std::cout<<"\nEmp. no"<<eno;        //cout<<"\nEmp. no"<<eno<<endl;
        std::cout<<"\nName"<<enam;          //cout<<"\nName"<<enam<<endl;
        std::cout<<"\nDepartment"<<dept;    //cout<<"\nDepartment"<<dept<<endl;
        std::cout<<"\nBasic. sal"<<bsal;    //cout<<"\nBasic. sal"<<bsal<<endl;
    }
};

int main()
{
    do{
        cls();
        empl obj;
        obj.input();
        obj.display();
        //scanf("%d",&int chk);
    }while(1);
    return EXIT_SUCCESS;
}