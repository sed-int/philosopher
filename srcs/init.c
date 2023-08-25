/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:25:59 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/25 18:19:19 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid(t_env *env)
{
	if (env->arg.number_of_philos <= 0)
		return (0);
	else if (env->arg.time_to_die <= 0)
		return (0);
	else if (env->arg.time_to_eat <= 0)
		return (0);
	else if (env->arg.time_to_sleep <= 0)
		return (0);
	else if (env->arg.must_eat_count <= 0)
		return (0);
	return (1);
}

void	init_env(t_env *env, char **av)
{
	int		i;

	env->arg.number_of_philos = ft_atoi(av[1]);
	env->arg.time_to_die = ft_atoi(av[2]);
	env->arg.time_to_eat = ft_atoi(av[3]);
	env->arg.time_to_sleep = ft_atoi(av[4]);
	env->arg.must_eat_count = INT32_MAX;
	if (av[5] != NULL)
		env->arg.must_eat_count = ft_atoi(av[5]);
	env->philos = malloc(sizeof(t_philo) * env->arg.number_of_philos);
	env->forks = malloc(sizeof(char) * env->arg.number_of_philos);
	env->mutex = malloc(sizeof(pthread_mutex_t) * env->arg.number_of_philos);
	env->start_time = get_time();
	env->is_over = !is_valid(env);
	env->eat_cnt = 0;
	i = -1;
	while (++i < env->arg.number_of_philos)
		pthread_mutex_init(env->mutex + i, NULL);
	pthread_mutex_init(&env->dead_mutex, NULL);
}

void	init_philo(t_env *env, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < env->arg.number_of_philos)
	{
		philos[i].num = i + 1;
		philos[i].eat_cnt = 0;
		philos[i].last_eat_time = 0;
		philos[i].is_dead = 0;
		philos[i].last_sleep_time = 0;
		philos[i].env = env;
		philos[i].left = i;
		philos[i].right = (i + 1) % env->arg.number_of_philos;
		i++;
	}
	i = 0;
	while (i < env->arg.number_of_philos)
	{
		pthread_create(&(philos[i].thr), 0, routine, &(env->philos[i]));
		i++;
	}
}
