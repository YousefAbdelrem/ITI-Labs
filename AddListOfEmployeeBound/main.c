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
void initializeEmployees();
void displayEntity(int ind, int constant);
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
    int id ;
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
    initializeEmployees();
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
    char menu[8][10000] = {"New","Display All","DisPlay By Id","DisPlay By Name" ,"Delete By Id" , "Delete By Name"
     ,"Delete All","Exit"},ch;
    int cursor =0,flag = 1;
    gotoxy(10,10);


    do
    {
        system("cls");
        for(int i =0; i < 8 ; i++)
        {
            gotoxy(45,5 + i*2);
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
                    cursor = 7;
                else
                    cursor--;
                break;
            case Down:
                if(cursor == 7)
                    cursor = 0;
                else
                    cursor++;
                break;
            }
            break;

        case Esc:
            flag =0;
            break;
        case Tap:
            if(cursor == 7)
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
    int ind = 0;
    do
    {
        InputPrintXY(1, 1,"Enter index: ",&ind);
        system("cls");


    }while(ind > 9);

    PrintXYInt(0, 0 , "## Employee Number -->",counter + 1);
    printf("\n-------------------------------------------------------------");
    PrintXY(10,2,"id: ");
    PrintXY(10,4,"Age: ");
    PrintXY(10,6,"commission: ");
    PrintXY(40,2,"Name: ");
    PrintXY(40,4,"Salary: ");
    PrintXY(40,6,"Deduction: ");
    printf("\n\n-------------------------------------------------------------");


    /// for loop start again then wait to enter each fill then exit
    InputPrintXY(10,2,"id: ",&e[ind].id);
    InputPrintXY(10,4,"Age: ",&e[ind].age);
    InputPrintXY(10,6,"commission: ",&e[ind].commission);
    PrintXY(40,2,"Name: ");

    char ch;
    int count = 0;
    while(ch != 13)
    {
        ch = getche();
        e[ind].name[count++] = ch;
    }
    InputPrintXY(40,4,"Salary: ",&e[ind].salary);
    InputPrintXY(40,6,"Deduction: ",&e[ind].deduction);
    system("cls");
    printf("------------------------------------");
    PrintXYStr(10, 2, "Name:",e[ind].name);
    PrintXYInt(30, 2, "Net Salary = ",(e[ind].salary + e[ind].commission - e[ind].deduction) );
    printf("\n\n------------------------------------");
    counter++;
    waitForEsc();
    DisplayMenu();
}

void DisplayEmployee()
{
    int constant = 0;
    if(counter != 0){
    for(int i = 0; i < 10; i++)
    {
    if(e[i].id != -1)
    {
    displayEntity(i, constant);
    constant +=1;
    }
    }
    }else
    {   textattr(3);
        printf("#There is no data for employees yet to display ");
    }

   waitForEsc();

}

void displayEntity(int ind, int constant)
{
    PrintXYInt(0, constant * 8 , "## Employee Number -->",constant + 1);
    PrintXYInt(10, 2 + constant * 8, "Id:", e[ind].id);
    PrintXYInt(10, 4 + constant * 8, "Age:", e[ind].age);
    PrintXYInt(10, 6 + constant * 8, "Commission:", e[ind].commission);
    PrintXYStr(40, 2 + constant * 8, "Name:", e[ind].name);
    PrintXYInt(40, 4 + constant * 8, "Salary:", e[ind].salary);
    PrintXYInt(40, 6 + constant * 8, "Deduction:", e[ind].deduction);
    printf("\n-------------------------------------------------------------\n");
};

void waitForEsc()
{
    char ch = getche();
    if(ch == Enter || Esc)
    {
        DisplayMenu();
    }
}

void initializeEmployees() {
    for (int i = 0; i < 10; i++) {
        e[i].id = -1;
    }
}

// Usage


/// sturct id ---> | 11 | 12 |
