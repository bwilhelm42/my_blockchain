#include "my_bc.h"

static int parse_cmd(char *cmd);

int execute_cmd(char* cmd, t_node **nodes) {
	int error;

	switch (parse_cmd(cmd)) {
		case ADD_NID:
			error = add_node(nodes, cmd);
			break;
		case ADD_BID:
			error = add_block(nodes, cmd);
			break;
		case RM_NID:
			error = rm_node(nodes, cmd);
			break;
		case RM_BID:
			error = rm_block(nodes, cmd);
			break;
		case LS:
			error = list_nodes(nodes);
			break;
		case LS_L:
			error = list_nodes_and_blocks(nodes);
			break;
		case SYNC:
			error = sync_nodes(nodes);
			break;
		case QUIT:
			save_and_quit(nodes);
			error = QUIT;
			break;
		default:
			error = COMMAND_NOT_FOUND;
			break;
	}
	return error;
}

static int parse_cmd(char *cmd) {
	char *commands[] = {"add node ", "add block ", "rm node ", "rm block ", "ls -l", "ls", "sync", "quit"};

	for (int i = 0; i < 8; i++) {
		if (my_strncmp(cmd, commands[i], my_strlen(commands[i])) == 0) {
			return i + 1;
		}
	}
	return -1;
}