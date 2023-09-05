#include <stdio.h>
#include <stdbool.h>

#include <tictactoe.h>

char globalGameGrid[NUMBER_ROWS][NUMBER_COLUMNS] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}};

int currentPlayer;

int main()
{
  int gameStatus;
  currentPlayer = 1;

  char currentPlayerMark;

  do
  {
    int inputX, inputY;
    displayBoard();

    currentPlayer = (currentPlayer % 2) ? 1 : 2;

    handlePlayerInput(&inputX, &inputY);

    currentPlayerMark = currentPlayer == 1 ? 'X' : 'O';

    markBoard(currentPlayerMark, inputX, inputY);

    gameStatus = checkWinCondition();

    currentPlayer++;

  } while (gameStatus == -1);

  if (gameStatus == 1)
  {
    printf("Player %d wins!", --currentPlayer);
  }
  else
  {
    printf("Game draw!");
  }

  return 0;
}

void handlePlayerInput(int *x, int *y)
{
  printf("Player %d, enter coordinates:\n", currentPlayer);
  printf("X (rows, 1-3): ");
  scanf("%d", x);
  printf("Y (column, 1-3): ");
  scanf("%d", y);
  printf("\n");
}

void displayBoard()
{
  const char *rowFormat = "%d| %c | %c | %c |\n";

  printf("X| 1 | 2 | 3 |\n");
  for (int i = 0; i < NUMBER_ROWS; i++)
  {
    printf(
        rowFormat,
        (i + 1),
        globalGameGrid[i][0],
        globalGameGrid[i][1],
        globalGameGrid[i][2]);
  }
  printf("\n");
}

/*
 * Function that check if a player won
 * Returns:
 * 0 for game draw
 * 1 for victory
 * -1 for board not full and game still running
 */
int checkWinCondition()
{
  bool boardIsNotFull = checkBoardFreeSpaces() != 0 ? true : false;

  if (boardIsNotFull)
  {
    // Loop and check rows
    for (int i = 0; i < NUMBER_ROWS; i++)
    {
      if (globalGameGrid[i][0] == globalGameGrid[i][1] && globalGameGrid[i][0] == globalGameGrid[i][2])
      {
        if (globalGameGrid[i][0] != ' ' && globalGameGrid[i][1] != ' ' && globalGameGrid[i][2] != ' ')
        {
          return 1;
        }
      }
    }

    // Loop and check colums
    for (int i = 0; i < NUMBER_ROWS; i++)
    {
      if (globalGameGrid[0][i] == globalGameGrid[1][i] && globalGameGrid[0][i] == globalGameGrid[2][i])
      {
        if (globalGameGrid[0][i] != ' ' && globalGameGrid[1][i] != ' ' && globalGameGrid[2][i] != ' ')
        {
          return 1;
        }
      }
    }

    // Check grid diagonals
    if (globalGameGrid[0][0] == globalGameGrid[1][1] && globalGameGrid[0][0] == globalGameGrid[2][2])
    {
      if (globalGameGrid[0][0] != ' ' && globalGameGrid[1][1] != ' ' && globalGameGrid[2][2] != ' ')
      {
        return 1;
      }
    }
    if (globalGameGrid[0][2] == globalGameGrid[1][1] && globalGameGrid[0][2] == globalGameGrid[2][0])
    {
      if (globalGameGrid[0][2] != ' ' && globalGameGrid[1][1] != ' ' && globalGameGrid[2][0] != ' ')
      {
        return 1;
      }
    }

    return -1;
  }
  else
  {
    return 0;
  }
};

/**
 * Loops through the board and
 * returns a integers representing the remaining
 * free spaces on it.
 */
int checkBoardFreeSpaces()
{
  int totalFreeSpaces = 9;

  for (int i = 0; i < NUMBER_ROWS; i++)
  {
    for (int j = 0; j < NUMBER_COLUMNS; j++)
    {
      if (globalGameGrid[i][j] != ' ')
      {
        totalFreeSpaces -= 1;
      }
    }
  }

  return totalFreeSpaces;
}

/**
 * Marks a board space.
 * Takes as arguments a char representing the current player mark and
 * two integers representing the board coordinates (x, y).
 */
void markBoard(char currentPlayerMark, int boardX, int boardY)
{
  if (boardX > 3)
  {
    printf("Invalid X position\n");
    return;
  }
  else if (boardY > 3)
  {
    printf("Invalid Y position\n");
    return;
  }

  if (boardX > NUMBER_ROWS || boardY > NUMBER_COLUMNS)
  {
    printf("Invalid move: Position is out of scope\n");
    return;
  }

  if (globalGameGrid[boardX - 1][boardY - 1] != ' ')
  {
    printf("Invalid move: Position is already filled\n");
    return;
  }

  globalGameGrid[boardX - 1][boardY - 1] = currentPlayerMark;
  return;
};
