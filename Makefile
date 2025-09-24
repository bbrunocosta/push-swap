# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 13:53:43 by bcosta-b          #+#    #+#              #
#    Updated: 2025/09/23 20:15:58 by bcosta-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RM      = rm -rf

OBJDIR  = obj

SRCS = \
	libs/charft/ft_isdigit.c \
	libs/charft/ft_isspace.c \
	libs/charft/ft_putchar.c \
	libs/listft/lst_push.c \
	libs/listft/lst_detach.c \
	libs/listft/lst_pop.c \
	libs/listft/lst_add_after.c \
	libs/listft/lst_add_before.c \
	libs/listft/lst_add_first.c \
	libs/listft/lst_add_last.c \
	libs/listft/lst_delete.c \
	libs/listft/lst_delete_all.c \
	libs/listft/lst_delete_node.c \
	libs/listft/lst_foreach.c \
	libs/listft/lst_is_detached.c \
	libs/listft/lst_is_equal.c \
	libs/listft/lst_is_first.c \
	libs/listft/lst_is_invalid.c \
	libs/listft/lst_is_last.c \
	libs/listft/lst_new_node.c \
	libs/listft/lst_sum.c \
	libs/mathft/ft_abs.c \
	libs/mathft/ft_atoi.c \
	libs/mathft/to_string_base_prefix.c \
	libs/memft/ft_calloc.c \
	libs/memft/ft_memcpy.c \
	libs/memft/ft_memset.c \
	libs/stringft/ft_strlen.c \
	libs/stringft/put_str.c \
	libs/stringft/str_dup.c \
	libs/stringft/str_free.c \
	libs/stringft/str_new.c \
	libs/stringft/str_new_char.c \
	libs/stringft/str_new_values.c

	
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))


INC_FLAGS = \
	-Isrc \
	-Isrc/normalizers \
	-Isrc/parsers \
	-Ilibs/charft \
	-Ilibs/listft \
	-Ilibs/mathft \
	-Ilibs/memft \
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
