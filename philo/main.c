/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:30:08 by saragar2          #+#    #+#             */
/*   Updated: 2025/02/06 17:10:06 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_error(char *arg)
{
	perror(arg);
	exit(1);
}

int	init_and_errs(t_general *g, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		print_error("Invalid amount of arguments");
	if (ft_isvalidnum(argv[1]) == 1 || ft_isvalidnum(argv[2]) == 1 || 
		ft_isvalidnum(argv[3]) == 1 || ft_isvalidnum(argv[4]) == 1 ||
		(argc == 6 && ft_isvalidnum(argv[5]) == 1))
		print_error("Invalid argument");
	g->num = ft_atoi(argv[1]);
	g->t_die = ft_atoi(argv[2]);
	g->t_eat = ft_atoi(argv[3]);
	g->t_sleep = ft_atoi(argv[4]);
	
	if (argc == 6)
		g->num_t_eat = ft_atoi(argv[5]);
	return (0);
}
int main(int argc, char **argv)
{
	t_general	g;

	init_and_errs(&g, argc, argv);
		
}


// rutinaq