/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:25:06 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/27 15:16:37 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo(char	**av)
{
	pthread_t	monitor_thr[2];
	t_env		*env;
	int			i;

	env = malloc(sizeof(t_env));
	init_env(env, av);
	pthread_create(&monitor_thr[0], 0, count_monitor, env);
	pthread_create(&monitor_thr[1], 0, death_monitor, env);
	init_philo(env, env->philos);
	i = 0;
	while (i < env->arg.number_of_philos)
		pthread_join(env->philos[i++].thr, 0);
	pthread_join(monitor_thr[0], 0);
	pthread_join(monitor_thr[1], 0);
	i = 0;
	while (i < env->arg.number_of_philos)
		pthread_mutex_destroy(&env->mutex[i++]);
	pthread_mutex_destroy(&env->over_mutex);
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
