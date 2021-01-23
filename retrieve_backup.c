#include "my_bc.h"

int retrieve_backup(int fd, t_node **nodes) {
	int ret;
	char buf[10];
	
	while ((ret = read(fd, buf, 10)) != 0) {
		if (buf[0] == '\0') {
			nodes = &(*nodes)->next;
		}
		else if (*nodes == NULL) {
			*nodes = create_node(my_atoi(buf));
		}
		else {
			append_block((*nodes)->genesis, create_block(buf));
			(*nodes)->root_hash = generate_hash((*nodes)->genesis);
		}
	}
	return 0;
}