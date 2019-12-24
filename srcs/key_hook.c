/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_hook.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pduhard- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 23:31:49 by pduhard-     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 08:30:59 by pduhard-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_update_boundaries(t_data *data, int keycode)
{
	if (keycode == 0)
	{
		data->col_min -= ft_fabs(data->col_min - data->col_max) / 20.0;
		data->col_max -= ft_fabs(data->col_min - data->col_max) / 20.0;
	}
	else if (keycode == 1)
	{
		data->row_min -= ft_fabs(data->row_min - data->row_max) / 20.0;
		data->row_max -= ft_fabs(data->row_min - data->row_max) / 20.0;
	}
	else if (keycode == 2)
	{
		data->col_min += ft_fabs(data->col_min - data->col_max) / 20.0;
		data->col_max += ft_fabs(data->col_min - data->col_max) / 20.0;
	}
	else if (keycode == 13)
	{
		data->row_min += ft_fabs(data->row_min - data->row_max) / 20.0;
		data->row_max += ft_fabs(data->row_min - data->row_max) / 20.0;
	}
	else
		return (0);
	return (1);
}

int			ft_key_press(int keycode, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (keycode == 53)
	{
		ft_free_data(data);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 18)
		data->color_set_index = 0;
	else if (keycode == 19)
		data->color_set_index = 1;
	else if (keycode == 20)
		data->color_set_index = 2;
	else if (keycode == 69)
		data->iter += 2;
	else if (keycode == 78)
		data->iter -= data->iter - 2 > 1 ? 2 : 0;
	else if (!ft_update_boundaries(data, keycode))
		return (0);
	ft_print_loop_image(param);
	return (1);
}
