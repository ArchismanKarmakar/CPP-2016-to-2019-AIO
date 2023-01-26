//magic box
#include<stdio.h>

int main()
{
	int n[3][3],a,r=0,c=1,i,j; //first row second coloumn
	//clrscr();
	printf("Enter the starting number");
	scanf("%d",&a);
    //	n[r][c]=a++;

	for(i=0;i<9;) //3x3=9
	{
		n[r][c]=a;//first number will be printed on first row second coloumn
			  printf("\n%d %d %d  \n",a,r,c);
			getc(stdin);
		i++;
		r--;
		c++;
		if(i%3==0)
		{
			r+=2;
			c--;
		}
		else
		{
		if(r<0)     //ensure the it does not get out of array limit
			r=2;
		 if(c>2)
			c=0;
		}
		a++;

	}
	printf("\n the array is:\n");
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			printf("%2d  ",n[i][j]);
		}
		printf("\n");
	}
	getc(stdin);
}