#include <stdio.h>

int sols = 0;
int board[8][8]; 
int place_queen (int queen, int a, int b);
int remove_q (int n);

int main (int argc, char* argv[]) {
	int j,k;
	remove_q (-1);
	place_queen (1,-1,-1);
	printf ("%d\n", sols);
	return 0;
}

int place_queen (int queen, int a, int b) {
	int j,k;
	
	if (queen == 9) {
		print_board ();
		return 0;
	}
	
	if (a != -1 || b != -1) {
		board[a][b] = queen;
		fill_board (a,b,queen);
		if (place_queen (queen + 1, -1, -1) == 1) {
			//remove_q (queen);
			board[a][b] = queen;
			return 1;
		}
	}
	
	if (queen == 9) return 1;
	else {
		for (j = 0; j < 8; j++) { //Fill up:down, left:right
			for (k = 0; k < 8; k++) {
			 	if (board[j][k] == 0) {
			 		board[j][k] = queen;
			 		fill_board (j,k,queen);
			 		if (place_queen (queen + 1, -1, -1) == 0) {
			 			remove_q (queen);
			 		} else {
			 			//remove_q (queen);
			 			board[j][k] = queen;
			 			
			 		}
			 	}
			}
		}
		return 0;
	}
}

//Queen's position: Fill it's used spaces with the queen's number
int fill_board (int a, int b, int queen) { 
	int j,k;
	for (j = 0; j < 8; j++) { //Fill up:down, left:right
		for (k = 0; k < 8; k++) {
		 	if ((j == a || k == b) && board[j][k] == 0) board[j][k] = queen;
		}
	}
	//Fill diagonals
	for (k = b, j = a; j > 0 && k > 0; j--, k--) { //Up left
		if (board[j][k] == 0) board[j][k] = queen;
	}	
	for (k = b, j = a; j > 0 && k < 8; j--, k++) { //Up right
		if (board[j][k] == 0) board[j][k] = queen;
	}	
	for (k = b, j = a; j < 8 && k > 0; j++, k--) { //down left
		if (board[j][k] == 0) board[j][k] = queen;
	}	
	for (k = b, j = a; j < 8 && k < 8; j++, k++) { //down right
		if (board[j][k] == 0) board[j][k] = queen;
	}
}

int print_board () {
	int j,k;
	for (j = 0; j < 8; j++) {
		for (k = 0; k < 8; k++) {
		 	if (board[j][k] != 0) printf ("%d ", board[j][k]);
		 	else printf (". ");
		}
		printf ("\n");
	}
	sols++;	
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


