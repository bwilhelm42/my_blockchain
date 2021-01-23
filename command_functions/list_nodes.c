#include "../my_bc.h"

int list_nodes(t_node **nodes) {
	t_node *temp = *nodes;

	while (temp != NULL) {
		printf("%d\n", temp->nid);
		temp = temp->next;
	}
	return 0;
}