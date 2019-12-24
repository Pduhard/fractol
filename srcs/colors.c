/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   colors.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pduhard- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 21:02:57 by pduhard-     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 07:48:57 by pduhard-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		ft_set_color_1(int color_set[COLOR_SET_SIZE])
{
	color_set[0] = 0x75f5fd;
	color_set[1] = 0x75f5fd;
	color_set[2] = 0xb76cfd;
	color_set[3] = 0xb76cfd;
	color_set[4] = 0xff2281;
	color_set[5] = 0xff2281;
	color_set[6] = 0x011ffd;
	color_set[7] = 0x011ffd;
	color_set[8] = 0x75f5fd;
	color_set[9] = 0xff2281;
}

void		ft_set_color_2(int color_set[COLOR_SET_SIZE])
{
	color_set[0] = 0x000000;
	color_set[1] = 0x181818;
	color_set[2] = 0x323232;
	color_set[3] = 0x4b4b4b;
	color_set[4] = 0x626262;
	color_set[5] = 0x7a7a7a;
	color_set[6] = 0x939393;
	color_set[7] = 0xababab;
	color_set[8] = 0xb3b3b3;
	color_set[9] = 0xcbcbcb;
}

void		ft_set_color_3(int color_set[COLOR_SET_SIZE])
{
	color_set[0] = 0xff000f;
	color_set[1] = 0xee11e1;
	color_set[2] = 0xdd222d;
	color_set[3] = 0xcc33c3;
	color_set[4] = 0xbb444b;
	color_set[5] = 0xaa55a5;
	color_set[6] = 0x996669;
	color_set[7] = 0x887787;
	color_set[8] = 0x778887;
	color_set[9] = 0x669969;
}

void		ft_get_colors_set(int color_set[COLOR_SET_NBR][COLOR_SET_SIZE])
{
	ft_set_color_1(color_set[0]);
	ft_set_color_2(color_set[1]);
	ft_set_color_3(color_set[2]);
}
