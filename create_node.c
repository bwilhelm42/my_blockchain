#include "my_bc.h"

t_node* create_node(int nid) {
	t_node *new_node;

	new_node = (t_node*)malloc(sizeof(t_node));

	if (new_node == NULL) {
		return NULL;
	}
	new_node->next = NULL;
	new_node->genesis = create_block(NULL);
	new_node->root_hash = 0;
	new_node->nid = nid;
	
	return new_node;
}