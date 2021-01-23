#include "../my_bc.h"

int my_strlen(char* str) {
	int i;

	for (i = 0; str[i] != '\0'; i++);
	return  i;
}