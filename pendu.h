#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

#define MIN 1
#define EASY 22740
#define HARD 235

typedef struct
{
	char *playerWord;
	char *wordtoguess;
	char *name;
	int life;
	int error;
}player;

// typedef struct player player;

int check(char *player, char *game);
char* chooseWord();
void hangman(int error);
void game(int mode, int language);
int gameMode(int langue);
int getLen(char *);
char getLetter(char *userword, char* wordtoguess);
int hasLife(player *user);
void indice(player *player, int langue);
void intro();
void letterFound(player *player, char guess, int len, int langue);
int language();
int level();
void multiplayer();
int playerInit(player *user, int langue);
void soloen();
void solofr();
int wordValue(char *wordtoguess);