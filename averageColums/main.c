#include <stdio.h>
#include <stdlib.h>

#define col 4
#define row 3
int main()
{
    int arr[row][col] ={0};
    int val;
/// take the arr from user

    for(int i = 0; i < row; i++){
        for(int j =0; j < col; j++)
            {
             scanf("%d",&val);
             arr[i][j] = val;
            }
    }
    int average[col]={0};
    int sum =0;
    /// outer loop it the colums and inner loop is the avera

    for(int i =0; i < col;i++)
        {
            for(int j = 0; j < row; j++)
            {
                sum+= arr[j][i];
            }
            average[i]=sum;
            sum = 0;
        }
    for(int i =0; i < col; i++)
    printf("\n%d Col : %d\n", i+1,average[i]);
    return 0;
}
