/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <sbourziq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:39:55 by sbourziq          #+#    #+#             */
/*   Updated: 2024/09/15 16:43:29 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *phil, pthread_mutex_t *first, pthread_mutex_t *second)
{
	pthread_mutex_lock(first);
	if (locked_print("has taken a fork", phil))
	{
		pthread_mutex_unlock(first);
		return (1);
	}
	pthread_mutex_lock(second);
	if (locked_print("has taken a fork", phil))
	{
		pthread_mutex_unlock(first);
		pthread_mutex_unlock(second);
		return (1);
	}
	return (0);
}

int	eat(t_philo *phil)
{
	pthread_mutex_lock(&phil->my_data->lock);
	phil->start_time = get_current_time();
	if (!phil->my_data->flag)
		printf(FG_GREEN "%zu %d is eating\n" ANSI_COLOR_RESET,
			get_current_time() - phil->start, phil->index);
	pthread_mutex_unlock(&phil->my_data->lock);
	ft_usleep(phil->time_to_eat);
	pthread_mutex_lock(&phil->my_data->lock);
	if (phil->my_data->num_meal != -1)
		phil->meals_eaten++;
	pthread_mutex_unlock(&phil->my_data->lock);
	pthread_mutex_unlock(phil->r_fork);
	pthread_mutex_unlock(phil->l_fork);
	return (check_simulation_end(phil));
}

int	phil_sleep(t_philo *phil)
{
	if (locked_print("is sleeping", phil))
		return (1);
	ft_usleep(phil->time_to_sleep);
	return (check_simulation_end(phil));
}

int	think(t_philo *phil)
{
	return (locked_print("is thinking", phil));
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (validate_arguments(argc) != 0)
		return (1);
	if (ft_parsing(&data, argv) != 0)
		return (1);
	if (allocate_memory(&data) != 0)
		return (1);
	if (initialize_simulation(&data) != 0)
		return (1);
	if (create_and_monitor_philosophers(&data) != 0)
		return (1);
	cleanup_resources(&data);
	return (0);
}
