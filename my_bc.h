#ifndef MY_BC_H
#define MY_BC_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>

#define ADD_NID	1
#define ADD_BID	2
#define RM_NID	3
#define RM_BID	4
#define LS_L	5
#define LS		6
#define SYNC	7
#define QUIT	8

#define NO_MORE_RESOURCES	1
#define NODE_EXISTS			2
#define BLOCK_EXISTS		3
#define NODE_DOESNT_EXIST	4
#define BLOCK_DOESNT_EXIST	5
#define COMMAND_NOT_FOUND	6

typedef struct s_block {
	char* bid;
	int hash;
	struct s_block *next;
} t_block;

typedef struct s_node {
	int nid;
	struct s_block *genesis;
	int root_hash;
	struct s_node *next;
} t_node;

//my_lib_functions
void my_putnbr(int nbr);
int my_strcmp(char *s1, char *s2);
char *my_itoa(int n, char *dest, int len);
char* my_strdup(char* str);
void my_memset(char *s, int c, int size);
void my_strcpy(char *dest, char *src);
int my_strlen(char* str);
int my_atoi(char* str);
char* my_strnstr(char* big, char* little, int n);
int my_strncmp(char* s1, char* s2, int n);
void my_strrev(char *str);

//cmd functions
int add_block(t_node **nodes, char* cmd);
int add_node(t_node **nodes, char* cmd);
int list_nodes_and_blocks(t_node **nodes);
int list_nodes(t_node **nodes);
int rm_block(t_node **nodes, char* cmd);
int rm_node(t_node **nodes, char* cmd);
int save_and_quit(t_node **nodes);
int sync_nodes(t_node **nodes);

int append_block(t_block *genesis, t_block *new_block);
int generate_hash(t_block *genesis);
t_node* create_node(int nid);
t_block* create_block(char* bid);
int execute_cmd(char* cmd, t_node **nodes);
int retrieve_backup(int fd, t_node **nodes);
char* get_word(char* str, int n);
char* receive_cmd(t_node *nodes);

#endif