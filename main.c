#include <stdio.h>
#include <stdbool.h>

#include "tictactoe.h"

char gameGrid[NUMBER_ROWS][NUMBER_COLUMNS] =
{
  {' ', ' ', ' '},
  {' ', ' ', ' '},
  {' ', ' ', ' '}
};

int choice, currentPlayer;

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
  } else {
    printf("Game draw!");
  }

  return 0;
}

void handlePlayerInput(int* x, int* y) {
  printf("Player %d, enter coordinates:\n", currentPlayer);
  printf("X (rows, 1-3): ");
  scanf("%d", x);
  printf("Y (column, 1-3): ");
  scanf("%d", y);
  printf("\n");
}

void displayBoard()
{
  printf("X| 1 | 2 | 3 |\n");
  for (int i = 0; i < NUMBER_ROWS; i++)
  {
    printf(
      "%d| %c | %c | %c |\n", 
      (i+1), 
      gameGrid[i][0], 
      gameGrid[i][1], 
      gameGrid[i][2]
    );
  }
  printf("\n");
}

/*
* Function that check if player won
* Returns:
* 0 for draw
* 1 for victory
* -1 for board not full and game still running 
*/
int checkWinCondition() {
  bool boardIsNotFull = checkBoardFreeSpaces() != 0 ? true : false;

  if (boardIsNotFull)
  {
    for (int i = 0; i < NUMBER_ROWS; i++)
    {
      if (gameGrid[i][0] == gameGrid[i][1] && gameGrid[i][0] == gameGrid[i][2])
      {
        if (gameGrid[i][0] != ' ' && gameGrid[i][1] != ' ' && gameGrid[i][2] != ' ')
        {
          return 1;
        }
      }
    }

    // Check Colums
    for (int i = 0; i < NUMBER_ROWS; i++)
    {
      if (gameGrid[0][i] == gameGrid[1][i] && gameGrid[0][i] == gameGrid[2][i])
      {
        if (gameGrid[0][i] != ' ' && gameGrid[1][i] != ' ' && gameGrid[2][i] != ' ')
        {
          return 1;
        }
      }
    }

    // Check grid diagonals
    if (gameGrid[0][0] == gameGrid[1][1] && gameGrid[0][0] == gameGrid[2][2])
    {
      if (gameGrid[0][0] != ' ' && gameGrid[1][1] != ' ' && gameGrid[2][2] != ' ')
      {
        return 1;
      }
    }
    if (gameGrid[0][2] == gameGrid[1][1] && gameGrid[0][2] == gameGrid[2][0])
    {
      if (gameGrid[0][2] != ' ' && gameGrid[1][1] != ' ' && gameGrid[2][0] != ' ')
      {
        return 1;
      }
    }

    return -1;
  } else {
    return 0;
  }
};

int checkBoardFreeSpaces() {
  int free_spaces = 9;

  for (int i = 0; i < NUMBER_ROWS; i++)
  {
    for (int j = 0; j < NUMBER_COLUMNS; j++)
    {
      if (gameGrid[i][j] != ' ')
      {
        free_spaces--;
      }
    }
  }

  return free_spaces;
}

void markBoard(char currentPlayerMark, int boardX, int boardY)
{
  if (boardX > 3) {
    printf("Invalid X position\n");
    return;
  } else if (boardY > 3) {
    printf("Invlid Y position\n");
    return;
  }

  if (boardX > NUMBER_ROWS || boardY > NUMBER_ROWS)
  {
    printf("Invalid move: Position is out of scope\n");
    return;
  }

  if (gameGrid[boardX-1][boardY-1] != ' ') {
    printf("Invalid move: Position is already filled\n");
    return;
  }

  gameGrid[boardX-1][boardY-1] = currentPlayerMark;
  return;
};

