/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <sbourziq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:39:48 by sbourziq          #+#    #+#             */
/*   Updated: 2024/09/15 16:45:28 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		;
	return (0);
}

int	locked_print(char *msg, t_philo *phil)
{
	pthread_mutex_lock(&phil->my_data->lock);
	if (phil->my_data->flag == 1)
	{
		pthread_mutex_unlock(&phil->my_data->lock);
		return (1);
	}
	printf("%zu %d %s\n", get_current_time() - phil->start, phil->index, msg);
	pthread_mutex_unlock(&phil->my_data->lock);
	return (0);
}

int	create_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&data->philo[i].th1, NULL, &routine,
				&data->philo[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

void	join_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_join(philo[i].th1, NULL) != 0)
		{
			write(2, "Failed joining thread\n", 22);
			break ;
		}
		i++;
	}
}
