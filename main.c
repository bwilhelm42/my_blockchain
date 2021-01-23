#include "my_bc.h"

static void error_output(int error);

int main() {
	t_node *nodes = NULL;
	int fd;
	char* cmd;
	int error;

	fd = open("bc_backup", O_RDONLY);
	printf("%s\n", fd == -1 ? "No Backup Found: Starting New Blockchain" : "Restoring From Backup");
	if (fd != -1) {
		retrieve_backup(fd, &nodes);
	}
	while (true) {
		cmd = receive_cmd(nodes);
		error = execute_cmd(cmd, &nodes);
		free(cmd);
		if (error == QUIT) {
			error_output(error);
			return 0;
		}
		if (error != 0) {
			error_output(error);
		}
	}
	return 0;
}

static void error_output(int error) {
	switch(error) {
		case NO_MORE_RESOURCES:
			printf("No more resources\n");
			break;
		case NODE_EXISTS:
			printf("Node already exists\n");
			break;
		case BLOCK_EXISTS:
			printf("Block already exists\n");
			break;
		case NODE_DOESNT_EXIST:
			printf("Node doesn't exist\n");
			break;
		case BLOCK_DOESNT_EXIST:
			printf("Block doesn't exist\n");
			break;
		case COMMAND_NOT_FOUND:
			printf("Command not found\n");
			break;
		case QUIT:
			printf("Backing up blockchain...\nQuitting\n");
			break;
		default:
			printf("Unknown error\n");
			break;
	}
}