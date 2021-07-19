#include "./minilibx_macos/mlx.h"
#include <stdlib.h>

typedef struct s_mlx
{
    void    *mlx_ptr;
    void    *win_ptr;
}t_mlx;

int     main(void)
{
    t_mlx *mlx;

    mlx = (t_mlx *)malloc(sizeof(t_mlx));
    system("leaks a.out > result; cat result; rm result");
    mlx->mlx_ptr = mlx_init();
    system("leaks a.out > result; cat result; rm result");
    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1000, 800, "test");
    system("leaks a.out > result; cat result; rm result");
    mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
    system("leaks a.out > result; cat result; rm result");
    mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
    system("leaks a.out > result; cat result; rm result");
    free(mlx->mlx_ptr); // <-
    system("leaks a.out > result; cat result; rm result");
    free(mlx); // <-
    system("leaks a.out > result; cat result; rm result");
}