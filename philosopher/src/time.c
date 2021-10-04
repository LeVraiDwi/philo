#include "philosopher.h"

long	gettimestamp(struct timeval timeval)
{
	struct timeval	time_act;
	long int		time;

	gettimeofday(&time_act, NULL);
	time = ((time_act.tv_sec - timeval.tv_sec) * 1000) + ((time_act.tv_usec - timeval.tv_usec)/1000);
	return (time);
}
