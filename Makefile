# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 13:53:43 by bcosta-b          #+#    #+#              #
#    Updated: 2025/12/06 22:50:54 by bcosta-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RM      = rm -rf

OBJDIR  = obj

SRCS = \
	$(wildcard libs/hsft/*.c) \
	$(wildcard libs/charft/*.c) \
	$(wildcard libs/listft/*.c) \
	$(wildcard libs/mathft/*.c) \
	$(wildcard libs/memft/*.c) \
	$(wildcard libs/stringft/*.c) 

	
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))


INC_FLAGS = \
	-Ilibs/charft \
	-Ilibs/listft \
	-Ilibs/mathft \
	-Ilibs/memft \
	-Ilibs/hsft \
	-Ilibs/stringft

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

bonus: all

fclean: clean
	$(RM) $(NAME)

re: fclean all


start: all
	$(CC) $(INC_FLAGS) -lm $(NAME) $(SRCS) *.c && ./a.out $(shell shuf -i 1-$(N) -n $(N))

push_swap: all
	$(CC) $(CFLAGS) $(INC_FLAGS) push_swap.c chunkish.c $(NAME) -lm -o push_swap

test: push_swap
	@ARG=$$(shuf -i 1-$(N) -n $(N) | tr '\n' ' '); \
	echo "Testing with $(N) numbers: $$ARG"; \
	RESULT=$$(./push_swap $$ARG | ./checker_linux $$ARG); \
	MOVES=$$(./push_swap $$ARG | wc -l); \
	echo "Result: $$RESULT"; \
	echo "Moves: $$MOVES"

.PHONY: all clean bonus fclean re start push_swap test


