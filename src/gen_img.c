/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:02:04 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/09/09 19:15:14 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_mlx_put_pixel(t_fractol *data, int x, int y, int n_iter);

int	gen_img(t_fractol *fractol)
{
	unsigned int		x_axis;
	unsigned int		y_axis;
	int					n_iter;
	unsigned int		pixel;
	unsigned int		mult_pixel;

	pixel = 0;
	mult_pixel = WIDTH * HEIGHT;
	fractol->scale_x = (DISTANCE) * fractol->zoom;
	fractol->scale_y = (DISTANCE) * fractol->zoom;
	while (pixel != mult_pixel)
	{
		x_axis = pixel % WIDTH;
		y_axis = pixel / WIDTH;
		fractol->z.re = fractol->offset_x
			+ (((double)x_axis / WIDTH) * fractol->scale_x);
		fractol->z.im = fractol->offset_y
			+ (((double)y_axis / HEIGHT) * fractol->scale_y);
		n_iter = fractol->iter(fractol->z, fractol->c, fractol->max_iter);
		my_mlx_put_pixel(fractol, x_axis, y_axis, n_iter);
		pixel++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img.img,
		0, 0);
	return (0);
}

static void	my_mlx_put_pixel(t_fractol *data, int x, int y, int n_iter)
{
	char			*dst;
	unsigned int	*color;
	int				factor;

	dst = data->img.addr + ((y * data->img.line_lenght)
			+ (x << (data->img.bits_p_pix >> 4)));
	color = (unsigned int *)dst;
	if (n_iter == data->max_iter)
		*color = 0xFF000000;
	else
	{
		factor = (int)(255 * n_iter / data->max_iter);
		*color = 0xFF << 24;
		*color |= (int)pow(factor, 1.5) << 8;
		*color |= (255 - factor) << 16;
	}
}
