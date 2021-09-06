/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 13:45:52 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/09/06 14:29:59 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx_win, check_key, fractol);
	mlx_mouse_hook(fractol->mlx_win, get_zoom, fractol);
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
	double	bef_x;
	double	bef_y;
	double	aft_x;
	double	aft_y;

	bef_x = (REAL_DISTANCE) * (fractol->zoom);
	bef_y = (IMG_DISTANCE) * (fractol->zoom);
	if (key == MWHEEL_UP)
		fractol->zoom *= 0.9f;
	else if (key == MWHEEL_DOWN)
		fractol->zoom *= 1.1f;
	if (fractol->zoom > 1.0f)
		fractol->zoom = 1;
	aft_x = (REAL_DISTANCE) * (fractol->zoom);
	aft_y = (IMG_DISTANCE) * (fractol->zoom);
	fractol->offset_x -= ((double)x / WIDTH) * (aft_x - bef_x);
	fractol->offset_y -= ((double)y / HEIGHT) * (aft_y - bef_y);
	gen_img(fractol);
	return (0);
}
