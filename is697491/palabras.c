#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//TODO Sort letters
//cc     palabras.c -lm  -o palabras && ./palabras words.txt
typedef struct WORDS {
	char word[20];
	struct WORDS *next;
} WORDS;

FILE* words_file;

int main (int argc, char* argv[]) {
	int total = 0;
	char temp[100];
	char *pch;
	WORDS *current, *new;
	WORDS *start = NULL;
	printf ("Sort Words: By Felipe Escoto\n");
	
	words_file = fopen(argv[1], "r");
	if (words_file == NULL)	{
		printf("File \"%s\" does not exist!\n", argv[1]);
		return 0;
	}

	while (!feof(words_file)) {
		fgets (&temp, 20000, words_file);

		//printf ("Splitting string \"%s\" into tokens:\n",temp);
		pch = strtok (temp," ,.-");
		while (pch != NULL) {
			//printf ("%s\n",pch);
			new = (WORDS *) malloc (sizeof (WORDS));
			new->next = NULL;
			strcpy (&new->word, pch); 
					
			if (start == NULL) {
				start = new;
			} else {
				current = start;
				while (current->next != NULL) {
					current = current->next;
				}
				current->next = new;
			}	
			pch = strtok (NULL, " ,.-");
		}	
	}
			
	current = start;
	while (current != NULL) {
		printf ("%s\n", current->word);
		current = current->next;
	}
	//printf ("Total: %d\n", total);
	return 0;	
}	
