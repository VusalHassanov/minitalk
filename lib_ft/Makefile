# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 21:19:28 by ncolomer          #+#    #+#              #
#    Updated: 2025/06/13 19:44:39 by vhasanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_FILES = ft_isalnum.c ft_isprint.c ft_memcmp.c ft_striteri.c ft_putchar_fd.c \
			  ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
			  ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_strjoin.c ft_strtrim.c \
			  ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_strmapi.c \
			  ft_memmove.c ft_strdup.c ft_strlen.c ft_strrchr.c ft_itoa.c \
			  ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c \
			  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strcmp.c
			  
PRINTF_FILES = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_ptr.c

LIBFT_SRCS = $(addprefix libft/, $(LIBFT_FILES))
PRINTF_SRCS = $(addprefix ft_printf/, $(PRINTF_FILES))

SRCS = $(LIBFT_SRCS) $(PRINTF_SRCS)
OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft -Ift_printf

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re