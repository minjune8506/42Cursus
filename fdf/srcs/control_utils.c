#include "fdf.h"
#include "mlx.h"

int
	control_x(int keycode, t_data **data)
{
	if (keycode == NUM1)
		(*data)->project->alpha -= 0.1;
	if (keycode == NUM2)
		(*data)->project->alpha += 0.1;
	return (1);
}

int
	control_y(int keycode, t_data **data)
{
	if (keycode == NUM3)
		(*data)->project->beta -= 0.1;
	if (keycode == NUM4)
		(*data)->project->beta += 0.1;
	return (1);
}

int
	control_z(int keycode, t_data **data)
{
	if (keycode == NUM5)
		(*data)->project->gamma -= 0.1;
	if (keycode == NUM6)
		(*data)->project->gamma += 0.1;
	return (1);
}

int
	control_projection(int keycode, t_data **data)
{
	if (keycode == ISO)
	{
		init(data);
		(*data)->project->iso = 1;
	}
	if (keycode == PARALLEL)
	{
		init(data);
		(*data)->project->iso = 0;
		(*data)->project->shift_x = \
		(*data)->win_width / 2 - (*data)->width * (*data)->project->zoom / 2;
		(*data)->project->shift_y = \
		(*data)->win_height / 2 - (*data)->height * (*data)->project->zoom / 2;
	}
	return (1);
}
