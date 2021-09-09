/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:15:30 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/09/08 21:57:38 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	complex_abs(t_complex z);

int	mandelbrot_set(t_complex c, t_complex z)
{
	double		tmp;
	int			n_iter;

	n_iter = 0;
	while (complex_abs(z) <= 4 && n_iter < MAX_ITER)
	{
		tmp = pow(z.re, 2) - pow(z.im, 2);
		z.im = (2 * z.im * z.re) + c.im;
		z.re = tmp + c.re;
		n_iter++;
	}
	if (n_iter == MAX_ITER)
		return (MAX_ITER);
	return (n_iter + 1 - log(log2(complex_abs(z))));
}

int	julia_set(t_complex z, t_complex c)
{
	double	tmp;
	int		n_iter;

	n_iter = 0;
	while (complex_abs(z) <= 4 && n_iter < MAX_ITER)
	{
		tmp = pow(z.re, 2) - pow(z.im, 2);
		z.im = (2 * z.im * z.re) + c.im;
		z.re = tmp + c.re;
		n_iter++;
	}
	if (n_iter == MAX_ITER)
		return (MAX_ITER);
	return (n_iter + 1 - log(log2(complex_abs(z))));
}

static double	complex_abs(t_complex z)
{
	return (pow(z.re, 2) + pow(z.im, 2));
}
