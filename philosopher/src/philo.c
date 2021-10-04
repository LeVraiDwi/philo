#include "philosopher.h"

void	ft_write(t_philosophe *philo, char *str)
{
	pthread_mutex_lock(&philo->setting->write);
	if (!philo->setting->end)
		printf("%.4ld %d %s\n", gettimestamp(philo->setting->start), philo->name, str);
	pthread_mutex_unlock(&philo->setting->write);
}

int	ft_taking_fork(t_philosophe *philo)
{
	pthread_mutex_lock(&philo->fork[0]->mutex);
	ft_write(philo, FORK);
	pthread_mutex_lock(&philo->fork[1]->mutex);
	ft_write(philo, FORK);
	return (1);
}

int	ft_sleeping(t_philosophe *philo)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	ft_write(philo, SLEEP);
	while (gettimestamp(start) < philo->setting->time[3] && !philo->setting->end)
	{
		usleep(1000);
	}
	return (1);
}

int	ft_eating(t_philosophe *philo)
{
	struct timeval	start;

	if (!philo->setting->end)
	{
		gettimeofday(&start, NULL);
		gettimeofday(&philo->alive, NULL);
		philo->eat_time++;
		ft_write(philo, EAT);
		while ((gettimestamp(start)) < philo->setting->time[2] && !philo->setting->end)
		{
			usleep(1000);
		}
	}
	pthread_mutex_unlock(&philo->fork[0]->mutex);
	pthread_mutex_unlock(&philo->fork[1]->mutex);
	return (1);
}

void	*ft_philo(void *data)
{
	int				i;
	t_philosophe 	*philo;
	t_setting		*setting;

	i = 0;
	philo = (t_philosophe *)data;
	gettimeofday(&philo->alive, NULL);
	setting = philo->setting;
	while (!setting->end)
	{
		ft_taking_fork(philo);
		ft_eating(philo);
		ft_sleeping(philo);
		ft_write(philo, THINK);
		i++;
	}
	return(0);
}
