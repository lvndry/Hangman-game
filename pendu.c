#include "pendu.h"

int check(char *userword, char* wordtoguess){
	
	if(strcmp(userword, wordtoguess) == 0)
		return 1;

	return 0;
}

char* chooseWord(int level){
	FILE* words;

	char *word = malloc(20*sizeof(char));
	char c = ' ';
	//char *temp = malloc(20* sizeof(char));
	
	if(level == 1){
		words = fopen("dico.txt","r");
		int random = (rand() % (EASY - MIN + 1)) + MIN;

		for(int i = 0; i < random; i++){
			fscanf(words, "%s", word);
		}
	}

	else if(level == 2){ 
		words = fopen("hardw.txt", "r");
		int random = (rand() % (HARD - MIN + 1)) + MIN;
		//printf("random : %d\n", random);

		for(int i = 0; i < random; i++)
			fscanf(words, "%s", word);
	}

	else {
		words = fopen("dico.txt", "r");
		int random = (rand() % (EASY - MIN + 1)) + MIN;
		for(int i = 0; i < random; i++){
			fscanf(words, "%s", word);
		}	 
	}

	fclose(words);

	return word;
}

void game(int mode, int language){
	switch(mode){
		case 1:
			if(language == 1)
				solofr();
			if(language == 2)
				soloen();
		break;

		case 2:
			multiplayer(language);
		break;
	}
}

int gameMode(int langue){
	int mode;
	
	if(langue == 1)
		printf("Voulez vous jouer seul ou en multijoueur ? \nTapez 1 pour mode solo 2 pour jouer a 2 : ");
	else printf("Do you want to player alone or with an other person ?\nPress 1 for solo mode and 2 for duo mode : ");
	int rep = scanf("%d", &mode);
	getchar();

	while(!rep || mode < 1 || mode > 2 ){
		if(langue  == 1)
			printf("Mode de jeu non valide\nTapez 1 pour mode solo 2 pour jouer a 2 : ");
		else printf("Unable player mode\nPress 1 for solo mode and 2 for duo mode : ");
		scanf("%d", &mode);
		getchar();
	}

	return mode;
}

int getLen(char *game){
	return strlen(game);
}

char getLetter(char *userword, char* wordtoguess){
	int len = strlen(wordtoguess), posletter;
	
	srand(time(NULL));

	do{
		posletter = (rand() % (len - MIN + 1)) + MIN;
	}while(userword[posletter] != '*');

	return wordtoguess[posletter];
}

void hangman(int error){

	char body[9];
	for(int i = 0; i < 9; i ++){
		body[i] = ' ';
	} 

	switch(error){
		case 8: body[7] = '\\'; 
		case 7: body[6] = '/'; 
		case 6: body[5] = '|'; 
		case 5: body[4] = '\\'; 
		case 4: body[3] = '|'; 
		case 3: body[2] = '/'; 
		case 2: body[1] = '@'; 
		case 1: body[0] = '|'; 
		default: break;
	}
	
printf(" _______________\n|		%c \n|	 	%c\n|              %c%c%c\n|             	%c     \n|              %c %c\n|\n_____________________ \n", 
		body[0], body[1], body[2], body[3], body[4], body[5], body[6], body[7]);
}

int hasLife(player *user){
	if(user->life > 0)
		return 1;
	return 0;
}

int language(){
	int language ;
	
	printf("Choose Language : \n Tapez 1 pour le francais, Press 2 for english\nLanguage : ");
	int rep = scanf("%d", &language);
	getchar();
	while(!rep || language < 1 || language > 2){
		printf("Language Unable/Langue non disponible\n");
		printf("Choose Language : \n Tapez 1 pour le francais, Press 2 for english\n");
		rep = scanf("%d", &language);
		getchar();
	}
	return language;
}

void indice(player *player, int langue){
	int indice;

	if(player->error >= 4){
		if(langue == 1) printf("Vous voulez un indice ? Appuyez '0' pour un indice\n");
		else printf("Do you need help ? Press 'O' for a clue : ");
		getchar();
		scanf("%c", &indice);
		if(toupper(indice) == 'O'){
			if(langue == 1) printf("La lettre %c est dans le mot\n", getLetter(player->playerWord, player->wordtoguess));
			else printf(" %c appears is in the word\n", getLetter(player->playerWord, player->wordtoguess));
		}
	}
}

void intro(){
	FILE* intro = fopen("intro.txt", "r");
	char c;

	struct timespec req, rem;
	req.tv_sec = 0;
	req.tv_nsec = 500;
	rem.tv_sec = 0;
	rem.tv_nsec = 50;

	while(!feof(intro)){
		c = getc(intro);
		nanosleep(&req, &rem);
		putchar(c);
	}
}

void letterFound(player *player, char guess, int len, int langue){
	int count = 0;

	for(int i = 0; i < len; i++){
			if(guess == player->wordtoguess[i]){
				player->playerWord[i] = guess;
				count++;
			}
		}

		if(count > 0) {
			if(langue == 1)
				printf("La lettre %c est presente %d fois dans le mot\n", guess, count);
			else printf("Letter %c is %d int the word\n", guess, count);
		}
		else {
			if(langue == 1)
				printf("La lettre %c n'est pas dans le mot\n", guess); 
			else printf("%c isn't in the word\n", guess);
			player->error+=1;
		}

		//player->life-=1;
}

int level(int langue){
	int level;
	if(langue == 1){
		printf("Choisissez un niveau : \n");
		printf("1. Mots faciles\n");
		printf("2. Mots Difficiles\n");
		printf("3. Choix aleatoire\n");
	}

	else{
		printf("Choose a level : \n");
		printf("1. Easy\n");
		printf("2. Difficult\n");
		printf("3. Random\n");
	}

	int rep = scanf("%d", &level);
	getchar();
	while(level < 1 || level > 3 || !rep){
		if(langue == 1)
			printf("Choix non valide : \n");
		else printf("Unable choice\n");

		rep = scanf("%d", &level);
		getchar();
	}
	return level;
}


void multiplayer(int langue){
	player player1, player2;
	player *playerpt1 = &player1, *playerpt2 = &player2;

	int win1 = 0, win2 = 0;

	char guess;
 	
 	printf("\n");
 	printf("Joueur 1 : \n");
 	int len1 = playerInit(playerpt1, langue);
 	printf("\n");
 	printf("Joueur 2 :\n");
 	int len2 = playerInit(playerpt2, langue);

	
	do{
		indice(playerpt1, langue);
		printf("\n");
		printf("%s\n", playerpt1->playerWord);

		if(langue == 1) printf("Joueur 1 : Tapez une lettre : ");
		else printf("player1 : Press a letter : ");

		getchar();
		scanf("%c", &guess);
		letterFound(playerpt1, guess, len1, langue);
		printf("%s\n", playerpt1->playerWord);
		win1 = check (playerpt1->playerWord, playerpt1->wordtoguess);
		hangman(playerpt1->error);

		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

		indice(playerpt2, langue);
		printf("\n");
		printf("%s\n", playerpt2->playerWord);

		if(langue == 1) printf("Joueur 2 : Tapez une lettre : ");
		else printf("Player 2 : Press a letter  : ");

		getchar();
		scanf("%c", &guess);
		//getchar();
		letterFound(playerpt2, guess, len2, langue);
		printf("%s\n", playerpt2->playerWord);

		if(langue == 1) printf("Il vous reste %d chances\n", 8-playerpt2->error);
		else printf("You have %d chances left\n", 8-playerpt2->error);

		win2 = check(playerpt2->playerWord, playerpt2->wordtoguess);
		//printf("Win 1 : %d\n", win2);
		//printf("Errors 1 : %d\n", playerpt2->error);
		hangman(playerpt2->error);

		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	}while(playerpt1->error < 8 && playerpt2->error < 8 && win1 == 0 && win2 == 0);

	if(win1)
		printf("Bravo %s tu as gagne!!\n", playerpt1->name);
	if(win2)
		printf("Bravo %s tu as gagne!!\n", playerpt2->name);
	else 
		printf("Vous avez tous les 2 perdus ?? :(\nC'etait pas si dur pourtant je pensais aux mot %s pour %s et au mot %s pour %s!\n", 
			    playerpt1->wordtoguess, playerpt1->name, playerpt2->wordtoguess, playerpt2->name);

	printf("\n\n\n");
	printf("Vous voulez recommencer ?\n");
	printf("Appuie sur Entrer pour rejouer et sur q pour quitter\n");
}

int playerInit(player *user, int langue){
    
    int lvl = level(langue);
	
	user->wordtoguess = malloc(20*sizeof(char));
	user->playerWord = malloc(20*sizeof(char));
	user->name = malloc(20*sizeof(char));

	printf("\n");
	if(langue == 1)
		printf("Tapez votre nom : \n");
	else printf("Type your name : \n");
    scanf("%s", user->name);
    if(langue == 1)
   		printf("Bonne chance %s ! \n", user->name);
   	else printf("Good luck %s !\n", user->name);
	user->life = 10;
	user->error = 0;
	
	user->wordtoguess = chooseWord(lvl);
	
	int len = strlen(user->wordtoguess);

	for(int i = 0; i < len; i++){
		user->playerWord[i] = '*';
	}
	user->playerWord[len] = '\0';
	
	return len;
}

void soloen(){
	
	int lvl = level(2);
	
	char* wordtoguess = chooseWord(lvl);
	int len = getLen(wordtoguess);
	
	//printf("Len : %d\n", len);
	
	char *userword = malloc(len*sizeof(char));
	int count = 0, life = 10, win, error = 0;
	char indice;

	char guess;

	//printf("\nWordtoguess : %s\n", wordtoguess);
	printf("The word has a score value of %d points\n", wordValue(wordtoguess));
		
	printf("Rules : You have to guess what word I'm thinking about..Easy right ?\nYou've only 10 chances to find the word");
	printf("Challenge accepted ?\nWell let me choose a word...\n");
	sleep(2);
	printf("I got it!\n\n");
	
	for(int i = 0; i < len; i++){
		userword[i] = '*';
		printf("%c", userword[i]);
	}
	userword[len] = '\0';
	printf("\n");
			
	//printf("\nWordtoguess : %s\n", wordtoguess);

	do{
		count = 0;

		if(life <= 5){
			printf("Do you need help ? Press 'O' for a clue : ");
			scanf("%c", &indice);
			getchar();
			if(toupper(indice) == 'O')
				printf(" %c appears is in the word\n", getLetter(userword, wordtoguess));
		}

		printf("Press a letter: ");
		scanf("%c", &guess);
		getchar();
			
		for(int i = 0; i < len; i++){
			if(guess == wordtoguess[i]){
				userword[i] = guess;
					count++;
			}
		}

		if(count > 0)
			printf(" %c appears %d times in the word\n", guess, count);
			
		else {
			printf(" %c is not in the word\n", guess);
			error++;
		}
		hangman(error);
			
		win = check(userword, wordtoguess);
		
		printf("%s\n", userword);

		printf("You have %d chances left\n\n", life);

	}while(error < 8 && win == 0);

	if(win == 0)
		printf("Sorry you lost...\nThe word was %s", wordtoguess);
	else printf("Congrats! You are the best :) \n");
		
	printf("\n\n\n");
	printf("Want to replay ?\n");
	printf("Press 'Enter' to replay et 'q' to quit\n");
}

void solofr(){
	int lvl = level(1);
	
	char *wordtoguess = chooseWord(lvl);
	
	int len = getLen(wordtoguess);
	//printf("Longueur du mot : %d\n\n", len);
	
	char *userword = malloc(len*sizeof(char));
	
	int count = 0, win, life = 10, error = 0;
	char indice;

	char guess;

	printf("Le mot a une valeur de %d\n", wordValue(wordtoguess));
		
	printf("Regles : Vous devez devnier le mot auquelle je pense..Voila C'est simple non ?\nSi apres 10 coups vous n'y etes arrive pas vous avez perdu\n");
	printf("Challenge accepte ?\nD'accord laisse moi reflechir a un mot...\n");
	sleep(2);
	printf("C'est bon j'ai une bonne idee!\n\n");
	
	for(int i = 0; i < len; i++){
		userword[i] = '*';
		printf("%c", userword[i]);
	}
	userword[len] = '\0';
	printf("\n");
	
	//printf("Vous commencez avec %d vies\n", life);

	do{
		count = 0;

		if(life <= 5){
			printf("Voulez vous un indice ? Tapez O pour un indice : (Cela vous fera perdre une vie)");
			scanf("%c", &indice);
			getchar();
			
			if(toupper(indice) == 'O'){
				printf("La lettre %c apparait au moins une fois dans le mot\n", getLetter(userword, wordtoguess));
				hangman(++error);
			}
		}
		
		printf("Tapez un lettre : ");
		scanf("%c", &guess);
		getchar();
			
		for(int i = 0; i < len; i++){
			if(guess == wordtoguess[i]){
				userword[i] = guess;
				count++;
			}
		}

		if(count > 0) 
			printf("La lettre %c est presente %d fois dans le mot\n", guess, count);
		else {
			printf("La lettre %c n'est pas dans le mot\n", guess); 
			error++;
		}
		hangman(error);
		printf("\n");
		win = check(userword, wordtoguess);
		
		for(int i = 0; i < len; i++){
			printf("%c", userword[i]);
		} 

		printf("\n");
		//printf("Il vous reste %d vies\n\n", life);

	}while(error < 8 && win == 0);

	if(win == 0)
		printf("Desole vous avez perdu...\nLe mot auquelle je pensais ete %s", wordtoguess);
	else printf("Bravo!! Tu es trop fort :) \n");
		
	printf("\n\n\n");
	printf("Tu veux recommencer ?\n");
	printf("Appuie sur Entrer pour rejouer et sur q pour quitter\n");
}

int wordValue(char *wordtoguess){
	int values[26] = {2, 4, 4, 4, 2, 4, 4, 6, 2, 6, 8, 2, 2, 2, 2, 6, 6, 4, 4, 4, 2, 4, 8, 10, 10, 10};
	
	int len = strlen(wordtoguess);
	int score = 0;
	char *copie = malloc(len*sizeof(char));

	for(int i = 0; i < len; i++){
		int count = 0;
		if(copie[i] != 0){
			copie[i] = tolower(wordtoguess[i])-'a';
			count++;
			for(int j = 0; j < len; j++){
				if(wordtoguess[i] == copie[j]){
					count++;
					copie[j] = 0;
				}
			}
			score += (values[copie[i]]/count);
			//printf("Score : %d\n", score);
		}
	}
	//printf("Score : %d\n", score);
	printf("\n");
	
	return score;
}