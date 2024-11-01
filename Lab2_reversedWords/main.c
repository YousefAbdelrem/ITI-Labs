#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[50],ch;
    int count=0;
    printf("Enter A Word to be Reversed: \n");
    do
    {
    ch = getche();
    arr[count++]= ch;
    }while(ch != 13);
    arr[count - 1] = '\0';

    for(int i = count - 1; i >= 0; i--)
    {
      printf("%c",arr[i]);
    }
    return 0;
}
