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
	WORDS *current, *new, *prev;
	WORDS *start = NULL;
	printf ("Sort Words: By Felipe Escoto\n");
	
	words_file = fopen(argv[1], "r");
	if (words_file == NULL)	{
		printf("File \"%s\" does not exist!\n", argv[1]);
		return 0;
	}
	fgets (&temp, 20000, words_file);
	do {
		pch = strtok (temp," ,.-\n");
		while (pch != NULL) {
			new = (WORDS *) malloc (sizeof (WORDS));
			new->next = NULL;
			strcpy (&new->word, pch);

			if (start == NULL) {
				start = new;
			} else {
				current = start;
				while (current->next != NULL && strcmp (current->word,new->word) < 0) {
					prev = current;
					current = current->next;					
				}				
				if (strcmp (current->word,new->word) != 0) { //Check if word didn't exit
					if (current == start) { //Insert at the begining
						new->next = start;
						start = new;
					} else if (current->next == NULL) { //Insert at the end
						current->next = new;
					} else { //Insert at the middle
						prev->next = new;
						new->next = current;
					}
				}
			}
			pch = strtok (NULL, " ,.-\n");
		}
		fgets (&temp, 20000, words_file);
	} while (!feof(words_file));
			
	current = start;
	while (current != NULL) {
		printf ("%s\n", current->word);
		current = current->next;
	}
	fclose (words_file);
	return 0;	
}	

