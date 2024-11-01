#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    do
    {
        ch = getche();
        if(ch == -32)

            {   ch = getche();
                printf("Extended key %d \n", ch);
            }
        else
            printf("Normal key %d \n", ch);


    }while(ch != 13);
    return 0;
}
