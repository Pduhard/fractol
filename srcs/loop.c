/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   loop.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pduhard- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 23:22:59 by pduhard-     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 07:50:07 by pduhard-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		ft_print_loop_image(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->img_ptr);
	data->mlx->img_ptr = mlx_new_image(data->mlx->mlx_ptr,
		WIN_WIDTH, WIN_HEIGHT);
	data->mlx->img_str = (int *)mlx_get_data_addr(data->mlx->img_ptr,
		&(data->mlx->bpp), &(data->mlx->s_l), &(data->mlx->endian));
	data->fractal_fct(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->mlx->img_ptr, 0, 0);
	return (1);
}
