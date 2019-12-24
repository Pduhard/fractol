/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pduhard- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 18:46:02 by pduhard-     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 08:04:15 by pduhard-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (ft_printf("Usage: ./fractol <fractal_name>\n"));
	if (!(data = ft_init_data(argv[1])))
		return (0);
	mlx_hook(data->mlx->win_ptr, 2, 303, &ft_key_press, (void *)data);
	mlx_hook(data->mlx->win_ptr, 4, 303, &ft_mouse_hook, (void *)data);
	mlx_hook(data->mlx->win_ptr, 5, 303, &ft_mouse_hook, (void *)data);
	mlx_hook(data->mlx->win_ptr, 6, 303, &ft_moov_hook, (void *)data);
	data->fractal_fct(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr,
		data->mlx->win_ptr, data->mlx->img_ptr, 0, 0);
	mlx_loop(data->mlx->mlx_ptr);
	return (0);
}
