/* AuP - Berechnung des Binominalkoeffizienten, rekursiv */

#include <stdio.h>

static unsigned int binom(unsigned int, unsigned int);

int main() {
	int n, k;
	printf("n = ");
	scanf("%d", &n);
	printf("k = ");
	scanf("%d", &k);
	printf("%d ueber %d = %d\n", n, k, binom(n, k));
	
	return 0;
}

unsigned int binom(unsigned int n,unsigned int k) {
	if ((n == k) || (k == 0)) return 1;
	else if ((0 < k) && (k < n))
		return binom(n - 1, k - 1) + binom(n -1, k);
	else
		return 0;
}
