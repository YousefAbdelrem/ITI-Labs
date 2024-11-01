#include <stdio.h>
#include <stdlib.h>

/// the output is wrong??
int main()
{
    /// first name
    char fn[10],ln[10];
    /// get them
    printf("Enter Your First Name: ");
    scanf("%s",&fn);
    printf("Enter Your Last Name: ");
    scanf("%s",&ln);
    /// put them in full name arr
    char fullName[21] = "";
    strcat(fullName, fn);
        strcat(fullName, " ");
    strcat(fullName, ln);
    /// print arr using get()
    printf("%s", fullName);
    return 0;
}
