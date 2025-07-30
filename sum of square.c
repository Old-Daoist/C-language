//program to add the square of n numbers
#include<stdio.h>
int main()
{
    int n;
    int sq=0;
    printf("Enter the numbers which you want to add\n ");
    scanf("%d",&n);
    for(int i=0;i<=n;++i)
    {
        sq+=i*i;
    }
    printf("the sum of square of the first %d numbers are : %d\n",n,sq);
    return 0;
}
