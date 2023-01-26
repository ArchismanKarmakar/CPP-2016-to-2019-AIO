#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<fstream>
#include<math.h>
#include<bitset>
//#include<bits/stdc++.h>
using namespace std;
#define cls() system("cls");
#define SIZE 1000
#define halt() cin.get();

/*including user def functions*/
#include<E:\Program_Files_temp\VS_Code_Lang\CC++\IMPD\encode.h>
//#include<decode.cpp>

char login[20],str[1000],str1[1000];

int main()
{
    //encode obj1;

    /*printf("\nEnter password: ");
    fflush(stdin);
    gets(login);
    lgin();*/
    /*printf("Encoding HEX is: ");
    puts(login);*/
    
    cout<<"\n\nEnter data: ";
    //fflush(stdin);
    
    cin.clear();
    cin>>str;
    //enc();
    //enc();

    //obj1.enc();
    //obj1.enc();

    cout<<"\n\n";

    toHEX(str);
    //puts(base64Encoder(str1,strlen(str1)));
    //cout<<obj1.base64Encoder(str1,strlen(str1));
    halt();
    return EXIT_SUCCESS;
}