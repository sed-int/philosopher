/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:25:06 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/24 11:39:18 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_leak(void)
{
	system("leaks philo");
}

void	philo(char	**av)
{
	t_env	*env;
	int		i;

	env = malloc(sizeof(t_env));
	init_env(env, av);
	init_philo(env, env->philos);
	i = 0;
	while (i < env->arg.number_of_philos)
		pthread_join(env->philos[i++].thr, 0);
	i = 0;
	while (i < env->arg.number_of_philos)
		pthread_mutex_destroy(&env->mutex[i++]);
	free_all(env);
}

int	main(int ac, char **av)
{
	// atexit(check_leak);
	if (ac < 5 || ac > 6)
	{
		printf("Error: Wrong argument count.\n");
		return (1);
	}
	philo(av);
}
