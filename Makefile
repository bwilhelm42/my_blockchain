EXEC = my_blockchain
FILES = main get_word execute_cmd create_node append_block receive_cmd \
		create_block retrieve_backup generate_hash\
		command_functions/add_block command_functions/add_node \
		command_functions/list_nodes_and_blocks command_functions/list_nodes \
		command_functions/rm_block command_functions/rm_node \
		command_functions/save_and_quit command_functions/sync_nodes\
		my_lib_funcs/my_atoi my_lib_funcs/my_putnbr my_lib_funcs/my_strcmp \
		my_lib_funcs/my_strdup my_lib_funcs/my_strlen my_lib_funcs/my_strnstr \
		my_lib_funcs/my_strncmp my_lib_funcs/my_itoa my_lib_funcs/my_memset \
		my_lib_funcs/my_strcpy my_lib_funcs/my_strrev

SRCS = $(addsuffix .c,$(FILES))
OBJS = $(notdir $(addsuffix .o,$(FILES)))

all: exec

exec: objs
	gcc $(FLAGS) -o $(EXEC) $(OBJS)

objs:
	gcc $(FLAGS) -c $(SRCS)

debug:
	gcc $(FLAGS) -g -o debug $(SRCS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(EXEC) debug bc_backup

re: fclean all