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
int xLocArrItem [5];
int yLocArrItem [5];
int tempHold;

// In a grid layout of 40x15 elements, 106 of them are walls.
int wallCoordinates[106] = {1, 2 , 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
                            16, 31, 46, 61, 76, 91, 106, 121, 136, 151, 166, 181,
                            196, 211, 226, 241, 256, 271, 286, 301, 316, 331, 346,
                            361, 376, 391, 406, 421, 436, 451, 466, 481, 496, 511,
                            526, 541, 556, 571, 586, 587, 588, 589, 590, 591, 592,
                            593, 594, 595, 596, 597, 598, 599, 600, 30, 45, 60, 75,
                            90, 105, 120, 135, 150, 165, 180, 195, 210, 225, 240, 255,
                            270, 285, 300, 315, 330, 345, 360, 375, 390, 405, 420, 435,
                            450, 465, 480, 495, 510, 525, 540, 555, 570, 585};


int gameBoardWalls[40][15];
char gBMap[40][15];

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
void generateStartDrop();
void generateGameFile();
void convertIntArrtoCharArr();
void printBoard();

// Colour text definitions - 0: Red, 1: Green, 2: Yellow, 3: Blue
// Usage Example: colour("This is a String.", 2); // This will print "This is a String" in Yellow.
void colourize(const char *s, const char *code);
void colour(const char *s, int n);

// Storage for the character
char keyPress;
char gamePress;

struct mazeRunner{
    // Initialise at index [39,14]
    int xyposition[1][2];
    int hasObject; //99 - Yes 98- No
} mRunner;

struct gameBoard {
    /* How many items on the board?
    * Creates this matrix, should populate these with coordinates randomized between a row [0:34] and column [0:14]
    * {[x][y]} {[x][y]} {[x][y]} {[x][y]} {[x][y]}
    */
    int xItemCo [5];
    int yItemCo [5];

    // Initialise as a StartDrop point x-index [35:39] and y-index as 14.
    int xyStartDrop[2][5];

    // Game Board array
    int gameBoardText[40][15];

    int gameScore;
} gBoard;


// Storage for maze runner
struct mazeRunner playerOne;

// Storage for game board attributes
struct gameBoard boardOne;


int main()
{
    system("cls");
    initialize();
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
    generateItemLocation();
    printf("Generation of item locations done.\n");
    boardOne.gameScore = 0;
    printf("Reset Game Score.\n");
    generateStartDrop();
    printf("Generated the start of player and drop off point.\n");
    generateGameFile();
    printf("Generated the basic game file.\n");
    loadStructToArray();
    printf("Loaded storage and generated walls.\n\n");
    //generateStartDrop();
    /* DEBUG
    for(int i = 0; i < 5; i++)
    {
        printf("XY: %d %d\n", boardOne.xItemCo[i], boardOne.yItemCo[i]);
    }
    */
}
void loadStructToArray()
{
    for(int x = 0; x < 40; x++)
    {
        for(int y = 0; y < 15; y++)
        {
            tempHold = boardOne.gameBoardText[x][y];
            for (int z = 0; z < 106; z++)
            {
                if(boardOne.gameBoardText[x][y] == wallCoordinates[z])
                {
                    tempHold = 0;
                }
                gameBoardWalls[x][y] = tempHold;
            }
        }
    }
}

void printBoard()
{
    for(int x = 0; x < 40; x++)
    {
        for(int y = 0; y < 15; y++)
        {
            printf("%d\t", gameBoardWalls[x][y]);
            if(boardOne.gameBoardText[x][y] % 15 == 0)
            {
                printf("\n");
            }
        }
    }
}

void convertIntArrtoCharArr()
{
    for(int x = 0; x < 40; x++)
    {
        for(int y = 0; y < 15; y++)
        {

        }
    }
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
    printf("\n\nScore: %d\n\n", score);
    // Populate and Print the board.
    printBoard();

    // Place Player onto board


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
                system("cls");
                printf("\nPick up object");
                printf("\n\nScore: %d\n\n", score);
                // Populate and Print the board.
                printBoard();
                score++;
                break;
            case 'd':
                system("cls");
                printf("\nDrop off object");
                printf("\n\nScore: %d\n\n", score);
                // Populate and Print the board.
                printBoard();
                score--;
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

    // Read the data file and then store into the storage
}

void generateGameFile()
{
    char *filename = "gameBoard.txt";
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error opening file. Please ensure the file exists within folder.\n");
        return 0;
    }

    // Creates a "xxx xxx xxx..." 40x15 grid of numerical values from 001-600
    for(int i = 1; i < 601; i++)
    {
        if(i > 9 && i < 100)
        {
            fprintf(fp, "0%d ", i);
        }
        else if (i > 99)
        {
            fprintf(fp, "%d ", i);
        }
        else
        {
            fprintf(fp, "00%d ", i);
        }

        if (i % 15 == 0 && i != 0)
        {
            fprintf(fp, "\n");
        }
    }

    fclose(fp);
    FILE *fp2 = fopen(filename, "r");

    // Send every value from text file to an array in gameBoard
    for(int x = 0; x < 40; x++)
    {
        for(int y = 0; y < 15; y++)
        {
            fscanf(fp2, "%d ", &boardOne.gameBoardText[x][y]);
        }
    }
    // gameBoard.gameBoardText[x][y] = //item 1
    fclose(fp);
}

void generateItemLocation()
{
    int counter = 0;
    // Access the game board array
    for(int z = 0; z<5; z++)
    {
        counter++;
        // Generate and assign item location to X Array
        boardOne.xItemCo[z] = rand() % 40;
        // Generate and assign item location to Y Array
        boardOne.yItemCo[z] = rand() % 15;

        /* DEBUGGING
        * printf("XY of %d: %d %d\t", counter, xLocArrItem[z], yLocArrItem[z]);
        * printf("\n");
        */
    }
}

void generateStartDrop()
{
    // Set Default Start/Drop Location
    boardOne.xyStartDrop[0][0] = 39;
    boardOne.xyStartDrop[0][1] = 19;
    playerOne.xyposition[0][0] = 39;
    playerOne.xyposition[0][1] = 19;
    playerOne.hasObject = 98;
}

void addScore()
{
    boardOne.gameScore = boardOne.gameScore+1;
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


