#include "../my_bc.h"

char* my_strdup(char* str) {
	char* new;
	int i;

	new = (char*)malloc(my_strlen(str) + 1);
	for (i = 0; str[i] != '\0'; i++) {
		new[i] = str[i];
	}
	new[i] = '\0';
	return new;
}