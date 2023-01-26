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
char map86[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$%&()*+-;<=>?@^_`{|}~";
char map64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char login[20],str[1000],str1[1000];

class decode{
            public:
                        void dec();
                        //void BINtoSTR();
                        string HEXtoSTR(string hex);
                        char* base64Decoder(char input_str[], int len_str);
                        char* BinaryTostring(char* s);

};

string decode::HEXtoSTR(string hex)
{
    /*char ascii[1000];
    int i,j;

    memset(ascii,0,sizeof(ascii));*/
    
    string ascii = ""; 
    for (size_t i = 0; i < hex.length(); i += 2) 
    { 
        // extract two characters from hex string 
        string part = hex.substr(i, 2);     /* [string_variable].substr(start_point, no_of_characters_to_copy_from_start); is used to
                                                copy a string only upto a particular range not the full one */
    
        // change it into base 16 and  
        // typecast as the character 
        char ch = stoul(part, nullptr, 16);      //Convert string to unsigned long;


        // add this char to final ASCII string 
        ascii += ch; 
    } 
    return ascii; 

}


int main()
{
    cout<<"Enter Data:";
    cin.clear();
    cin>>str;
    halt();


    return EXIT_SUCCESS;
}