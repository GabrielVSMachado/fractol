/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:40:55 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/09/01 15:34:44 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		error_handler(MLX_NULL, &fractol);
	fractol->mlx_win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "");
	if (!fractol->mlx_win)
		error_handler(MLX_WIN_NULL, &fractol);
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img.img)
		error_handler(MLX_IMG_NULL, &fractol);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_p_pix, &fractol->img.line_lenght,
			&fractol->img.endian);
	calc_colors(fractol->colors, fractol->max_iter);
	init_hooks(fractol);
	gen_img(fractol);
	mlx_loop(fractol->mlx);
}
