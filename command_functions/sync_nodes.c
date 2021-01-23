#include "../my_bc.h"

static void match_blocks(t_node *a_node, t_node *b_node);

int sync_nodes(t_node **nodes) {
	bool modified = true;
	t_node **head = nodes;

	while (modified == true) {
		modified = false;
		head = nodes;
		while (*head != NULL && (*head)->next != NULL) {
			if ((*head)->root_hash != (*head)->next->root_hash) {
				match_blocks(*head, (*head)->next);
				modified = true;
				(*head)->root_hash = generate_hash((*head)->genesis);
				(*head)->next->root_hash = generate_hash((*head)->next->genesis);
			}
			head = &(*head)->next;
		}
	}
}

static void match_blocks(t_node *a_node, t_node *b_node) {
	t_block *a_blocks = a_node->genesis->next;
	t_block *b_blocks;
	int i;
	bool duplicate;

	while (a_blocks != NULL) {
		b_blocks = b_node->genesis->next;
		duplicate = false;
		while (b_blocks != NULL) {
			if (my_strcmp(b_blocks->bid, a_blocks->bid) == 0) {
				duplicate = true;
				break;
			}
			b_blocks = b_blocks->next;
		}
		if (duplicate == false) {
			append_block(b_node->genesis, create_block(a_blocks->bid));
		}
		a_blocks = a_blocks->next;
	}
	b_blocks = b_node->genesis->next;
	a_blocks = a_node->genesis->next;
	while (b_blocks != NULL) {
		a_blocks = a_node->genesis->next;
		duplicate = false;
		while (a_blocks != NULL) {
			if (my_strcmp(a_blocks->bid, b_blocks->bid) == 0) {
				duplicate = true;
				break;
			}
			a_blocks = a_blocks->next;
		}
		if (duplicate == false) {
			append_block(a_node->genesis, create_block(b_blocks->bid));
		}
		b_blocks = b_blocks->next;
	}
}