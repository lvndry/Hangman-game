#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pendu.h"

#ifdef _WIN32
#define CLEAR system("cls");
#else 
#define CLEAR system("clear");
#endif

int main(int argc, char const *argv[])
{

	do{
		CLEAR

		intro();
		printf("====== Jeu du pendu =======\n");
		srand(time(NULL));
		
		int speech = language();
		int mode = gameMode(speech);
		game(mode, speech);
	
	}while(getchar() != 'q' && getchar() == '\n');	

	return 0;
}