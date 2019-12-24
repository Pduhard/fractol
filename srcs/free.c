/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pduhard- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/21 08:19:03 by pduhard-     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 08:34:26 by pduhard-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_free_mlx(t_mlx *mlx)
{
	if (!mlx->mlx_ptr || !mlx->img_ptr)
		return ;
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx->img_ptr = NULL;
	if (!mlx->win_ptr)
		return ;
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->win_ptr = NULL;
	free(mlx);
}

void		ft_free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->mlx)
	{
		ft_free_mlx(data->mlx);
		data->mlx = NULL;
	}
	if (data->fractal_param)
	{
		free(data->fractal_param);
		data->fractal_param = NULL;
	}
	free(data);
}
