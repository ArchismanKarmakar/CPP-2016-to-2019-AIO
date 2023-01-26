#include <iostream>
#include <cstdlib>
using namespace std;

#define cls system("cls");

int fact(int n)
{
     if (n > 1)
     {
          n = n * fact(n - 1);
     }
     return n;
}

int main(int argc, char *argv)
{
     // This is a template code
     int n;
     cin >> n;
     cout << fact(n) << endl;

     return EXIT_SUCCESS;
}