/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:30:08 by saragar2          #+#    #+#             */
/*   Updated: 2025/04/16 17:02:46 by saragar2         ###   ########.fr       */
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
	t_general g;

	// printf("\ndebug\n");
	
	init_and_errs(&g, argc, argv);
	create_philos(&g);
	limpiarlas(&g);
}


// -----NOTAS-----
// Hay que hacer los free de todos los malloc en caso de error y al finalizar el programa
// Hay que hacer la rutina y programar a pakita la cotilla
// hay que hardcodear el caso del filosofo solo
// como putas se usan g->philos y philo->thread????
// Norminette
// pakita no se está chivando cuando mueren
// En el caso de one_philo saltan problemas (y ademas lo hace mal)
// quita los putos mutex de t_philo y metelos en general, que sino con 200 philos hay 600 mutex (y se usan 3)