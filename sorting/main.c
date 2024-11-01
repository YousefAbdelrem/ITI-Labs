#include <stdio.h>
#include <stdlib.h>

#define size 5
int main()
{
    int arr[size]= {0}, val;
    /// Taking array
    printf("Enter the values : ");
    for(int i =0; i < size; i++)
    {
        scanf("%d",&val);
        arr[i]= val;
    }
    /// sorting
    for(int i = 0; i < size; i++)
    {
        for(int j = 1; j < size  ; j++)
        {
            if(arr[j] < arr[j-1])
            {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }

    for(int i = 0; i < size; i++)
    {
        printf("%d  ",arr[i]);
    }
    return 0;
}
