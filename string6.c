/*
Na grafei programma poy dexetai apo orismata grammis edolon ena email kai elegxei an einai 
egiro. Tha prepei na apoteleitai apo grammata, arithmous, '.', '_' kai to '@' 1 fora mono.
tha prepei na kataligei se '.gr' i '.com'

./a.out dl@hotmail.com
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]){
	int len, i, papakia;
	char *email = NULL;
		
	if (argc != 2){
		printf("Prepei na dosete 1 mono email!\n");
		return 1;
	}

	email = strdup(argv[1]);
	printf("email: %s \n", email);

	len = strlen(email);
	papakia = 0;
	for (i = 0 ; i <len ; i++){
		if (isalnum(email[i]) == 0){
			if (email[i] == '@') papakia++;
			else if (email[i] != '.' && email[i] != '_') {
				printf("To email periexei ton lathos xaraktira %c \n", email[i]);
				return 1;
			}
		}
	}
	
	if (papakia != 1){
		printf("Lathos email, periexei kanena i perissotera apo 1 simvola '@' \n");
		return 1;
	}

	if (!((email[len - 1] == 'r' && email[len - 2] == 'g') ||
		(email[len-1] == 'm' && email[len - 2] == 'o' && email[len - 3] == 'c'))){
			printf("H ataliksi prepei na einai .gr i .com!\n");
			return 1;
		}
		
	printf("Apodekto eimail!\n");
	return 0;
}