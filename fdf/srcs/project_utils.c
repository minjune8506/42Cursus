#include "fdf.h"

void	zoom(t_dda *com, t_data **data)
{
	com->x *= (*data)->project->zoom;
	com->y *= (*data)->project->zoom;
	com->x1 *= (*data)->project->zoom;
	com->y1 *= (*data)->project->zoom;
	com->z *= (*data)->project->zoom;
	com->z1 *= (*data)->project->zoom;
}

void	shift(t_data **data, t_dda *com)
{
	com->x += (*data)->project->shift_x;
	com->y += (*data)->project->shift_y;
	com->x1 += (*data)->project->shift_x;
	com->y1 += (*data)->project->shift_y;
}
