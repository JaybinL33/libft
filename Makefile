CC := cc
CFLAGS := -Wall -Wextra -Werror
SRCS := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
        ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c \
        ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
        ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memchr.c ft_memcmp.c \
        ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
        ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
        ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
        ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
        ft_substr.c ft_tolower.c ft_toupper.c

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
