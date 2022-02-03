#include <stdio.h>

#define NUMBER_ROWS 3
#define NUMBER_COLUMNS 3

char game_grid[NUMBER_ROWS][NUMBER_COLUMNS] =
{
  {' ', ' ', ' '},
  {' ', ' ', ' '},
  {' ', ' ', ' '}
};

int choice, player;

int check_for_win();
int check_free_spaces();
void display_board();
void mark_board(char mark, int x, int y);

int main()
{
  int game_status;
  player = 1;

  char mark;
  
  do
  {
    int x, y;
    display_board();

    player = (player % 2) ? 1 : 2;

    printf("Player %d, enter coordinates:\n", player);
    printf("X (rows, 1-3): ");
    scanf("%d", &x);
    printf("Y (column, 1-3): ");
    scanf("%d", &y);
    printf("\n");

    mark = player == 1 ? 'X' : 'O';

    mark_board(mark, x, y);

    game_status = check_for_win();

    player++;

  } while (game_status == -1);

  if (game_status == 1)
  {
    printf("Player %d wins!", --player);
  } else {
    printf("Game draw!");
  }

  return 0;
}

void display_board()
{
  printf("X| 1 | 2 | 3 |\n");
  for (int i = 0; i < NUMBER_ROWS; i++)
  {
    printf(
      "%d| %c | %c | %c |\n", 
      (i+1), 
      game_grid[i][0], 
      game_grid[i][1], 
      game_grid[i][2]
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
int check_for_win() {
  if (check_free_spaces() != 0)
  {
    // Check Rows
    for (int i = 0; i < NUMBER_ROWS; i++)
    {
      if (game_grid[i][0] == game_grid[i][1] && game_grid[i][0] == game_grid[i][2])
      {
        if (game_grid[i][0] != ' ' && game_grid[i][1] != ' ' && game_grid[i][2] != ' ')
        {
          return 1;
        }
      }
    }

    // Check Colums
    for (int i = 0; i < NUMBER_ROWS; i++)
    {
      if (game_grid[0][i] == game_grid[1][i] && game_grid[0][i] == game_grid[2][i])
      {
        if (game_grid[0][i] != ' ' && game_grid[1][i] != ' ' && game_grid[2][i] != ' ')
        {
          return 1;
        }
      }
    }

    // Check grid diagonals
    if (game_grid[0][0] == game_grid[1][1] && game_grid[0][0] == game_grid[2][2])
    {
      if (game_grid[0][0] != ' ' && game_grid[1][1] != ' ' && game_grid[2][2] != ' ')
      {
        return 1;
      }
    }
    if (game_grid[0][2] == game_grid[1][1] && game_grid[0][2] == game_grid[2][0])
    {
      if (game_grid[0][2] != ' ' && game_grid[1][1] != ' ' && game_grid[2][0] != ' ')
      {
        return 1;
      }
    }

    return -1;
  } else {
    return 0;
  }
};

int check_free_spaces() {
  int free_spaces = 9;

  for (int i = 0; i < NUMBER_ROWS; i++)
  {
    for (int j = 0; j < NUMBER_COLUMNS; j++)
    {
      if (game_grid[i][j] != ' ')
      {
        free_spaces--;
      }
    }
  }

  return free_spaces;
}

void mark_board(char mark, int x, int y)
{
  if (x > NUMBER_ROWS || y > NUMBER_ROWS)
  {
    printf("Invalid move.\n");
    return;
  } else {
    game_grid[x-1][y-1] = mark;
  }

  return;
};

