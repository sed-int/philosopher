/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:19:44 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/20 16:12:52 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_env(t_env *env, t_arg arg)
{
	int	i;

	env->philo = malloc(sizeof(t_philo) * arg.number);
	env->fork = malloc(sizeof(int) * arg.number);
	env->mutex = malloc(sizeof(pthread_mutex_t) * arg.number);
	i = -1;
	while (++i < arg.number)
		pthread_mutex_init(env->mutex + i, NULL);
	if (!env->philo || !env->fork)
		exit(1);
}

t_arg	init_arg(char **av)
{
	t_arg	arg;

	arg.number_of_philo = ft_atoi(av[1]);
	arg.time_to_die = ft_atoi(av[2]);
	arg.time_to_eat = ft_atoi(av[3]);
	arg.time_to_sleep = ft_atoi(av[4]);
	arg.must_eat_count = 1;
	if (av[5] != NULL)
		arg.must_eat_count = ft_atoi(av[5]);
	return (arg);
}

void	philo(char	**av)
{
	t_arg	arg;
	t_env	env;

	arg = init_arg(av);
	init_env(&env, arg);
}
