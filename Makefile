
NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRCS := pipex.c process_utils.c path_utils.c print_error.c \
        libft/ft_split.c \
		libft/ft_strdup.c \
		libft/ft_strlcpy.c \
		libft/ft_strlcat.c \
        libft/ft_strlen.c \
		libft/ft_strncmp.c \
		libft/ft_strchr.c \
		libft/ft_substr.c \
		libft/ft_putendl_fd.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


