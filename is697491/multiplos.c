#include <stdio.h>

void reset ();
int digits (int n);
int check (int n, int o);
int used[] = {0,0,0,0,0,0,0,0,0};

int main (int argc, char* argv[]) {
	int n, max = 987654321;
	if (argc == 2) max = atoi(argv[1]);
	for (n = 1; n < max; n++) {
		check (n,n);
		reset();
	}
	return 0;
}

int check (int n, int o) {
	if (n % digits(n) != 0) return 0; 
	if (n % 10 == 0 && n != 0) return 0;
	if (used[n % 10] == 1) return 0;
	else used[n % 10] = 1;
	
	if (n == 0) printf ("%d si es valido\n", o);
	else return check (n / 10, o);
	return 1;
} 

void reset () { 
	int n;
	for (n = 0; n < 10; n++) {
		used[n] = 0;
	}
}

int digits (int n) {
	if (n < 0) 			return 0;
	if (n < 10) 		return 1;
	if (n < 100) 		return 2;
	if (n < 1000) 		return 3;
	if (n < 10000)		return 4;
	if (n < 100000) 	return 5;
	if (n < 1000000) 	return 6;
	if (n < 10000000) 	return 7;
	if (n < 100000000) 	return 8;
	if (n < 1000000000)	return 9;
	return 10;
}
