#include <math.h>
#include <stdio.h>
#include "solution.h"

double check_range(double angle)
{
	double x=99;
	if(angle>-PI &&angle<PI)
	{
		return angle;
	}
	else
	{
		return x;
	}
}

double calcDeviation(double old_angle, double new_angle)
{
	double deviation=0;
	
	if(old_angle!=0 && new_angle!=0)
	{
		if(new_angle/fabs(new_angle)==old_angle/fabs(old_angle))
		{
			deviation= fabs(new_angle)-fabs(old_angle);
		}
		else
		{
			deviation= fabs(new_angle)+fabs(old_angle);
		}
	}
	else
	{
		deviation = fabs (old_angle) + fabs(new_angle);
	}	
	
	return deviation;
}

double calc_base_to_end_deviation()
{
	
	
}

