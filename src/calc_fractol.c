/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:27:33 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/08/27 17:37:19 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static double	complex_abs(t_complex z);

int	iteration_mandelbrot(t_complex c, t_complex z)
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
	return (n_iter);
}

static double	complex_abs(t_complex z)
{
	return (pow(z.re, 2) + pow(z.im, 2));
}
