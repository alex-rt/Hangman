/*This hangman game is designed so that tje user will execute the programm with a number 
from 1 to 7 as an argumrnt which will select the word to guess*/
//words go from 4 to 10 letters
//you start with 5 lives, you can only guess one letter at a time
//wrong letter -1 live, repeated letter, -1 live 
//0 lives= game over. You wont know the word until you gess it.
//Guess the word right and you win!

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
char *wordbank[8]={".", "casa", "arbol", "geometria","celular","vaso","cuarentena","coronavirus"};

char *answer=wordbank[atoi(argv[1])];

int answerlen = strlen(answer);
int letterguessed[11]={0,0,0,0,0,0,0,0,0,0,0};
int lives=5;
int numcorrect=0;
int oldcorrect=0;
int loopindex,reguessed=0;
char guess[2];
char letterentered;

while(numcorrect<answerlen) 
{
printf("\nword:\n");
	for( loopindex = 0; loopindex < answerlen; loopindex++) {
		if(letterguessed[loopindex] == 1) 
		{
				printf("%c",answer[loopindex]);				
		}else{
				printf("*"); 
			}
		}	
		printf("\nHave a guess:\n");
		scanf(" %c", &guess); 
		letterentered = guess[0];
		reguessed = 0; 
		printf("Letter:%c\n",letterentered);
		oldcorrect = numcorrect;
		
		for(loopindex=0; loopindex<answerlen; loopindex++) 
		{
			if(letterguessed[loopindex]==1) 
			{ 
				if(answer[loopindex]==letterentered) 
				{
					reguessed = 1; 
					break;
				} 
				continue;
			}
			if(letterentered==answer[loopindex]) 
			{ 
				letterguessed[loopindex] = 1;
				numcorrect++; 			
			}		
		
		}	
		
		if(oldcorrect==numcorrect && reguessed==0) 
		{ 
			lives--; 
			printf("wrong letter, %d lives left\n", lives);
			if (lives == 0) 
			{ 
				break;
			}
		} else if(reguessed==1) 
		{ 
			lives--;
			printf("repeated letter, %d lives left\n", lives);
		}else{
			printf("there you go!\n");
		}
}    
if(lives==0) 
{
	printf("No more lives left :c you lose\n");	
}else{	
	printf("Congratulations! c: %s is the correct word!\n",answer);
} 	
return 0;
}
