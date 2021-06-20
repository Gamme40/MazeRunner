#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ESD.h"

#define ESC 27
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77

/* KNOWN BUGS
*   - After entering a game and pressing buttons, then leaving, one will have to 'Q' twice to actually exit.
*/

// Global Variable
int arrVar[10];
int score;

// Function definition which reads from a file
void initialize();
void readData();
void menuOptions();
void progInfo();
void startGame();
void settingsGame();
void newPlayer();
void newGameBoard();
void generateItemLocation();

// Colour text definitions - 0: Red, 1: Green, 2: Yellow, 3: Blue
// Usage Example: colour("This is a String.", 2); // This will print "This is a String" in Yellow.
void colourize(const char *s, const char *code);
void colour(const char *s, int n);

// Storage for the character
char keyPress;
char gamePress;

// Storage for maze runner
struct mazeRunner playerOne;

// Storage for game board attributes
struct gameBoard boardOn;

int main()
{
    system("cls");
    generateItemLocation();
    menuOptions();
    return 0;

    /*
    // Read Data in from .txt file:
    int i;
    readData();

    for(i=0; i<10; i++){
        printf("The value of entry %d is: %d\n",i ,arrVar[i]);
    }
    return 0;*/
}

void initialize()
{
    //playerOne.xyposition
}

// Reads from the .txt file "data.txt"
void readData()
{
    FILE *fp;
    char buf[10];
    int i, x;

    fp = fopen("data.txt", "rt");
    printf("%d\n",fp);

    for(i=0; i<10; i++){
            fgets(buf, 4, fp);
            printf("%s\n", buf);
            x = atoi(buf);
            arrVar[i] = x;
    }

    fclose(fp);
}

void menuOptions()
{
    colour("\tMenu\n", 2);
    printf("Press ");
    colour("I", 0);
    printf(" for program info.\n");


    printf("Press ");
    colour("G", 0);
    printf(" to start game.\n");


    printf("Press ");
    colour("S", 0);
    printf(" for game settings.\n");


    printf("Press ");
    colour("ESC", 0);
    printf(" exit game.\n");

    do
    {
        keyPress = getch();

        switch(keyPress)
        {
            case 'i':
                system("cls");
                progInfo();
                getch();
                break;
            case 'g':
                system("cls");
                startGame();
                getch();
                break;
            case 's':
                system("cls");
                settingsGame();
                getch();
                break;
            case ESC:
                printf("\nWe have ended the game.");
                return 0;
                break;

        }
        system("cls");
        menuOptions();
    } while(TRUE);

}

void progInfo()
{
    colour("\tProgram Operation\n", 2);
    printf("Find and collect the hidden objects.\n");
    printf("Drop the objects at the drop zone.\n");

    printf("Press ");
    colour("UP-Arrow", 0);
    printf(" to move player up.\n");

    printf("Press ");
    colour("DOWN-Arrow", 0);
    printf(" to move player DOWN.\n");

    printf("Press ");
    colour("LEFT-Arrow", 0);
    printf(" to move player LEFT.\n");

    printf("Press ");
    colour("RIGHT-Arrow", 0);
    printf(" to move player RIGHT.\n");


    printf("Press ");
    colour("P", 0);
    printf(" to pick up an object.\n");


    printf("Press ");
    colour("D", 0);
    printf(" to drop an object.\n");


    printf("Press ");
    colour("Q", 0);
    printf(" to quit and return to main menu.\n");

    colour("\tPress any key to continue.\n", 2);
}

void startGame()
{
    score = 0;
    printf("\n\nScore: %d", score);

    // Generate and Print the board.
    printf("\nBoard has been generated");

    // Create Struct of player and Board

    // Wait for user input.
    do
    {
        gamePress = getch();
        switch(gamePress)
        {
            case UP_ARROW:
                printf("\nUP Arrow was pressed");
                break;
            case DOWN_ARROW:
                printf("\nDOWN Arrow was pressed");
                break;
            case LEFT_ARROW:
                printf("\nLEFT Arrow was pressed");
                break;
            case RIGHT_ARROW:
                printf("\nRIGHT Arrow was pressed");
                break;
            case 'p':
                printf("\nPick up object");
                break;
            case 'd':
                printf("\nDrop off object");
                break;
        }

    }while(gamePress != 'q');

    printf("\nPress a key to go to main menu.");
    // Switch-Case to determine what to do with user input.
    return 0;
    // Change board, clear screen and reprint the board.

}

void newPlayer()
{

}

void newGameBoard ()
{
    // Read the data file and then store into the
}

void generateItemLocation()
{
    int counter = 0;
    // Access the game board array
    for(int z = 0; z<5; z++)
    {
        counter++;
        // Generate item x location
        int xLocItem = rand() % 75;
        // Generate item y location
        int yLocItem = rand() % 25;

        // Assign item location to
        //gameBoard.xyItem[z] = info
        printf("XY of %d: %d %d\t", counter, xLocItem, yLocItem);
        printf("\n");
    }
}

void settingsGame()
{
    colour("\tSettings\n", 2);
    printf("Use the arrow keys to select the colour.\n");
    printf("Press ");
    colour("ENTER ", 0);
    printf("to set colour.\n");
    printf("Colour: \n");

}

void colourize(const char *s, const char *code) {
  printf("%s%s\e[0m", code, s);
}

void colour(const char *s, int n) {
  char t[32];
  sprintf(t, "\e[%dm", 31 + n % 7);
  colourize(s, t);
}

struct mazeRunner{
    // Initialise at index [79,24]
    int xyposition[1][1];
    int hasObject; //99 - Yes 98- No
} mRunner;

struct gameBoard {
    /* How many items on the board?
    * Creates this matrix, should populate these with coordinates randomized between a row [0:74] and column [0:24]
    * [00] [01]
    * [10] [11]
    * [20] [21]
    * [30] [31]
    * [40] [41]
    */
    int xyItem [2][5];

    // Initialise as a StartDrop point x [74:84] and y as 24.
    int xyStartDrop[2][5];

    int gameScore;
} gBoard;

