#include "../my_bc.h"

static void list_blocks(t_block *block);

int list_nodes_and_blocks(t_node **nodes) {
	t_node *temp = *nodes;

	while (temp != NULL) {
		printf("%d:", temp->nid);
		list_blocks(temp->genesis);
		printf("\n");
		temp = temp->next;
	}
	return 0;
}

static void list_blocks(t_block *block) {
	while (block->next != NULL) {
		printf(" %s", block->next->bid);
		if (block->next->next != NULL) {
			printf(",");
		}
		block = block->next;
	}
}