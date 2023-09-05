#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <game.h>
#include <tictactoe.h>

S_GameSession const *createGameSession()
{
  size_t gameGridAllocationSize = MAX_GRID_SIZE * sizeof(char);
  char *gameGrid = malloc(gameGridAllocationSize);

  S_GameSession const *gameSession = malloc(sizeof(struct GameSession));

  strncpy(gameSession->gameGrid, gameGrid, MAX_GRID_SIZE);

  memcpy(gameSession->status, &INITIAL_GAME_STATUS, sizeof(int));

  return gameSession;
}

void startGame(S_GameSession const *gameSession) {}

void finishGame(S_GameSession const *gameSession)
{
  free(gameSession->gameGrid);
  free(gameSession);
}
