#include "my_bc.h"

t_block *create_block(char* bid) {
	t_block *new_block;

	new_block = (t_block*)malloc(sizeof(t_block));
	new_block->next = NULL;
	if (bid == NULL) {
		new_block->bid = NULL;
	}
	else {
		new_block->bid = (char*)malloc(my_strlen(bid) + 1);
		my_strcpy(new_block->bid, bid);
	}
	return new_block;
}