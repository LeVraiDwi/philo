#include "philosopher.h"

long	gettimestamp(struct timeval timeval)
{
	struct timeval time_act;

	gettimeofday(&time_act, NULL);
	return (((time_act.tv_sec - timeval.tv_sec) * 1000000) + ((time_act.tv_usec - timeval.tv_usec)));
}
