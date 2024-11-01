#include <stdio.h>
#include <stdlib.h>

int main()
{
/// create two arrays
    int arr1[3][3]=
    {{1,2,3},
    {4,5,6},
    {7,8,9}};
    int arr2[3][2] =
    {{1,4}
    ,{2,5},
    {3,6}};
    int arr3[3][2];
/// start with the first array and multiply first row with column in the second array
    /// 2 for loops outer loop loop on row for arr1 and second for loop for colums in arr2
    for(int i = 0; i < 3; i++) // columns
    {
        int sum = 0;
        for(int k = 0; k < 2; k++)
        {
        for(int j = 0; j < 3; j++) // columns
        {
            sum +=arr1[i][j]*arr2[j][k];

        }
            arr3[i][k]= sum;
            sum =0;
        }
    }

    /// print 3
        for(int i = 0; i < 3; i++ )
        {
            for(int j =0; j < 2;j++)
            {
                printf("%d ",arr3[i][j]);
            }
            printf("\n");
        }

    return 0;
}


/// start with the first array and multiply first row with column in the second array
    /// 2 for loops outer loop loop on row for arr1 and second for loop for colums in arr2
    /// sum indexs and but them in one variate
    /// add result to the new matrix 3x2
