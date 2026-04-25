CC := cc
CFLAGS := -Wall -Wextra -Werror -g

TEST_SRCS := $(wildcard *.c)
TEST_OBJS := $(TEST_SRCS:.c=.o)
TEST_BIN := test

LIB_DIR := ..
LIB_H := $(LIB_DIR)/libft.h
LIB_A := $(LIB_DIR)/libft.a

all: $(TEST_BIN)

$(TEST_BIN): $(TEST_OBJS) $(LIB_A)
	$(CC) $(CFLAGS) $(TEST_OBJS) -L$(LIB_DIR) -lft -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

$(LIB_A):
	make -C $(LIB_DIR) all

clean:
	rm -f $(TEST_OBJS)

fclean: clean
	rm -f $(TEST_BIN)

re: fclean all

.PHONY: all clean fclean re $(LIB_A)
