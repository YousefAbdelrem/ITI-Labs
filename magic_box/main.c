#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void gotoxy( int column, int line );

int main()
{
    int size =0;
    do
    {
        printf("Enter odd size");
        scanf("%i", &size);

    }while(size % 2 == 0);

    int row = 1;
    int column = size/2 + 1;
    for(int i = 1; i <= size * size; i++)
    {
        gotoxy(column*3, row*3 );
        printf("%i",i);
        if(i % size != 0)
        {
            column--;
            row--;
            if(column < 1){column = size;}
            if(row < 1){row = size;}
        }
        else
        {
            row++;
            if(row > size) row =1; /// why it's useless
        }
    }
    return 0;
}

/// why
void gotoxy( int column, int row )
{
    COORD coord;
    coord.X = column;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

