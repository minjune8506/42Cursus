#include "./minilibx_macos/mlx.h"

int	main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 280, 162, "test");
	mlx_loop(mlx_ptr);
}