#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

typedef struct DIGIT {
	int value;
	struct DIGIT *next;
	struct DIGIT *prev;
} DIGIT;


int getch (void) {
    struct termios oldattr, newattr;
    int ch;
    
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
/*start->num = 0;
	start->next = NULL;
	
   	while(c != 10){
    	c = getch();
    	n = c - 48;
    	printf("%c ",c);
   } */
   
int main(){
	char c = 0;

	
	DIGIT *new, *current_a, *current_b, *start, *prev;
	int over = 0, n, temp;
	
	printf ("Huge number adition: By Felipe Escoto\n");
	printf ("\nNumber  1: ");
	
	
	DIGIT *start_a = (DIGIT *) malloc (sizeof (DIGIT));
	start_a->value = 0;
	start_a->next = NULL;
	DIGIT *current = start_a;
	
	while (n != -38) {
		c = getch ();
		n = c - 48;
		
		if (n >=0 && n <=9) {
			current->next = (DIGIT *) malloc (sizeof (DIGIT));
			current->next->prev = current;
			current = current->next;
			current->value = n;
			current->next = NULL;	
			printf ("%d", n);
		}
		
	}
	
	DIGIT *start_b = (DIGIT *) malloc (sizeof (DIGIT));
	start_b->value = 0;
	start_b->next = NULL;
	current = start_b;
	
	n = 0;
	printf ("\nNumero  2: ");
	while (n != -38) {
		c = getch ();
		n = c - 48;
		
		if (n >=0 && n <=9) {
			current->next = (DIGIT *) malloc (sizeof (DIGIT));
			current->next->prev = current;
			current = current->next;
			current->value = n;
			current->next = NULL;	
			printf ("%d", n);
		}
	}


	over = 0;
	temp = 1;
	current_a = start_a;
	current_b = start_b;
	
	start = (DIGIT *) malloc (sizeof (DIGIT));
	start->value = 0;
	start->next = NULL;
	current = start;
	
	
	while (current_a->next != NULL) current_a = current_a->next;
	while (current_b->next != NULL) current_b = current_b->next;
	
	printf ("\nRespuesta: ");
	while (current_a != NULL || current_b != NULL) {
		if (current_a == NULL || current_b == NULL) {
			if (current_a != NULL) temp = current_a->value + over;
			if (current_b != NULL) temp = current_b->value + over;
		} else {
			temp = current_a->value + current_b->value + over;			
		}
		over = 0;
		if (temp > 9) {over = 1; temp = temp - 10;}
		//printf ("%d", temp);
		
		current->next = (DIGIT *) malloc (sizeof (DIGIT));
		current->next->prev = current;
		current = current->next;
		current->value = temp;
		current->next = NULL;	
				
		if (current_a != NULL) current_a = current_a->prev;
		if (current_b != NULL) current_b = current_b->prev;
		
	}

	while (current->prev != NULL) {
		printf ("%d", current->value);
		current = current->prev;
	}
	printf ("\n");
	return 0;	
}	

