#include "my_bc.h"

int generate_hash(t_block *genesis) {
	int b_hash;
	int r_hash = 0;

	genesis = genesis->next;
	while (genesis != NULL) {
		b_hash = 0;
		for (int i = 0; genesis->bid[i] != '\0'; i++) {
			b_hash += genesis->bid[i];
		}
		genesis->hash = b_hash;
		r_hash += b_hash;
		genesis = genesis->next;
	}
	return r_hash;
}