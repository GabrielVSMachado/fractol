/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:02:04 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/09/08 15:24:11 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_mlx_put_pixel(t_data *data, int x, int y, unsigned int n_iter);

void	gen_img(t_fractol *fractol)
{
	unsigned int		x_axis;
	unsigned int		y_axis;
	unsigned int		n_iter;
	unsigned int		pixel;

	pixel = 0;
	while (pixel != WIDTH * HEIGHT)
	{
		x_axis = pixel % WIDTH;
		y_axis = pixel / WIDTH;
		fractol->z.re = fractol->offset_x
			+ (((double)x_axis / WIDTH) * (REAL_DISTANCE) * fractol->zoom);
		fractol->z.im = fractol->offset_y
			+ (((double)y_axis / HEIGHT) * (IMG_DISTANCE) * fractol->zoom);
		n_iter = fractol->iter(fractol->z, fractol->c);
		my_mlx_put_pixel(&fractol->img, x_axis, y_axis, n_iter);
		pixel++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img.img,
		0, 0);
}

static void	my_mlx_put_pixel(t_data *data, int x, int y, unsigned int n_iter)
{
	char			*dst;
	unsigned int	*color;
	int				factor;

	dst = data->addr + ((y * data->line_lenght)
			+ (x << (data->bits_p_pix >> 4)));
	color = (unsigned int *)dst;
	if (n_iter == MAX_ITER)
		*color = 0xFF000000;
	else
	{
		factor = (int)(255 * n_iter / MAX_ITER);
		*color = 0xFF << 24;
		*color |= (int)pow(factor, 1.5) << 8;
		*color |= (255 - factor) << 16;
	}
}
