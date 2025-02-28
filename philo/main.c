/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:30:08 by saragar2          #+#    #+#             */
/*   Updated: 2025/02/27 20:38:59 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char *arg)
{
	perror(arg);
	exit(1);
}

int main(int argc, char **argv)
{
// 	t_general	g;

// 	init_and_errs(&g, argc, argv);
	if (!ft_isvalidnum(argv[1]))
		printf("yayy 1\n\n");
	if (!ft_isvalidnum(argv[2]))
		printf("yayy 2\n\n");
	if (!ft_isvalidnum(argv[3]))
		printf("yayy 3\n\n");
	if (!ft_isvalidnum(argv[4]))
		printf("yayy 4\n\n");
}


// -----NOTAS-----
// Hay que hacer los free de todos los malloc en caso de error y al finalizar el programa
// Hay que hacer la rutina y programar a pakita la cotilla
// hay que hardcodear el caso del filosofo solo
// como putas se usan g->philos y philo->thread????
// Norminette