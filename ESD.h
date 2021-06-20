#ifndef ESD_H_INCLUDED
#define ESD_H_INCLUDED
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD pos = {x, y};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, pos);
}

void setColor(int c)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, c);
}

void clrscr()
{
    int i,j;
    for(i=0;i<25;i++)
    {
        for(j=0;j<80;j++)
        {
            gotoxy(j,i);
            printf(" ");
        }
    }
    gotoxy(0,0);
}


#endif // ESD_H_INCLUDED
