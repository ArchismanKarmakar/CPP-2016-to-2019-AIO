//#include<stdio.h>
//#include<conio.h>
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
//#define halt() system("PAUSE");
#define halt() cin.get();
char map86[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$%&()*+-;<=>?@^_`{|}~";
char map64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


/*struct node
{ int n;
  node *p;
};
node *front=NULL,*end=NULL;

*/

char login[20],str[1000],str1[1000];


class encode{
            public:
                        void toHEX();
                        //void toBIN();
                        char* base64Encoder(char input_str[], int len_str); 
                        char* stringToBinary(char* s);
                        void enc();

};




char* encode::stringToBinary(char* s)
{
    if(s == NULL) return 0; /* no input string */
    char *binary = (char *) malloc(sizeof(s)*8);
    strcpy(binary,"");
    char *ptr = s;
    int i;

    for(; *ptr != 0; ++ptr)
    {
        /* perform bitwise AND for every bit of the character */
        for(i = 7; i >= 0; --i){
            (*ptr & 1 << i) ? strcat(binary,"1") : strcat(binary,"0");
        }
    }
    return binary;
}



void encode::toHEX()
{

        /*unsigned */char strH[1000];
    int i,j;

    memset(strH,0,sizeof(strH));
     
    /*converting str character into Hex and adding into strH*/
    for(i=0,j=0;i<strlen(str1);i++,j+=2)
    { 
        sprintf((char*)strH+j,"%02X",str1[i]);
        //printf("\n%i",udt);
    }
    strH[j]='\0'; /*adding NULL in the end*/
    //printf("\n\nHEX CODE:%s",strH );
    strcpy(str1,strH);

     /*int binaryNum, hex=0, mul=1, chk=1, rem, i=0;
    char hexDecNum[20];
    //cout<<"Enter any Binary Number: ";
    //cin>>binaryNum;
    while(binaryNum!=0)
    {
        rem = binaryNum%10;
        hex = hex + (rem*mul);
        if(chk%4==0)
        {
            if(hex<10)
                hexDecNum[i] = hex+48;
            else
                hexDecNum[i] = hex+55;
            mul = 1;
            hex = 0;
            chk = 1;
            i++;
        }
        else
        {
            mul = mul*2;
            chk++;
        }
        binaryNum = binaryNum/10;
    }
    if(chk!=1)
        hexDecNum[i] = hex+48;
    if(chk==1)
        i--;
    cout<<"\nEquivalent Value in Hexadecimal: ";
    for(i=i; i>=0; i--)
        cout<<hexDecNum[i];
    cout<<endl;*/
    
}

char* encode::base64Encoder(char input_str[], int len_str) 
{ 
    // Character set of base64 encoding scheme 
    //char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";       
    // Resultant string 
    char *res_str = (char *) malloc(SIZE * sizeof(char)); 
      
    int index, no_of_bits = 0, padding = 0, val = 0, count = 0, temp; 
    int i, j, k = 0; 
      
    // Loop takes 3 characters at a time from  
    // input_str and stores it in val 
    for (i = 0; i < len_str; i += 3) 
        { 
            val = 0, count = 0, no_of_bits = 0; 
  
            for (j = i; j < len_str && j <= i + 2; j++) 
            { 
                // binary of input_str is stored in val 
                val = val << 8;  
                  
                // (A + 0 = A) stores character in val 
                val = val | input_str[j];  
                  
                // loop counter
                
                count++; 
              
            } 
  
            no_of_bits = count * 8;  
  
            // calculates how many "=" to append after res_str. 
            padding = no_of_bits % 3;  
  
            // extracts all bits from val (6 at a time)  
            // and find the value of each block 
            while (no_of_bits != 0)  
            { 
                // retrieve the value of each block 
                if (no_of_bits >= 6) 
                { 
                    temp = no_of_bits - 6; 
                      

                    index = (val >> temp) & 63;  
                    no_of_bits -= 6;          
                } 
                else
                { 
                    temp = 6 - no_of_bits; 
                      
                    // append zeros to right if bits are less than 6 
                    index = (val << temp) & 63;  
                    no_of_bits = 0; 
                } 
                res_str[k++] = map86[index]; 
            } 
    } 
  
    // padding is done here 
    for (i = 1; i <= padding; i++)  
    { 
        res_str[k++] = '='; 
    } 
  
    res_str[k] = '\0'; 
    return res_str; 
  
} 

void encode::enc()
{
    strcpy(str1,str);
    //https://renenyffenegger.ch/notes/development/Base64/Encoding-and-decoding-base-64-with-cpp/index
    //https://www.geeksforgeeks.org/encode-ascii-string-base-64-format/
    //https://www.codechef.com/problems/ENCDEC09
    char vsp;
    strrev(str1);
   
    for(int loop1=0; loop1<int(strlen(str1)/2); loop1++)
    {   vsp=str1[loop1];
        str1[loop1]=str1[int((loop1)/2)];
        str1[(int((loop1)/2))]=vsp;
    }

    for(int loop1=strlen(str1)-1, loop2=int(strlen(str1)/2); loop1>int(strlen(str1)/2) && loop2<strlen(str1); loop1-- && loop2++)
    {

        vsp=str1[loop1];
        str1[loop1]=str1[(loop2)];
        str1[((loop2))]=vsp;

    }

    toHEX();
    strcpy(str,str1);
    std::cout<<"\n\n";
    //puts(str1);
    std::cout<<str1;
    //getchar();
    halt();

}

void lgin()
{
    strcpy(str,login);
    //toHEX();
    //strcpy(login,strrev(str1));   
}


int main()
{
    encode obj1;

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

    obj1.enc();
    obj1.enc();

    cout<<"\n\n";

    //puts(base64Encoder(str1,strlen(str1)));
    cout<<obj1.base64Encoder(str1,strlen(str1));
    //getchar();
    halt();
    return EXIT_SUCCESS;
}