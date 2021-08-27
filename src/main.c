/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 08:20:16 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/08/27 17:50:07 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	if (argc == 1)
		error_handler(AVAILABLE_SETS, NULL);
	bzero(&fractol, sizeof(t_fractol));
	check_input(argc, argv, &fractol);
	if (fractol.flag == mandelbrot)
		fractol.iter = iteration_mandelbrot;
	init_mlx(&fractol);
	return (EXIT_SUCCESS);
}
