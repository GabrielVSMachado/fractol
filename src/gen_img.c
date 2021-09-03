/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:02:04 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/09/03 18:00:09 by gvitor-s         ###   ########.fr       */
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
		fractol->z.re = fractol->offset_x
			+ (((double)x_axis / WIDTH) * (4) * fractol->zoom);
		fractol->z.im = fractol->offset_y
			+ (((double)y_axis / HEIGHT) * (4) * fractol->zoom);
		n_iter = fractol->iter(fractol->z, fractol->c);
		my_mlx_put_pixel(&fractol->img, x_axis, y_axis,
			255 - (int)(n_iter * 255 / MAX_ITER));
		pixel++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img.img,
		0, 0);
}

static void	my_mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_p_pix / 8));
	*(unsigned int *)dst = color;
}
