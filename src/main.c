/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 08:20:16 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/09/11 18:21:29 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_struct(t_fractol *fractol);

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	if (argc == 1)
		error_handler(AVAILABLE_SETS, NULL);
	init_struct(&fractol);
	check_input(argc, argv, &fractol);
	if (fractol.flag == mandelbrot)
		fractol.iter = mandelbrot_set;
	else if (fractol.flag == julia)
		fractol.iter = julia_set;
	else if (fractol.flag == mandelbar)
		fractol.iter = mandelbar_set;
	init_mlx(&fractol, argv[1]);
	return (EXIT_SUCCESS);
}

static void	init_struct(t_fractol *fractol)
{
	ft_bzero(fractol, sizeof(t_fractol));
	fractol->zoom = 1.0;
	fractol->offset_x = REAL_INIT;
	fractol->offset_y = IMG_INIT;
	fractol->max_iter = 80;
}
