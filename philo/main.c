/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:30:08 by saragar2          #+#    #+#             */
/*   Updated: 2025/05/14 20:03:57 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char *arg)
{
	perror(arg);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_general	g;

	init_and_errs(&g, argc, argv);
	create_philos(&g);
	limpiarlas(&g);
}
