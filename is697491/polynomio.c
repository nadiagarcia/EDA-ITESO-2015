#include <stdio.h>
#include <string.h>

int poly (int n, int k);
int main (int argc, char* argv[]) {
	if (argc != 2) {
		printf ("Polynomio (x + 1)^n\nExec: %s \"n\"\n", argv[0]);
		return 0;
	};
	
	int n = atoi (argv[1]);
	int m = n;
	while (m >= 0) {
		if (m != 0) printf ("%dx^%d + ", poly (n,m), m);
		else printf ("%d\n", poly (n,m));
		m--;
	}
	return 0;
}

int poly (int n, int k) { //(X + 1)^n
	if (k == 0 || n == k) return 1;
	else return poly (n - 1, k - 1) + poly (n - 1, k);

}
