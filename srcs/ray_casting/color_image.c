#include "../../includes/cub3D.h"

void    color_line(t_mlx *mlx, int x, int y, int distance)
{
    int *adr;
    int i;
    
    (void)y;
    i = 0;
    while (i < distance)
    {
        adr = (int *)(mlx->addr + (x * mlx->size_line + i * (mlx->bpp / 8)));
        *adr = 1 << 15;
        i++;
    }
}