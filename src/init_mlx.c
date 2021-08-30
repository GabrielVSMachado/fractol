/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:40:55 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/08/30 12:50:00 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->mlx_win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "");
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_p_pix, &fractol->img.line_lenght,
			&fractol->img.endian);
	gen_img(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img.img,
		0, 0);
	init_hooks(fractol);
	mlx_loop(fractol->mlx);
}
