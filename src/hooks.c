/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 13:45:52 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/09/11 18:43:59 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx_win, check_key, fractol);
	mlx_mouse_hook(fractol->mlx_win, get_zoom, fractol);
	mlx_expose_hook(fractol->mlx_win, gen_img, fractol);
	if (fractol->flag == julia)
		mlx_hook(fractol->mlx_win, MOTION_NOTIFY, 1L << 6,
			motion_mouse, fractol);
}

int	check_key(int key, t_fractol *fractol)
{
	if (key == ESCAPE)
	{
		mlx_destroy_image(fractol->mlx, fractol->img.img);
		mlx_destroy_window(fractol->mlx, fractol->mlx_win);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		exit(EXIT_SUCCESS);
	}
	else if (key == UP || key == 'w')
		fractol->offset_y += 0.009L;
	else if (key == RIGHT || key == 'd')
		fractol->offset_x -= 0.009L;
	else if (key == DOWN || key == 's')
		fractol->offset_y -= 0.009L;
	else if (key == LEFT || key == 'a')
		fractol->offset_x += 0.009L;
	else if (key == 'm')
		fractol->motion_mouse = !fractol->motion_mouse;
	gen_img(fractol);
	return (0);
}

int	get_zoom(int key, int x, int y, t_fractol *fractol)
{
	double	bef;
	double	result;

	bef = (fractol->zoom);
	if (key == MWHEEL_UP)
	{
		fractol->zoom *= 0.94;
		if (fractol->max_iter < 498)
			fractol->max_iter += 2;
	}
	else if (key == MWHEEL_DOWN)
	{
		fractol->zoom *= 1.1;
		if (fractol->max_iter != 80)
			fractol->max_iter -= 2;
		if (fractol->zoom > 1)
			fractol->zoom = 1;
	}
	result = (DISTANCE * (fractol->zoom - bef));
	fractol->offset_x -= ((double)x / WIDTH) * result;
	fractol->offset_y -= ((double)y / HEIGHT) * result;
	calc_colors(fractol->colors, fractol->max_iter);
	gen_img(fractol);
	return (0);
}

int	motion_mouse(int x, int y, t_fractol *fractol)
{
	if (fractol->motion_mouse)
	{
		fractol->c.re = fractol->offset_x + ((double)x / WIDTH)
			* (4) * fractol->zoom;
		fractol->c.im = fractol->offset_y + ((double)y / HEIGHT)
			* (4) * fractol->zoom;
		gen_img(fractol);
	}
	return (0);
}
