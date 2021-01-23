#include "my_bc.h"

int append_block(t_block *genesis, t_block *new_block) {
	while (genesis->next != NULL) {
		genesis = genesis->next;
	}
	genesis->next = new_block;
	return 0;
}