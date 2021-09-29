#include "philosopher.h"

int	lunch_time(t_setting *setting, t_philosophe **philo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if(gettimeofday(&setting->start, NULL) == -1)
		return (0);
	setting->death = 0;
	while (i < philo[0]->setting->time[0])
	{
		if (pthread_create(&philo[i]->thread, 0, ft_philo, (void *)philo[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < 0)
	{
		if (pthread_join(philo[i]->thread, (void *)&j))
			return (0);
		if (j == -1)
			setting->death = 1;
		i++;
	}
	return (1);
}
