#include<stdio.h>
int main()
{
    int n,i;
    int *arr;
    int min, max;
    printf("Enter the size of the array\n");
    scanf("%d",&n);

    arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter %d elements:\n"n);
    for(i=0;i<n;++i)
    {
     scanf("%d",&arr[i]);
    }
    max=min=arr[0];
    for(i=1;i<n;++i)
    {
        if(arr[i]>max)
           max=arr[i];
        if (arr[i]<min)
           min=arr[i];
    }
    printf("The maximum value element in the array is: %d\n",max);
    printf("The maximum value element in the array is: %d\n",min);
    return 0;
}
