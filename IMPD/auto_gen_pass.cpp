#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<fstream>
#include<math.h>
#include<bitset>
#include<cstdlib>
#include<ctime>
#include<sys/stat.h>
#define PL1 50
//#include<bits/stdc++.h>
using namespace std;
#define cls() system("cls");
#define SIZE 1000
//#define halt() system("PAUSE");
#define halt() cin.get();



/*
DETAILS HERE

https://www.delftstack.com/howto/cpp/generate-random-number-in-range-cpp/
*/

char str1[PL1];

class gen{
            protected:
                    int x=1;
                    void agenp()
                    {           
                        //char map100[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$%&()*+-;<=>?@^_`{|}~©®™÷×╣►◄↕☼■è╒⌂";
                        char map100[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*_+=-.:;<>?~`";
                        //char map100[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789@#$%&*_";
                        //char map100[] = "ABCDE0123456789";
                        //string str;
                        int lu=sizeof(str1),uu=sizeof(map100);

                        int genap;//,cond1=1;
                        srand(time(NULL));
                                for(int i=0; i<=PL1;i++)
                                {
                                    //do{
                                        genap=((rand()%(uu-lu+1))+lu);
                                               
                                        //}while(cond1!=0);
                                        //str1[i]=map100[genap];
                                        cout<<map100[genap];
                                }
                        //strcpy(std::string str1,str);

                    }

            public:
                    void callm(){

                        agenp();
                    }
};


class dbmss{


    public:

    private:

    protected:
    
};

void flfn()
{
    fstream fptr;
    char strname[12];
    bool cond1=false;
    
     
    do{
    // Function: fileExists
/**
    Check if a file exists
@param[in] filename - the name of the file to check

@return    true if the file exists, else false

*/
    cout<<"\n\nEnter file name to store: ";
    cin>>strname;
    ifstream ifile;
        ifile.open(strname);
        if(ifile) {
            cout<<"\n\nfile exists";
            cond1=true;
        } else {
            fptr.open(strname,ios::in | ios::binary | ios::out);
            cond1=false;
            //break;
        }
    }while(cond1=true);
}


int main()
{
    gen objm;
    //cin>>str;
    objm.callm();
    //cout<<str1;
    //flfn();
    return EXIT_SUCCESS;
}