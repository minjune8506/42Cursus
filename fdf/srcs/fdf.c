#include "fdf.h"
#include "mlx.h"

void
	mlx(t_data **data)
{
	// void	*mlx_ptr;
	// void	*win_ptr;
	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, (*data)->win_width, (*data)->win_height, "fdf");
	(*data)->mlx->mlx_ptr = mlx_init();
	(*data)->mlx->win_ptr = mlx_new_window((*data)->mlx->mlx_ptr, \
	(*data)->win_width, (*data)->win_height, "fdf");
	draw(data);
	mlx_key_hook((*data)->mlx->win_ptr, key_control, data);
	mlx_loop((*data)->mlx->mlx_ptr);
}

int
	main(int ac, char **av)
{
	t_data	*data;
	char	*map_name;

	if (ac != 2)
		print_error("Usage : ./fdf <filename> [ case_size z_size ]");
	else
	{
		data = (t_data *)malloc(sizeof(t_data));
		data->mlx = (t_mlx *)malloc(sizeof(t_mlx));
		data->project = (t_projection *)malloc(sizeof(t_projection));
		map_name = av[1];
		read_map(map_name, &data);
		init(&data);
		mlx(&data);
		free_int(data->z_value, data->height);
		free_uint(data->color, data->height);
		free(data->mlx);
		free(data->project);
		free(data);
		// while(1);
	}
	return (0);
}
