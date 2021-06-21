struct gameBoard {
    /* How many items on the board?
    * Creates this matrix, should populate these with coordinates randomized between a row [0:74] and column [0:24]
    * {[x][y]} {[x][y]} {[x][y]} {[x][y]} {[x][y]}
    */
    int xItemCo [5];
    int yItemCo [5];

    // Initialise as a StartDrop point x [74:84] and y as 24.
    int xyStartDrop[1][2];

    // Game Board array
    int gameBoardText[40][15];

    int gameScore;
} gBoard;
