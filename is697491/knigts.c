#include <stdio.h>

int sols = 0;
int board[8][8]; 
int place_knight (int knight, int a, int b);
int remove_q (int n);

int main (int argc, char* argv[]) {
	int j,k;
	for (j = 0; j < 8; j++) { //place up:down, left:right
		for (k = 0; k < 8; k++) {
		 	remove_q (-1);
			place_knight (1,j,k);
			printf ("%d\n", sols);
	 	}
	}
	
	
	return 0;
}

//Supongamos que funciona.... casi dos horas despues no ha encontrado nada xD
int place_knight (int knight, int a, int b) {
	int j, k, attempt = 1;
	if (knight == 65) {
		sols++;
		printf ("-----------------------------------");	
		print_board ();
		printf ("-----------------------------------");	
		return 0;
	}

	if (a < 0 || a > 7 || b < 0 || b > 7) return 0; //Check out of bounds
	else if (board[a][b] != 0) return 0; //Check if used 
	else board[a][b] = knight;
	//if (knight > 60)
	print_board ();
	
	while (attempt < 10) {
		switch (attempt) {
			case 1: place_knight (knight + 1, a + 2, b + 1); break;
			case 2: place_knight (knight + 1, a + 1, b + 2); break;
			case 3: place_knight (knight + 1, a + 2, b - 1); break;
			case 4: place_knight (knight + 1, a + 1, b - 2); break;
			case 5: place_knight (knight + 1, a - 2, b - 1); break;
			case 6: place_knight (knight + 1, a - 1, b - 2); break;
			case 7: place_knight (knight + 1, a - 2, b - 1); break;
			case 8: place_knight (knight + 1, a - 1, b - 2); break;
			default: 
				board[a][b] = 0;
				return 0;
		}
		attempt++;
	}
}

int print_board () {
	int j,k;
	for (j = 0; j < 8; j++) {
		for (k = 0; k < 8; k++) {
		 	if (board[j][k] != 0) 
		 		if (board[j][k] < 10) printf (" %d ", board[j][k]);
				else printf ("%d ", board[j][k]);
		 	else printf (".. ");
		}
		printf ("\n");
	}
	printf ("%d\n", sols);
	printf ("\n");
}

//Enter number to remove, or -1 to clear board
int remove_q (int n) { 
	int j,k;
	for (j = 0; j < 8; j++) {
		for (k = 0; k < 8; k++) {
		 	if (n == board[j][k] || n == -1) board[j][k] = 0;
		}
	}
}


