/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 01:05:52 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/10/01 22:56:08 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHFT_H
# define MATHFT_H
#include <stddef.h>

unsigned long long	ft_abs(long long number);
int					ft_atoi(const char *nptr);
size_t				next_prime(size_t n);
int					ft_is_prime(size_t n);
#endif