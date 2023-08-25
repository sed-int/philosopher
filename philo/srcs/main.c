/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:25:06 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/25 15:08:56 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo(char	**av)
{
	pthread_t	monitor_thr;
	t_env		*env;
	int			i;

	env = malloc(sizeof(t_env));
	init_env(env, av);
	pthread_create(&monitor_thr, 0, monitor, env);
	init_philo(env, env->philos);
	i = 0;
	while (i < env->arg.number_of_philos)
		pthread_join(env->philos[i++].thr, 0);
	pthread_join(monitor_thr, 0);
	i = 0;
	while (i < env->arg.number_of_philos)
		pthread_mutex_destroy(&env->mutex[i++]);
	pthread_mutex_destroy(&env->dead_mutex);
	free_all(env);
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error: Wrong argument count.\n");
		return (1);
	}
	philo(av);
}
