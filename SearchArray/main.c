#include <stdio.h>
#include <stdlib.h>
#define size 5
int main()
{
    int arr[size]={0}, val;
    /// Taking array
    printf("Enter the values : ");
    for(int i =0; i < size; i++)
    {
        scanf("%d",&val);
        arr[i]= val;
    }

    /// scanning value
    printf("Enter the value You're Searching for : ");
    scanf("%d",&val);

    /// searching
    for(int i =0; i < size; i++){
        if(val == arr[i])
        printf("The element is in Index of : %d\n",i);
    }
    ///


    return 0;
}


