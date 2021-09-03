/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 08:20:16 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/09/02 19:59:44 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	if (argc == 1)
		error_handler(AVAILABLE_SETS, NULL);
	ft_bzero(&fractol, sizeof(t_fractol));
	fractol.zoom = 1.0;
	fractol.offset_x = REAL_INIT;
	fractol.offset_y = IMG_INIT;
	check_input(argc, argv, &fractol);
	if (fractol.flag == mandelbrot)
		fractol.iter = iteration_mandelbrot;
	init_mlx(&fractol);
	return (EXIT_SUCCESS);
}
