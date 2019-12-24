/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   complex.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pduhard- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 21:32:46 by pduhard-     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 23:43:16 by pduhard-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

double		ft_complex_module(t_complex a)
{
	return (sqrtf(a.real * a.real + a.imag * a.imag));
}

t_complex	ft_complex_add(t_complex a, t_complex b)
{
	t_complex c;

	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return (c);
}

t_complex	ft_complex_mult(t_complex a, t_complex b)
{
	t_complex c;

	c.real = a.real * b.real - a.imag * b.imag;
	c.imag = a.real * b.imag + a.imag * b.real;
	return (c);
}
