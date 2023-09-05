const int NUMBER_OF_ROWS = 3;
const int NUMBER_OF_COLUMNS = 3;
const int MAX_GRID_SIZE = NUMBER_OF_ROWS * NUMBER_OF_COLUMNS;
const int INITIAL_GAME_STATUS = -1;

typedef struct GameSession
{
  char *gameGrid[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
  int status;
  int currentPlayer;
} S_GameSession;

S_GameSession const *createGameSession();
void startGame(S_GameSession const *gameSession);
void finishGame(S_GameSession const *gameSession);
