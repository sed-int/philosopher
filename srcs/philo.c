/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:19:44 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/20 20:43:10 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_env(t_env *env)
{
	int	i;

	env->arg.number_of_philo = ft_atoi(av[1]);
	env->arg.time_to_die = ft_atoi(av[2]);
	env->arg.time_to_eat = ft_atoi(av[3]);
	env->arg.time_to_sleep = ft_atoi(av[4]);
	env->arg.must_eat_count = 1;
	if (av[5] != NULL)
		env->arg.must_eat_count = ft_atoi(av[5]);
	env->philo = malloc(sizeof(t_philo) * arg.number);
	env->fork = malloc(sizeof(char) * arg.number);
	env->mutex = malloc(sizeof(pthread_mutex_t) * arg.number);
	i = -1;
	while (++i < arg.number)
		pthread_mutex_init(env->mutex + i, NULL);
	if (!env->philo || !env->fork)
		exit(1);
}

void	philo(char	**av)
{
	t_env	env;

	init_env(&env);
}
