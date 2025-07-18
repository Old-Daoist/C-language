#include<stdio.h>
int main()
{
    int x;
    printf("Enter a number\n ");
    scanf("%d",&x);
    if(x%2==0)
        printf("The integer %d is an even number",x);
    else if(x%2!=0)
        printf("The integer %d is an odd number\n",x);
    else
        printf("The integer %d is zero\n",
               x);
    return 0;
}
