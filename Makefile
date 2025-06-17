# **************************************************************************** #
#                              Minitalk - Makefile                            #
# **************************************************************************** #

NAME_MANDATORY	= server client
NAME_BONUS		= server_bonus client_bonus

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I. -Ilib_ft -Ilibftprintf.a

MANDATORY_DIR	= mandatory
BONUS_DIR		= bonus

LIBFT_DIR		= lib_ft
LIBFT			= $(LIBFT_DIR)/libft.a

MANDATORY_SRCS = $(addprefix $(MANDATORY_DIR)/, server.c client.c)
BONUS_SRCS     = $(addprefix $(BONUS_DIR)/, server_bonus.c client_bonus.c)

MANDATORY_SRCS += utils.c
BONUS_SRCS     += utils.c

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS     = $(BONUS_SRCS:.c=.o)

all: $(LIBFT) server client

server: $(MANDATORY_DIR)/server.o utils.o
	$(CC) $(CFLAGS) -o server $^ $(LIBFT)

client: $(MANDATORY_DIR)/client.o utils.o
	$(CC) $(CFLAGS) -o client $^ $(LIBFT)

bonus: $(LIBFT) server_bonus client_bonus

server_bonus: $(BONUS_DIR)/server_bonus.o utils.o
	$(CC) $(CFLAGS) -o server_bonus $^ $(LIBFT)

client_bonus: $(BONUS_DIR)/client_bonus.o utils.o
	$(CC) $(CFLAGS) -o client_bonus $^ $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME_MANDATORY) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re