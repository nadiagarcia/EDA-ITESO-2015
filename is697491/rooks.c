#include <stdio.h>

int sols = 0;
int board[8][8]; 
int place_rook (int rook, int a, int b);
int remove_q (int n);

int main (int argc, char* argv[]) {
	int j,k;
	remove_q (-1);
	place_rook (1,-1,-1);
	printf ("%d\n", sols);
	return 0;
}

int place_rook (int rook, int a, int b) {
	int j,k;
	if (rook == 9) {
		print_board ();
		return 0;
	}
	if (a != -1 || b != -1) {
		board[a][b] = rook;
		fill_board (a,b,rook);
		if (place_rook (rook + 1, -1, -1) == 1) {
			//remove_q (rook);
			board[a][b] = rook;
			return 1;
		}
	}
	for (j = 0; j < 8; j++) { //place up:down, left:right
		for (k = 0; k < 8; k++) {
		 	if (board[j][k] == 0) {
		 		board[j][k] = rook;
		 		fill_board (j,k,rook);
		 		if (place_rook (rook + 1, -1, -1) == 0) {
		 			remove_q (rook);
		 		} else {
		 			//remove_q (rook);
		 			board[j][k] = rook;
		 		}
		 	}
		}
	}
	return 0;
}

//rook's position: Fill it's used spaces with the rook's number
int fill_board (int a, int b, int rook) { 
	int j,k;
	for (j = 0; j < 8; j++) { //Fill up:down, left:right
		for (k = 0; k < 8; k++) {
		 	if ((j == a || k == b) && board[j][k] == 0) board[j][k] = rook;
		}
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


