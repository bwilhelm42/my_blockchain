#include "../my_bc.h"

static int free_block(t_block *genesis, char* bid);

int rm_block(t_node **nodes, char* cmd) {
	char *bid;
	char *str_nid;
	int nid;

	bid = get_word(cmd, 3);
	str_nid = get_word(cmd, 4);
	while (*str_nid == '*') {
		if (free_block((*nodes)->genesis, bid) != 0) {
			return BLOCK_DOESNT_EXIST;
		}
		nodes = &(*nodes)->next;
		if (*nodes == NULL) {
			free(bid);
			free(str_nid);
			return 0;
		}
	} 
	nid = my_atoi(str_nid);
	while ((*nodes)->next != NULL && (*nodes)->nid != nid) {
		nodes = &(*nodes)->next;
	}
	if ((*nodes)->next == NULL && (*nodes)->nid != nid) {
		free(bid);
		free(str_nid);
		return NODE_DOESNT_EXIST;
	}
	if (free_block((*nodes)->genesis, bid) != 0) {
		free(bid);
		free(str_nid);
		return BLOCK_DOESNT_EXIST;
	}	
	free(bid);
	free(str_nid);
	return 0;
}

static int free_block(t_block *genesis, char* bid) {
	t_block *temp;

	while (genesis->next != NULL && my_strcmp(genesis->next->bid, bid) != 0) {
		genesis = genesis->next;
	}
	if (genesis->next == NULL) {
		return BLOCK_DOESNT_EXIST;
	}
	temp = genesis->next->next;
	free(genesis->next->bid);
	free(genesis->next);
	genesis->next = temp;
	return 0;
}