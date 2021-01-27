#include "my_bc.h"

// takes a string and returns a new string containing the nth word in that string
// memory here is allocated and needs to be freed by its caller
char* get_word(char* str, int n) {
	int i = 0;
	int j = 0;
	char buf[50];
	char *word;

	while (n-- > 1) {
		while (str[i++] <= ' ');
		while (str[i++] > ' ');
	}
	while (str[i] > ' ') {
		buf[j] = str[i];
		i++;
		j++;
	}
	buf[j] = '\0';
	word = my_strdup(buf);
	return word;
}