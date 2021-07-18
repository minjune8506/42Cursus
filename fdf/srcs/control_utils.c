#include "fdf.h"
#include "mlx.h"

void
	control_x(int keycode, t_data **data)
{
	mlx_clear_window((*data)->mlx->mlx_ptr, (*data)->mlx->win_ptr);
	if (keycode == NUM1)
		(*data)->project->alpha -= 0.1;
	if (keycode == NUM2)
		(*data)->project->alpha += 0.1;
	draw(data);
}

void
	control_y(int keycode, t_data **data)
{
	mlx_clear_window((*data)->mlx->mlx_ptr, (*data)->mlx->win_ptr);
	if (keycode == NUM3)
		(*data)->project->beta -= 0.1;
	if (keycode == NUM4)
		(*data)->project->beta += 0.1;
	draw(data);
}

void
	control_z(int keycode, t_data **data)
{
	mlx_clear_window((*data)->mlx->mlx_ptr, (*data)->mlx->win_ptr);
	if (keycode == NUM5)
		(*data)->project->gamma -= 0.1;
	if (keycode == NUM6)
		(*data)->project->gamma += 0.1;
	draw(data);
}

void
	control_projection(int keycode, t_data **data)
{
	mlx_clear_window((*data)->mlx->mlx_ptr, (*data)->mlx->win_ptr);
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
	draw(data);
}
