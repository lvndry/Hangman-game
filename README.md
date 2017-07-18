 ```
  _    _                                           _____                       
 | |  | |                                         / ____|                      
 | |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __   | |  __  __ _ _ __ ___   ___  
 |  __  |/ _` | '_ \ / _` | '_ ` _ \ / _` | '_ \  | | |_ |/ _` | '_ ` _ \ / _ \ 
 | |  | | (_| | | | | (_| | | | | | | (_| | | | | | |__| | (_| | | | | | |  __/ 
 |_|  |_|\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|  \_____|\__,_|_| |_| |_|\___| 
                      __/ |                                                     
                     |___/                                                  

  			           /*** MADE BY LANDRY MONGA - 2017 *** \
```
## Game
	HANGMAN GAME MADE IN C
**Options :**
 - Choice of language beetwen French and English
 - Solo mode/Duo Mode : The first player to found his word wins
 - 3 levels of difficulty : Common words, Difficult words, random
 
## Use 
 - Before playing you can choose language (French or English), and number of players (One or Two)
    ![Alt Text](screenshots/menu.png?raw=true "Menu to choose language and number of players")
 
 - In solo mode you choose the level of difficulty and a word is chosen for you
    ![Alt Text](screenshots/sologame.png?raw=true "Solo mode")
    If the letter chosen is in the word you have no pv lost, if isn't you lost a pv and hangman draw is showing up
 - You can have some clue if you have difficulties to find the word, however you have to sacrifice a pv for it
   ![Alt Text](screenshots/indice.png?raw=true "You can have clues if you have difficulies")
   If don't want one just press n
    ![Alt Text](screenshots/noindice.png?raw=true "Just press an other key if you don't want one")
    
 - Once you have finished you can replay by pressing Enter or quit by pressing q
   ![Alt Text](screenshots/re^play.png?raw=true "When finished press Enter to replay, q to quit")
 
 - You can also choose duo mode, nothing changes but here this is the first to guess his word that wins
    ![Alt Text](screenshots/multiplayer.png?raw=true "Duo mode")
    
## Compile
```
  gcc main.c pendu.c
```
