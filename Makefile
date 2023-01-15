NAME = 42labs
ENC = encoder
DEC = decoder

PATH_INCS = ./includes/
PATH_OBJS = ./objects/
PATH_SRCS = ./sources/

SRCS_ENC = $(addprefix $(PATH_SRCS),\
		encoder.c\
		compress.c\
		encode.c\
		get_str_size.c\
		share_info.c\
		dictionary_clear.c\
		dictionary_create.c\
		dictionary_init.c\
		dictionary_print.c\
		list_create.c\
		list_fill.c\
		list_node_new.c\
		list_node_remove.c\
		list_print.c\
		list_sorted_insert.c\
		tree_build.c\
		tree_free.c\
		tree_height.c\
		tree_print.c)
SRCS_DEC = $(addprefix $(PATH_SRCS),\
		decompress.c\
		decode.c\
		decoder.c)

OBJS_ENC = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS_ENC))
OBJS_DEC = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS_DEC))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I $(PATH_INCS)

all: $(NAME)

$(NAME): $(ENC) $(DEC)

$(ENC): $(OBJS_ENC)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(ENC) $(OBJS_ENC)

$(DEC): $(OBJS_DEC)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(DEC) $(OBJS_DEC)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@rm -rf $(PATH_OBJS)

fclean: clean
	@rm $(ENC)
	@rm $(DEC)

re: fclean all

n:
	@clear
	@norminette ./sources ./includes

git:
	@clear
	@git status
	@sleep 1 && echo 5 && sleep 1 && echo 4 && sleep 1 && echo 3 && sleep 1 && echo 2 && sleep 1 && echo 1 && sleep 2
	@git add .
	@git commit -m 'Automatic commit via Makefile'
	@git push
	@clear
	@git status

PHONY: all clean fclean re n git