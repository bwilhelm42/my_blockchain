#include "../my_bc.h"

int add_node(t_node **nodes, char* cmd) {
	int nid;
	
	nid = my_atoi(get_word(cmd, 3));
	if (nid == 0) {
		return COMMAND_NOT_FOUND;
	}
	while (*nodes) {
		if ((*nodes)->nid == nid) {
			return NODE_EXISTS;
		}
		nodes = &(*nodes)->next;
	}
	*nodes = create_node(nid);
	return *nodes == NULL ? NO_MORE_RESOURCES : 0;
}