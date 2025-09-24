/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 01:05:52 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/08/21 01:36:26 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHFT_H
# define MATHFT_H

# include "stringft.h"

unsigned long long	ft_abs(long long number);
int					ft_atoi(const char *nptr);
t_string			*to_string_base_prefix(unsigned long long number,
						const char *template, int base);

#endif