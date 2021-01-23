#include "../my_bc.h"

int my_atoi(char* str) {
	int sign = 1;
	int i = 0;
	int ret = 0;

	if (str[i] == '-') {
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9') {
		ret = (ret * 10) + (str[i] - '0');
		i++;
	}
	return ret * sign;
}