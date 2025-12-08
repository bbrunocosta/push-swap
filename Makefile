# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 13:53:43 by bcosta-b          #+#    #+#              #
#    Updated: 2025/12/08 11:28:53 by bcosta-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = push_swap
LIBFT      = libft.a
CC         = cc
CFLAGS     = -Wall -Wextra -Werror
AR         = ar rcs
RM         = rm -rf

OBJDIR     = obj
SRCDIR     = src

# Arquivos das bibliotecas
LIB_SRCS = \
	$(wildcard libs/hsft/*.c) \
	$(wildcard libs/charft/*.c) \
	$(wildcard libs/listft/*.c) \
	$(wildcard libs/mathft/*.c) \
	$(wildcard libs/memft/*.c) \
	$(wildcard libs/stringft/*.c)

# Arquivos do push_swap
PUSH_SWAP_SRCS = \
	$(SRCDIR)/main.c \
	$(wildcard $(SRCDIR)/instructions/*.c) \
	$(wildcard $(SRCDIR)/parser/*.c) \
	$(wildcard $(SRCDIR)/utils/*.c) \
	$(wildcard $(SRCDIR)/algorithms/*.c)

LIB_OBJS        = $(patsubst %.c,$(OBJDIR)/%.o,$(LIB_SRCS))
PUSH_SWAP_OBJS  = $(patsubst %.c,$(OBJDIR)/%.o,$(PUSH_SWAP_SRCS))

INC_FLAGS = \
	-Ilibs/charft \
	-Ilibs/listft \
	-Ilibs/mathft \
	-Ilibs/memft \
	-Ilibs/hsft \
	-Ilibs/stringft \
	-I$(SRCDIR)

all: $(NAME)

$(LIBFT): $(LIB_OBJS)
	$(AR) $@ $^

$(NAME): $(LIBFT) $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) $(LIBFT) -lm -o $@

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

bonus: all

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

start: all
	@if [ -z "$(N)" ]; then \
		echo "Usage: make start N=<number>"; \
		exit 1; \
	fi
	@./$(NAME) $$(shuf -i 1-$(N) -n $(N))

test: all
	@if [ -z "$(N)" ]; then \
		echo "Usage: make test N=<number>"; \
		exit 1; \
	fi
	@ARG=$$(shuf -i 1-$(N) -n $(N) | tr '\n' ' '); \
	echo "Testing with $(N) numbers: $$ARG"; \
	RESULT=$$(./$(NAME) $$ARG | ./checker_linux $$ARG); \
	MOVES=$$(./$(NAME) $$ARG | wc -l); \
	echo "Result: $$RESULT"; \
	echo "Moves: $$MOVES"

.PHONY: all clean bonus fclean re start test


