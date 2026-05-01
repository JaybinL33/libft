srcdir = .
SHELL = /usr/bin/env bash

SRC_DIR = $(srcdir)/src
SRC_DIRS = $(addprefix $(SRC_DIR)/, ftctype ftstring ftstdlib ftcustom ftllist)

SRCS_FTCTYPE = $(addprefix $(SRC_DIR)/ftctype/, \
                ft_isalnum.c \
                ft_isalpha.c \
                ft_isascii.c \
                ft_isdigit.c \
                ft_isprint.c \
                ft_tolower.c \
                ft_toupper.c \
                )
SRCS_FTSTRING = $(addprefix $(SRC_DIR)/ftstring/, \
                 ft_bzero.c \
                 ft_memchr.c \
                 ft_memcmp.c \
                 ft_memcpy.c \
                 ft_memmove.c \
                 ft_memset.c \
                 ft_strchr.c \
                 ft_strdup.c \
                 ft_strlcat.c \
                 ft_strlcpy.c \
                 ft_strlen.c \
                 ft_strncmp.c \
                 ft_strnstr.c \
                 ft_strrchr.c \
                 )
SRCS_FTSTDLIB = $(addprefix $(SRC_DIR)/ftstdlib/, \
                 ft_atoi.c \
                 ft_calloc.c \
                 )
SRCS_FTCUSTOM = $(addprefix $(SRC_DIR)/ftcustom/, \
                 ft_itoa.c \
                 ft_putchar_fd.c \
                 ft_putendl_fd.c \
                 ft_putnbr_fd.c \
                 ft_putstr_fd.c \
                 ft_split.c \
                 ft_striteri.c \
                 ft_strjoin.c \
                 ft_strmapi.c \
                 ft_strtrim.c \
                 ft_substr.c \
                 )
SRCS_FTLLIST = $(addprefix $(SRC_DIR)/ftllist/, \
                ft_lstadd_back.c \
                ft_lstadd_front.c \
                ft_lstclear.c \
                ft_lstdelone.c \
                ft_lstiter.c \
                ft_lstlast.c \
                ft_lstmap.c \
                ft_lstnew.c \
                ft_lstsize.c \
                )
SRCS = $(SRCS_FTCTYPE) $(SRCS_FTSTRING) $(SRCS_FTSTDLIB) $(SRCS_FTCUSTOM) $(SRCS_FTLLIST)

OUT_DIR = .
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
DEP_DIR = $(BUILD_DIR)/dep
ASM_DIR = $(BUILD_DIR)/asm
OBJ_DIRS = $(SRC_DIRS:$(SRC_DIR)/%=$(OBJ_DIR)/%)
DEP_DIRS = $(SRC_DIRS:$(SRC_DIR)/%=$(DEP_DIR)/%)
ASM_DIRS = $(SRC_DIRS:$(SRC_DIR)/%=$(ASM_DIR)/%)

CONFIG = config.mk

NAME := $(OUT_DIR)/libft.a
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS = $(SRCS:$(SRC_DIR)/%.c=$(DEP_DIR)/%.d)
ASMS = $(SRCS:$(SRC_DIR)/%.c=$(ASM_DIR)/%.s)

CC = cc
CPPFLAGS = -I$(srcdir)/include/
CFLAGS = -Wall -Wextra -Werror -O2
DEPFLAGS = -MMD -MP
CFLAGS_ALL = $(CPPFLAGS) $(CFLAGS) $(DEPFLAGS)

RM = rm -f

-include $(CONFIG)

UNAME ?= $(shell uname -s)
ifeq ($(UNAME), Linux)
AR ?= ar
ARFLAGS ?= -rcsD
else ifeq ($(UNAME), Darwin)
AR ?= ZERO_AR_DATE=1 ar
ARFLAGS ?= -rcs
endif


.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) | $(OUT_DIR)
	$(RM) $@.tmp
	$(AR) $(ARFLAGS) $@.tmp $^
	mv -f $@.tmp $@

$(OBJ_DIRS) $(DEP_DIRS) $(ASM_DIRS) $(OUT_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIRS) $(DEP_DIRS)
	$(CC) $(CFLAGS_ALL) -MF $(DEP_DIR)/$*.d -c $< -o $@

.PHONY: asm
asm: $(ASMS)
$(ASM_DIR)/%.s: $(SRC_DIR)/%.c | $(ASM_DIRS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -fverbose-asm -S $< -o $@

.PHONY: mostlyclean clean fclean
mostlyclean:
	$(RM) -r $(BUILD_DIR)
clean: mostlyclean
	$(RM) $(NAME)
fclean: clean
	$(RM) $(CONFIG)

.PHONY: re
re:
	$(MAKE) clean
	$(MAKE) all

.SUFFIXES:
(%) : % ;
%.a : ;

-include $(DEPS)
