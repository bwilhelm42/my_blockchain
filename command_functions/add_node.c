#include "../my_bc.h"

int add_node(t_node **nodes, char* cmd) {
	int nid;
	char* str_nid;
	
	str_nid = get_word(cmd, 3);
	nid = my_atoi(str_nid);
	free(str_nid);
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