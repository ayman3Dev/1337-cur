#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	void *mlx;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_destroy_display(mlx);
	free(mlx);
	return 0;
}