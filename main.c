#include <stdio.h>
#include <stdlib.h>
#include "ESD.h"

// Global Variable
int arrVar[10];

// Function definition which reads from a file
void readData();

int main()
{
    printf("Hello world!\n");
    // Read Data in from .txt file:
    int i;
    readData();
    for(i=0;i<10;i++)printf("The value of entry %d is: %d\n",i ,arrVar[i]);
    return 0;
}

// Reads from the .txt file "data.txt"
void readData()
{
    FILE *fp;
    char buf[10];
    int i,x;

    fp=fopen("data.txt", "rt");
    printf("%d\n",fp);
    for(i=0;i<10;i++)
    {
            fgets(buf,4,fp);
            printf("%s\n",buf);
            x=atoi(buf);
            arrVar[i]=x;
    }
    fclose(fp);
}
