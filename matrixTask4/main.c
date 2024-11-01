#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1[3][2]={{1,2},{3,4},{5,6}};
    int arr2[2][1]={{1},{2}};
    int newArr[3][1]={0};

    for(int i= 0; i < 3; i++) /// rows
    {
    /// outer loop will loop on the small matrix
        int sum = 0;
        for(int j = 0; j < 2; j++) /// 2 colums
            {
               sum+= arr1[i][j]*arr2[j][0];
            }
    /// add each element to the new array
        newArr[i][0] = sum;
        printf("%d \n ",newArr[i][0]); /// why it get printed that way
        sum = 0;
    }
    return 0;
}

