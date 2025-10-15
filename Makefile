# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 13:53:43 by bcosta-b          #+#    #+#              #
#    Updated: 2025/10/03 05:08:16 by bcosta-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RM      = rm -rf

OBJDIR  = obj

SRCS = \
	libs/hsft/*.c \
	libs/charft/*.c \
	libs/listft/*.c \
	libs/mathft/*.c \
	libs/memft/*.c \
	libs/stringft/*.c 

	
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
	$(CC) $(INC_FLAGS) $(NAME) $(SRCS) *.c && ./a.out $(shell shuf -i 1-$(N) -n $(N))


