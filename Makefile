CC := cc
CFLAGS := -Wall -Wextra -Werror \
          -O2
SRCS := ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
        ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlcat.c \
        ft_strlen.c ft_strlcpy.c ft_toupper.c ft_tolower.c ft_strchr.c \
        ft_toupper2.c ft_strrchr.c ft_strncmp.c ft_memchr.c
ASM := $(SRCS:.c=.s)
OBJS := $(SRCS:.c=.o)
NAME := libft.a

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c  -I . $< -o $@

.PHONY: asm
asm: $(ASM)

%.s: %.c
	$(CC) $(CFLAGS) -S -I . $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(ASM)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
