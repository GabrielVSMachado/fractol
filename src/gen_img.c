/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:02:04 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/08/27 18:05:32 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static void	my_mlx_put_pixel(t_data *data, int x, int y, int color);

void	gen_img(t_fractol *fractol)
{
	int		x_axis;
	int		y_axis;
	int		n_iter;
	int		pixel;

	pixel = 0;
	while (pixel != WIDTH * HEIGHT)
	{
		x_axis = pixel % WIDTH;
		y_axis = pixel / WIDTH;
		fractol->z.re = REAL_INIT + ((double)x_axis / WIDTH) * REAL_DISTANCE;
		fractol->z.im = IMG_INIT + ((double)y_axis / HEIGHT) * IMG_DISTANCE;
		n_iter = fractol->iter(fractol->z, fractol->c);
		my_mlx_put_pixel(&fractol->img, x_axis, y_axis,
			500 - (n_iter * 500 / MAX_ITER));
		pixel++;
	}
}

static void	my_mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_p_pix / 8));
	*(unsigned int *)dst = color;
}
