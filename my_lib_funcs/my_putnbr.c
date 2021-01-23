#include "../my_bc.h"

void my_putnbr(int nbr) {
	char ret;

	if (nbr < 0) {
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 10) {
		my_putnbr(nbr / 10);
	}
	ret = nbr % 10 + '0';
	write(1, &ret, 1);
}