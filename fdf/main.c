#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello Word!");
	mlx_loop(mlx);
}
