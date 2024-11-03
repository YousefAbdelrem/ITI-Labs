#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define Extended -32
#define Enter 13
#define Esc 27
#define Home 71
#define End 79
#define Up 72
#define Down 80
#define left 75
#define right 77
#define Tap 9
#define backspace 8
void textattr(int i);
void gotoxy( int column, int line );
int main()
{
    int first, curr,last;
    char arr[30],flag = 1;
    char *pfirst, *pcurr, *plast;
    pfirst = pcurr = plast = arr;
    first = curr = last = 0;
    for(int i = 0; i < 30; i++)
    {
        gotoxy(20+i,10);
        textattr(2);
    }

    do
    {
        gotoxy(20 + curr,10);
        char ch = getch();

        switch(ch)
        {
        case Extended:
           ch = getch();
            switch(ch)
            {
            case left:
                if(curr > first)
                {
                    curr--;
                    pcurr--;
                }
                else
                {
                    /// curr == first;
                }
                break;
            case right:
                if(curr < last)
                {
                    curr++;
                    pcurr++;
                }
                break;

            case Home :
                curr = first;
                break;
            case End :
                curr = last;
                break;


            }

            break;
        case Esc:
        case Enter:
            *pcurr = '\0';
            flag = 0;
            break;
        case backspace:
            /// at the end curr == last
            if(curr == last)
            {
                gotoxy(20+curr - 1,10) ;
                printf(" ");
                curr--;
                last--;
                pcurr--;
            }
            break;

        default :

            if(curr == last)
            {
                if(last < 30)
                {
                    *pcurr = ch;
                    pcurr++;
                    plast++;
                    curr++;
                    last++;
                    printf("%c",ch);
                }
            }
            else
            {
                *pcurr = ch;
                pcurr++;

                curr++;
                printf("%c",ch);
            }
        }
    }
    while(flag);

    gotoxy(20,14);
    printf("\nOutput: %s",arr);
    return 0;
}




/// create 3 val & 3 pointers
/// choose the key
/// then increase or decrease pointers int curr valu
/// print on screen



void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
