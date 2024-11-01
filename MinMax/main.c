#include <stdio.h>
#include <stdlib.h>
#define size 5
int main()
{
    int arr[size]={0}, min, max,val;
    /// Taking array
    printf("Enter the values : ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d",&val);
        arr[i]= val;
         if(i == 0)
            min= max= arr[i];
        if(val < min) min = val;
        if(val > max) max = val;
    }
    printf("The Min Number is :%d\n The Max Number is : %d" ,min,max);
        return 0;
}
