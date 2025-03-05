/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:18:26 by saragar2          #+#    #+#             */
/*   Updated: 2025/03/05 18:39:37 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_isvalidnum(char *s)
{
    int i;
	int	res;

	i = 0;
	while(s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	res = ft_atoi(s);
	if (res <= 0)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	nb;
	int	minus;

	nb = 0;
	minus = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*(str + 1) == '+' || *(str + 1) == '-')
			return (0);
		else if (*str == '-')
			minus = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	if (nb * minus <= 0)
		print_error("You can't use 0");
	return (nb * minus);
}

int	f_strcmp(const char *s1, const char *s2)
{
	int	cont;

	cont = 0;
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		cont = (unsigned char)*s1 - (unsigned char)*s2;
	return (cont);
}