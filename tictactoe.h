#define NUMBER_ROWS 3
#define NUMBER_COLUMNS 3

void displayBoard();
void handlePlayerInput(int* x, int* y);
int checkWinCondition();
int checkBoardFreeSpaces();
void markBoard(char currentPlayerMark, int boardX, int boardY);
