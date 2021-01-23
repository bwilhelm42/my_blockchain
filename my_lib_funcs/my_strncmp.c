#include "../my_bc.h"

int my_strncmp(char* s1, char* s2, int n) {
	int i = 0;

	while (--n && s1[i] && s2[i]) {
		if (s1[i] != s2[i]) {
			return s1[i] - s2[i];
		}
		i++;
	}
	return s1[i] - s2[i];
}