#include "../my_bc.h"

char* my_strnstr(char* big, char* little, int n) {
	int i;
	for (i = 0; big[i] && little[i] && n; i++) {
		if (big[i] != little[i]) {
			return NULL;
		}
		n--;
	}
	return big[i] == little[i] ? big : NULL;
}