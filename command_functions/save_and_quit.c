#include "../my_bc.h"

int save_and_quit(t_node **nodes) {
	t_block *blocks;
	t_node **head = nodes;
	int fd;
	char *buf;

	fd = open("bc_backup", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	buf = (char*)malloc(10);
	my_memset(buf, '\0', 10);
	while (nodes  != NULL && *nodes != NULL) {
		my_itoa((*nodes)->nid, buf, 10);
		write(fd, buf, 10);
		blocks = (*nodes)->genesis->next;
		while (blocks != NULL) {
			my_memset(buf, '\0', 10);
			my_strcpy(buf, blocks->bid);
			write(fd, buf, 10);
			blocks = blocks->next;
		}
		my_memset(buf, '\0', 10);
		write(fd, buf, 10);
		nodes = &(*nodes)->next;
	}
	free(buf);
	close(fd);
	if (*head) {
		rm_node(head, "rm node *");
	}
	return 0;
}
