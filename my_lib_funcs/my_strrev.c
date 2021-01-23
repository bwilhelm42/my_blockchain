#include "../my_bc.h"

void my_strrev(char *str) {
	int i = 0;
	int j = my_strlen(str) - 1;
	char temp;

	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}