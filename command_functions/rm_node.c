#include "../my_bc.h"

static int free_all_blocks(t_block *blocks);
static void free_node(t_node *node);
static int free_all_nodes(t_node **nodes);

int rm_node(t_node **nodes, char* cmd) {
	char* str_nid;
	int nid;
	int ret;
	t_node *temp = NULL;

	str_nid = get_word(cmd, 3);
	if (*str_nid == '*') {
		free(str_nid);
		free_all_nodes(nodes);
		return 0;
	}
	nid = my_atoi(str_nid);
	while (*nodes && (*nodes)->nid != nid) {
		temp = *nodes;
		nodes = &(*nodes)->next;
	}
	if (!*nodes || (*nodes)->nid != nid) {
		free(str_nid);
		return NODE_DOESNT_EXIST;
	}
	temp = (*nodes)->next;
	free_node(*nodes);
	*nodes = temp;
	return 0;
}

static int free_all_nodes(t_node **nodes) {
	if ((*nodes)->next != NULL) {
		free_all_nodes(&(*nodes)->next);
	}
	free_node(*nodes);
	return 0;
}

static void free_node(t_node *node) {
	free_all_blocks(node->genesis);
	free(node);
}

static int free_all_blocks(t_block *blocks) {
	if (blocks->next != NULL) {
		free_all_blocks(blocks->next);
	}
	if (blocks->bid != NULL) {
		free(blocks->bid);
	}
	free(blocks);
	return 0;
}