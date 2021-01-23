#include "../my_bc.h"

void my_memset(char *s, int c, int size) {
	int i = 0;

	while (size--) {
		s[i++] = c;
	}
}