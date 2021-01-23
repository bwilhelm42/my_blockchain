#include "my_bc.h"

static int count_nodes(t_node* list);
static bool check_sync(t_node *nodes);

char* receive_cmd(t_node *nodes) {
	int node_count;
	int bytes_read;
	bool sync;
	char* user_cmd;

	// This chunk prints out the prompt to type a command
	// I didn't use printf because I need it to print w/o a '\n'
	node_count = count_nodes(nodes);
	sync = check_sync(nodes);
	write(1, "[", 1);
	sync == true ? write(1, "s", 1) : write(1, "-", 1);
	my_putnbr(node_count);
	write(1, "]> ", 3);

	// Take input from user (max 20 characters)
	user_cmd = (char*)malloc(101);
	bytes_read = read(0, user_cmd, 100);
	user_cmd[bytes_read] = '\0';

	return user_cmd;
}

static bool check_sync(t_node *nodes) {
	int ret = 0;

	while (nodes != NULL) {
		nodes->root_hash = generate_hash(nodes->genesis);
		if (nodes->next != NULL) {
			ret = nodes->root_hash - nodes->next->root_hash;
		}
		else {
			return 1;
		}
		if (ret != 0) {
			return 0;
		}
		nodes = nodes->next;
	}
	return 1;
}

static int count_nodes(t_node* list) {
	int count = 0;

	while (list != NULL) {
		count++;
		list = list->next;
	}
	return count;
}