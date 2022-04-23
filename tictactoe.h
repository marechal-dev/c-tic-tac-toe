#define NUMBER_ROWS 3
#define NUMBER_COLUMNS 3

int checkWinCondition();
int checkBoardFreeSpaces();
void handlePlayerInput(int* x, int* y);
void displayBoard();
void markBoard(char currentPlayerMark, int boardX, int boardY);
