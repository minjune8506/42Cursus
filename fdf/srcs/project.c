#include "fdf.h"
#include <math.h>

static void
	rotate_x(t_dda *com, float alpha)
{
	float	pre_y;
	float	pre_y1;

	pre_y = com->y;
	pre_y1 = com->y1;
	com->y = cos(alpha) * pre_y - sin(alpha) * com->z;
	com->y1 = cos(alpha) * pre_y1 - sin(alpha) * com->z1;
	com->z = sin(alpha) * pre_y + cos(alpha) * com->z;
	com->z1 = sin(alpha) * pre_y1 + cos(alpha) * com->z1;
}

static void
	rotate_y(t_dda *com, float beta)
{
	float	pre_x;
	float	pre_x1;

	pre_x = com->x;
	pre_x1 = com->x1;
	com->x = pre_x * cos(beta) + com->z * sin(beta);
	com->z = -pre_x * sin(beta) + com->z * cos(beta);
	com->x1 = pre_x1 * cos(beta) + com->z1 * sin(beta);
	com->z1 = -pre_x1 * sin(beta) + com->z1 * cos(beta);
}

static void
	rotate_z(t_dda *com, float gamma)
{
	float	pre_x;
	float	pre_x1;

	pre_x = com->x;
	pre_x1 = com->x1;
	com->x = pre_x * cos(gamma) - com->y * sin(gamma);
	com->y = pre_x * sin(gamma) + com->y * cos(gamma);
	com->x1 = pre_x1 * cos(gamma) - com->y1 * sin(gamma);
	com->y1 = pre_x1 * sin(gamma) + com->y1 * cos(gamma);
}

void
	projection(t_point point, t_data **data, t_dda *com)
{
	init_dda(point, com);
	get_data(data, com);
	zoom(com, data);
	rotate_x(com, (*data)->project->alpha);
	rotate_y(com, (*data)->project->beta);
	rotate_z(com, (*data)->project->gamma);
	if ((*data)->project->iso)
	{
		isometric(&com->x, &com->y, com->z);
		isometric(&com->x1, &com->y1, com->z1);
	}
	shift(data, com);
}
