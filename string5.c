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
		
char* strtok(char *m, char* delim): anazita sto m opoiondipote xaraktira pou iparxei sto delim.
		stin proti thesi pou tha vrei enan tetoio xaraktira ton metatrepei se termatiko xaraktira
		'\0' kai epistrefei enan pointer sto proigoumeno kommati. An to m einai NULL sinexizei
		apo tin thesi pou eixe meinei prin. Epeidi allazei xaraktires se termatikous, to arxiko
		string allazei episis kai den einai to idio. Isos na xreiazetai na kratisoume prota
		ena adigrafo me tin strdup.
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
	
void gets(char* s): diavazei apo tin eisodo kai apothikevei ston pinaka s mexri tin 
		epomeni allagi grammis (tin opoia afinei stin mnimi)
		
scanf(char* format", ...): diavazei apo tin eisodo mexri na vrei to epomeno keno, tab, i
		allagi grammis ta opoia afairei apo tin mnimi
		
puts(char *s): emfanizei to s

printf(char *dormat, ...): emfanizei morfopoiimeni eksodo
Na grafei programma pou diavazei ena keimeno kai kataxorei kathe leksi se pinaka. Tha prepei
an mia leksi emfanizetai perissoteres fores na apothikevetai mono 1. Na emfanizontai oi 
lekseis. Na zitaei apo ton xristi mia leksi kai na tou emfanizei an vrisketai sto pinaka. 


Na grafei programma poy dexetai apo orismata grammis edolon ena email kai elegxei an einai 
egiro. Tha prepei na apoteleitai apo grammata, arithmous, '.', '_' kai to '@' 1 fora mono.
tha prepei na kataligei se '.gr' i '.com'
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	char buffer[4096];
	char *copy = NULL;
	char *token = NULL;
	char delim[] = "!,. ?\":";
	char **lexiko = NULL;
	int len, i, j, counter = 0, exist;
	
	printf("dose keimeno: \n");
	gets(buffer);

	copy = strdup(buffer);

	token = strtok(copy, delim);
	
	while (token != NULL){
		counter++;
		token = strtok(NULL, delim);
	}
	
	// kataskevi pinaka lekseon
	lexiko = (char**)malloc(sizeof(char*) * counter);
	if (lexiko == NULL){
		printf("malloc error\n");
		return 1;
	}
	
	// adigrafo tis lekseis ston pinaka
	copy = strdup(buffer);
	
	token = strtok(copy, delim);
	
	while (token != NULL){
		exist = 0;
		for (j = 0 ; j < i ; j++){
			if (strcmp(token, lexiko[j]) == 0) exist = 1;
		}
		if (exist == 0) lexiko[i++] = strdup(token);
		/*
		lexiko[i] = (char*)malloc(sizeof(char) * (strlen(token) + 1));
		if (lexiko[i] == NULL){
			printf("malloc error\n");
			free(lexiko);
			return 1;	
		}
		strcpy(lexiko[i], token);
		i++;
		*/
		token = strtok(NULL, delim);
	}
	counter = i;
	
	// emfanisi
	for (i = 0 ; i < counter ; i++){
		printf("%s \n", lexiko[i]);
	}
	
	// free
	for (i = 0 ; i < counter ; i++) free(lexiko[i]);
	free(lexiko);
	
	return 0;
}