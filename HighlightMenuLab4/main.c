#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void textattr(int i);
void gotoxy( int column, int line );

#define Extended -32
#define Enter 13
#define Esc 27
#define Home 71
#define End 79
#define Up 72
#define Down 80
#define Tap 9


int main()
{
    DisplayMenu();
    return 0;
}

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

void DisplayMenu()
{
    char menu[3][10000] = {"Add","Display","Menu"},ch;
    int cursor =0,flag = 1;
    gotoxy(10,10);


    do
    {
        system("cls");
        for(int i =0; i < 3 ; i++)
        {
            gotoxy(55,10 + i*2);
            if(cursor == i)
            {
                textattr(4);
            }
            else
                textattr(7);
            printf("%s",menu[i]);

        }
        /// wait for the cursor to change
        /// scanf ch then change cursor value depending on the key value
        ch = getch();
        switch(ch)
        {
        case Extended:
            ch = getch();
            switch (ch)
            {
            case Up:
                if(cursor == 0)
                    cursor= 2;
                else
                    cursor--;
                break;
            case Down:
                if(cursor == 2)
                    cursor= 0;
                else
                    cursor++;
                break;
            }
            break;

        case Esc:
            flag =0;
            break;
        case Tap:
            if(cursor == 2)
                cursor= 0;
            else
                cursor++;
            break;
        case Enter:
            break;
        case Home:
        cursor=0;
        break;
        }


    }
    while(flag);
}

