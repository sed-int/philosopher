/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunminjo <hyunminjo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:19:44 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/21 20:19:34 by hyunminjo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_env(t_env *env, char **av)
{
	int	i;

	env->arg.number_of_philos = ft_atoi(av[1]);
	env->arg.time_to_die = ft_atoi(av[2]);
	env->arg.time_to_eat = ft_atoi(av[3]);
	env->arg.time_to_sleep = ft_atoi(av[4]);
	env->arg.must_eat_count = 1;
	if (av[5] != NULL)
		env->arg.must_eat_count = ft_atoi(av[5]);
	env->philos = malloc(sizeof(t_philo) * env->arg.number_of_philos);
	env->forks = malloc(sizeof(char) * env->arg.number_of_philos);
	env->mutex = malloc(sizeof(pthread_mutex_t) * env->arg.number_of_philos);
	env->is_dead = -1;
	i = -1;
	while (++i < env->arg.number_of_philos)
		pthread_mutex_init(env->mutex + i, NULL);
	if (!env->philos || !env->forks)
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
	{
		pthread_create(&philos[i].thr, 0, routine, (void *)&env->philos[i]);
		i++;
	}
}

void	philo(char	**av)
{
	t_env	env;
	int		i;

	init_env(&env, av);
	i = 0;
	while (i < env.arg.number_of_philos)
		init_philo(&env, &env.philos[i++]);
}
