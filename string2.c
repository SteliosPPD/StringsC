/*
	XEIRISMOS GRAMMATOSEIRON
	========================
	
<string.h>
int strlen(char *s): epistrefei to mikos tis grammatoseiras s, xoris na metraei ton
		xaraktira termatismou '\0', px strlen("Hi!") = 3. Yparxei kai o xaraktiras
		termatismou '\0' pou akolouthei, alla den to metrame.
		
void strcpy(char *pros, char* apo): adigrafei ta periexomena toy apo sto pros. Tha prepei
		na iparxei arketi mnimi sto pros, oste na dextei olous tous xaraktires tou apo.
		Einai douleia tou programmatistei na iparxei mnimi, i entoli den kanei kanenan
		elegxo gia tin iparksi xorou sto pros.
		
char* strdup(char *s): ekxorei arketi mnimi oste na adigrapsei se nea thesi ta periexomena
		tou pinaka s. Ta adigrafei kai meta epistrefei enan neo deikti stin proti thesi
		tou adigrafou. Px boroume na grapsoume:
				char *copy = NULL;
				char text[] = "Hello from Tripoli!";
				
				copy = strdup(text);
				
int strcmp(char* s1, char* s2): sigrinei ta dio string s1, s2 kai epistrefei mia akeraia
		timi simfona me ta eksis:
			1. An s1 == s2, epistrefei == 0
			2. An s1 > s2,  epistrefei >  0
			3. An s1 < s2,  epistrefei <  0
		px
			if (strcmp(str, "end") == 0) ... 
			
char tolower(char ch): an to ch einai grammam epistrefei to idio gramma pezo, 
		px tolower('A') = 'a'
		
char toupper(char ch): an to ch einai grammam epistrefei to idio gramma kefalaio, 
		px tolower('a') = 'A'
		
<ctype.h>
int islower(char ch): epistrefei 0 an o xaraktiras ch den einai pezo gramma, allios 
		epistrefei kapoia alli mi mideniki timi. px islower('A') = 0
		
int isupper(char ch): epistrefei 0 an o xaraktiras ch den einai kefalaio gramma, allios 
		epistrefei kapoia alli mi mideniki timi. px isupper('a') = 0
		
int isalpha(char ch): epistrefei miden an o xaraktiras ch den einai gramma, allios kapoia
		mi mideniki timi, px isalpha('2') = 0
		
int isdigit(char ch): epistrefei miden an o xaraktiras ch den einai psifio, allios kapoia
		mi mideniki timi, px isdigit('a') = 0
		
int isalnum(char ch): epistrefei miden an o xaraktiras ch den einai psifio oute gramma, 
		allios kapoia mi mideniki timi, px isalnum('!') = 0
		
int isspace(char ch): epistrefei miden an o xaraktiras ch den einai keno, allagi grammis i tab, 
		allios kapoia mi mideniki timi, px isspace('!') = 0
		
char msg[] = "Hello from Tripoli";
char *token = NULL;
char delim[] = " ";
	
token = strtok(msg, delim); // msg = "Hello"+'\0'+"from Tripoli"
							// token = "Hello"
				
// to NULL simainei oti thelo na sinexiso apo tin proigoumeni thesi			
token = strtok(NULL, delim); // msg = "Hello"+'\0'+"from"+'\0'+"Tripoli"
							// token = "from"							

// to NULL simainei oti thelo na sinexiso apo tin proigoumeni thesi			
token = strtok(NULL, delim); // msg = "Hello"+'\0'+"from"+'\0'+"Tripoli"+'\0'
							// token = "Tripoli"
								
Na grafei programma pou diavazei apo orismata grammis edolon to onoma tou xristi kai 
efoson apoteleitai mono apo grammata, emfanizei enan xairetismo, ston opooio to proto 
gramma einai kefalaio kai ta ipoloipa peza.
*/

#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	char msg[] = "Hello from Tripoli, how are you!!???";
	char *token = NULL;
	char delim[] = "i! ";
	int len, i;

	token = strtok(msg, delim);
	
	while (token != NULL){
		printf("%s \n", token);
		token = strtok(NULL, delim);
	}
	printf("Now msg is: %s \n", msg);
	
	len = strlen(msg);
	for (i = 0 ; i < len+15 ; i++) printf("%c \n", msg[i]);
	return 0;
}