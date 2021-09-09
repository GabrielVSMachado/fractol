/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 13:45:52 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/09/09 19:39:36 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx_win, check_key, fractol);
	mlx_mouse_hook(fractol->mlx_win, get_zoom, fractol);
	mlx_expose_hook(fractol->mlx_win, gen_img, fractol);
}

int	check_key(int key, t_fractol *fractol)
{
	if (key == XK_Escape)
	{
		mlx_destroy_image(fractol->mlx, fractol->img.img);
		mlx_destroy_window(fractol->mlx, fractol->mlx_win);
		mlx_destroy_display(fractol->mlx);
		exit(EXIT_SUCCESS);
	}
	return (NO_VALID_KEY);
}

int	get_zoom(int key, int x, int y, t_fractol *fractol)
{
	double	bef;
	double	result;

	bef = (fractol->zoom);
	if (key == MWHEEL_UP)
	{
		fractol->zoom *= 0.94f;
		fractol->max_iter += 2;
	}
	else if (key == MWHEEL_DOWN)
	{
		fractol->zoom *= 1.1f;
		fractol->max_iter -= 2;
	}
	if (fractol->zoom > 1.0f)
	{
		fractol->max_iter = 80;
		fractol->zoom = 1;
	}
	result = (DISTANCE * (fractol->zoom - bef));
	fractol->offset_x -= ((double)x / WIDTH) * result;
	fractol->offset_y -= ((double)y / HEIGHT) * result;
	gen_img(fractol);
	return (0);
}
