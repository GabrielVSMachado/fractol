/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 13:45:52 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/08/30 13:52:28 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx_win, check_key, fractol);
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
