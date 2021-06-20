struct gameBoard {
    /* How many items on the board?
    * Creates this matrix, should populate these with coordinates randomized between a row [0:74] and column [0:24]
    * {[x][y]} {[x][y]} {[x][y]} {[x][y]} {[x][y]}
    */
    int xyItem [5];

    // Initialise as a StartDrop point x [74:84] and y as 24.
    int xyStartDrop[2][5];

    int gameScore;
} gBoard;
