#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void textattr(int i);
void gotoxy( int column, int line );
void DisplayEmployee();
void waitForEsc();
void AddEmployee();
void InputPrintXY(int x, int y,int *line,int *var);
void PrintXY(int x, int y,int *line);
void PrintXYInt(int x, int y,int *line,int val);

static counter= 0;
#define Extended -32
#define Enter 13
#define Esc 27
#define Home 71
#define End 79
#define Up 72
#define Down 80
#define Tap 9
struct Employee
{
    int id;
    char name[20];
    int age;
    int ssn;
    int commission;
    int deduction;
    int salary;

};
struct Employee e[10];

int main()
{
    /// display highlighted menu if with add button
    DisplayMenu();
    /// display the details for the employee
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
                textattr(2);
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
            if(cursor == 0)
            {
                system("cls");
                AddEmployee();
                flag = 0;
            }
            else if(cursor == 1)
            {
                system("cls");
                DisplayEmployee();
            };
            break;
        case Home:
            cursor=0;
            break;
        }
    }
    while(flag);
}
void PrintXY(int x, int y,int *line)
{
    gotoxy(x, y);
    printf("%s",line);

}
void PrintXYInt(int x, int y,int *line,int val)
{
    gotoxy(x, y);
    printf("%s %d",line,val);
}
void PrintXYStr(int x, int y,int *line,int *val)
{
    gotoxy(x, y);
    printf("%s %s",line,val);
}


void InputPrintXY(int x, int y,int *line,int *var)
{
    gotoxy(x, y);
    printf("%s",line);
    scanf("%d",var);
}
void AddEmployee()
{
    /// print menu then
    /// print it for the first time and loop on it again but this time wait for the input to get in

    printf("-------------------------------------------------------------");
    PrintXY(10,2,"id: ");
    PrintXY(10,4,"Age: ");
    PrintXY(10,6,"commission: ");
    PrintXY(40,2,"Name: ");
    PrintXY(40,4,"Salary: ");
    PrintXY(40,6,"Deduction: ");
    printf("\n\n-------------------------------------------------------------");


    /// for loop start again then wait to enter each fill then exit
    InputPrintXY(10,2,"id: ",&e[counter].id);
    InputPrintXY(10,4,"Age: ",&e[counter].age);
    InputPrintXY(10,6,"commission: ",&e[counter].commission);
    PrintXY(40,2,"Name: ");

    char ch;
    int count = 0;

    while(ch != 13)
    {
        ch = getche();
        e[counter].name[count++] = ch;
    }
    InputPrintXY(40,4,"Salary: ",&e[counter].salary);
    InputPrintXY(40,6,"Deduction: ",&e[counter].deduction);
    system("cls");
    printf("------------------------------------");
    PrintXYStr(10, 2, "Name:", e[counter].name);
    PrintXYInt(30, 2, "Net Salary = ",(e[counter].salary + e[counter].commission - e[counter].deduction) );
    printf("\n\n------------------------------------");
    counter++;
    waitForEsc();
    DisplayMenu();
}

void DisplayEmployee()
{
    printf("-------------------------------------------------------------");
    PrintXYInt(10, 2, "Id:", e[counter - 1].id);
    PrintXYInt(10, 4, "Age:", e[counter - 1].age);
    PrintXYInt(10, 6, "Commission:", e[counter - 1].commission);
    PrintXYStr(40, 2, "Name:", e[counter - 1].name);
    PrintXYInt(40, 4, "Salary:", e[counter - 1].salary);
    PrintXYInt(40, 6, "Deduction:", e[counter - 1].deduction);
    printf("\n\n-------------------------------------------------------------");
   waitForEsc();

}

void waitForEsc()
{
    char ch = getche();
    if(ch == Enter || Esc)
    {
        DisplayMenu();
    }
}
