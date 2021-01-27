#include "../my_bc.h"

static int add_block_to_all_nodes(t_node **nodes, char* bid);

int add_block(t_node **nodes, char* cmd) {
	char* str_nid;
	int nid;
	char* bid;
	t_block *new_block;

	bid = get_word(cmd, 3);
	str_nid = get_word(cmd, 4);
	if (*str_nid == '*') {
		add_block_to_all_nodes(nodes, bid);
		free(bid);
		return 0;
	}
	nid = my_atoi(str_nid);
	while (*nodes && (*nodes)->next != NULL && (*nodes)->nid != nid) {
		nodes = &(*nodes)->next;
	}
	if (!*nodes || (*nodes)->nid != nid) {
		free(str_nid);
		free(bid);
		return NODE_DOESNT_EXIST;
	}
	new_block = create_block(bid);
	free(bid);
	free(str_nid);
	if (new_block == NULL) {
		return NO_MORE_RESOURCES;
	}
	if (append_block((*nodes)->genesis, new_block) == BLOCK_EXISTS) {
		return BLOCK_EXISTS;
	}
	(*nodes)->root_hash = generate_hash((*nodes)->genesis);
	return 0;
}

static int add_block_to_all_nodes(t_node **nodes, char* bid) {
	t_block *new_block;

	while (*nodes != NULL) {
		new_block = create_block(bid);
		if (new_block == NULL) {
			return NO_MORE_RESOURCES;
		}
		append_block((*nodes)->genesis, new_block);
		(*nodes)->root_hash = generate_hash((*nodes)->genesis);
		nodes = &(*nodes)->next;
		if (*nodes == NULL) {
			return 0;
		}
	}
	return 0;
}
