/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_hook.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pduhard- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 23:20:33 by pduhard-     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 08:12:10 by pduhard-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

double	ft_m_calc(double min, double max, int mult, int divid)
{
	return (ft_fabs(min - max) / 10 * (double)mult / (double)divid);
}

int		ft_mouse_hook(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (button == 1)
		data->mouse_lock = (data->mouse_lock + 1) % 3;
	else if (button == 5)
	{
		data->row_min -= ft_m_calc(data->row_min, data->row_max, y, WIN_HEIGHT);
		data->row_max += ft_m_calc(data->row_min, data->row_max,
			WIN_HEIGHT - y, WIN_HEIGHT);
		data->col_min += ft_m_calc(data->col_min, data->col_max, x, WIN_WIDTH);
		data->col_max -= ft_m_calc(data->col_min, data->col_max,
				WIN_WIDTH - x, WIN_WIDTH);
	}
	else if (button == 4)
	{
		data->row_min += ft_m_calc(data->row_min, data->row_max, y, WIN_HEIGHT);
		data->row_max -= ft_m_calc(data->row_min, data->row_max,
				WIN_HEIGHT - y, WIN_HEIGHT);
		data->col_min -= ft_m_calc(data->col_min, data->col_max, x, WIN_WIDTH);
		data->col_max += ft_m_calc(data->col_min, data->col_max,
				WIN_WIDTH - x, WIN_WIDTH);
	}
	ft_print_loop_image(param);
	return (1);
}

int		ft_moov_hook(int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (ft_abs(data->mouse_x - x) + ft_abs(data->mouse_y - y)
		> JULIA_SENSI && !data->mouse_lock)
	{
		data->mouse_x = x;
		if (data->mouse_x < 0)
			data->mouse_x = 0;
		else if (data->mouse_x > WIN_WIDTH)
			data->mouse_x = WIN_WIDTH;
		data->mouse_y = y;
		if (data->mouse_y < 0)
			data->mouse_y = 0;
		else if (data->mouse_y > WIN_HEIGHT)
			data->mouse_y = WIN_HEIGHT;
		ft_print_loop_image((t_data*)param);
	}
	return (1);
}
