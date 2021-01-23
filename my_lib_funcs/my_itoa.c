#include "../my_bc.h"

char *my_itoa(int n, char *dest, int len) {
	int i = 0;

	if (n < 0) {
		dest[i++] = '-';
	}
	while (n > 0 && len-- > 0) {
		dest[i++] = n % 10 + '0';
		n /= 10;
	}
	dest[i] = '\0';
	my_strrev(dest);
	return 0;
}