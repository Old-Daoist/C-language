#include<stdio.h>
int main()
{
    int x;
    printf("Enter a number\n ");
    scanf("%d",&x);
    if(x>0)
        printf("The integer %d is positive\n",x);
    else if(x<0)
        printf("The integer %d is negative\n",x);
    else
        printf("The integer %d is zero\n",
               x);
    return 0;
}
