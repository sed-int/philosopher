/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:19:44 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/21 17:06:09 by hcho2            ###   ########.fr       */
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
	env->philos = malloc(sizeof(t_philo) * arg.number);
	env->fork = malloc(sizeof(char) * arg.number);
	env->mutex = malloc(sizeof(pthread_mutex_t) * arg.number);
	env->is_dead = -1;
	i = -1;
	while (++i < arg.number)
		pthread_mutex_init(env->mutex + i, NULL);
	if (!env->philo || !env->fork)
		exit(1);
}

void	init_philo(t_env *env, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < env->arg.number_of_philos)
	{
		philos[i].num = i;
		philos[i].eat_cnt = 0;
		philos[i].start_time = 0;
		philos[i].last_eat_time = 0;
		philos[i].last_sleep_time = 0;
		philos[i].stat = THINKING;
		philos[i].env = env;
	}
	i = 0;
	while (i < env->arg.number_of_philos)
		pthread_create(philos[i++].thr, 0, routine, 0);
}

void	philo(char	**av)
{
	t_env	env;
	int		i;

	init_env(&env);
	i = 0;
	while (i < env.arg.number_of_philo)
		init_philo(&env, env.philos[i++]);
}
