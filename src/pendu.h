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

int check(char *userword, char *wordtoguess); //Checks if userword and wordtoguess are the same 
char* chooseWord(int level); //Choose a random word depending on the level
void hangman(int error);
void game(int mode, int language); //Launch the game depending on the mode and the language
int gameMode(int langue); //return game mode : Solo or Duo
int getLen(char *); //return length of word
char getLetter(char *userword, char* wordtoguess);  //returns a random letter a letter not guessed yet
int hasLife(player *user); //Draw hangman body depending on the number of errors
void indice(player *gamer, int langue); //Return a letter that has not been found yet if wanted
void intro(); //Intro ascii animation
int language(); //Retunr language of choice
void letterFound(player *gamer, char guess, int len, int langue); //Check if player letter is in the word
int level(); //Choose a level
void multiplayer();  //Launch multiplayer game
int playerInit(player *user, int langue);  //Init players in duo mode
void soloen(); //Launch game in English
void solofr(); //Lauchn game in French
int wordValue(char *wordtoguess); //Calcul word value depending on the value of letter and the number of times it occurs in the word
