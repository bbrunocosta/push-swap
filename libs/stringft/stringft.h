/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 00:01:18 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/10/03 02:22:18 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGFT_H
# define STRINGFT_H

# include <stddef.h>

typedef struct s_string
{
	char	*value;
	size_t	length;
	
}	t_string;

t_string	*str_new(size_t len);
t_string	*str_new_char(char c);
t_string	*str_new_values(char *value, size_t len);
t_string	*str_dup(const char *s);
size_t		ft_strlen(const char *s);
size_t		put_string(t_string *str);
void		str_free(void *str);
#endif