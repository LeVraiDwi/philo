#include "philosopher.h"

void	ft_write(t_philosophe *philo, char *str)
{
	pthread_mutex_lock(philo->setting->write);
	printf("%d %d %s\n", gettimestamp(philo->setting->start) / 1000, philo->name, str);
	pthread_mutex_unlock(philo->setting->write);
}

int	ft_taking_fork(t_philosophe *philo)
{
	pthread_mutex_lock(philo->fork[0]->mutex);
	ft_write(philo, FORK);
	pthread_mutex_lock(philo->fork[1]->mutex);
	ft_write(philo, FORK);
}

int	ft_eating(t_philosophe *philo)
{
	struct timeval	start;

	if (!philo->setting->death)
	{
		ft_write(philo, EATING);
		start = gettimeofday(&timeval);
		while (gettimestamp(timeval) < philo->setting->time[2] && philo->setting->death)
		{
			usleep(1000);
		}
	}
	pthread_mutex_unlock(philo->fork[0]->mutex);
	pthread_mutex_unlock(philo->fork[1]->mutex);
	return (1)
}

int	ft_philo(void *data)
{
	int				i;
	t_philosophe 	*philo
	t_setting		*setting;

	i = 0;
	gettimeofday(&philo->alive);
	philo = (t_philosophe *)data;
	setting = philo->setting;
	while (!setting->death && i != setting->time[4])
	{
		ft_taking_fork(philo);
		ft_eating(philo);
		i++;
	}
	return(1);
}
