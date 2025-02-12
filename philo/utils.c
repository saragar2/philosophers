/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:18:26 by saragar2          #+#    #+#             */
/*   Updated: 2025/02/12 16:19:01 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_isvalidnum(char *s)
{
    int i;

	i = 0;
	while(s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
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
	return (nb * minus);
}