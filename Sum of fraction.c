#include<stdio.h>
int main()
{
    int n;
    double ans=0.0;
    printf("Enter the numbers which you want to add\n ");
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        ans=ans+1.0/i;
    }
    printf("The sum of the series of given numbers is %f\n",ans);
    return 0;
}
