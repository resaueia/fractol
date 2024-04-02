/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:33:06 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/04/02 18:35:34 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}

void	putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if (s == NULL || fd < 0)
		return ;
	while (s[index])
		write(fd, &s[index++], 1);
}

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	power;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	power = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while (*s == '+' || *s == '-')
		if (*s == '-')
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		power /= 10;
		fractional_part = fractional_part + (*s++ - 48) * power;
	}
	return ((integer_part + fractional_part) * sign);
}
