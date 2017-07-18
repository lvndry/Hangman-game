/***
  _    _                                           _____                       
 | |  | |                                         / ____|                      
 | |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __   | |  __  __ _ _ __ ___   ___  
 |  __  |/ _` | '_ \ / _` | '_ ` _ \ / _` | '_ \  | | |_ |/ _` | '_ ` _ \ / _ \ 
 | |  | | (_| | | | | (_| | | | | | | (_| | | | | | |__| | (_| | | | | | |  __/ 
 |_|  |_|\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|  \_____|\__,_|_| |_| |_|\___| 
                      __/ |                                                     
                     |___/                                                  

  MADE BY LANDRY MONGA
  August 2017
  
***/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "pendu.h"

#ifdef _WIN32	//If in windows
	#define CLEAR system("cls");
#else 
	#define CLEAR system("clear");	//If linux/Mac
#endif

int main(int argc, char const *argv[])
{
	do{
		CLEAR

		intro();
		printf("\n\n\n");
		
		srand(time(NULL));

		printf("====== Jeu du pendu =======\n");
		
		int speech = language();
		int mode = gameMode(speech);
		game(mode, speech);
	
	}while(getchar() != 'q' && getchar() == '\n');	

	return 0;
}
