/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:21:49 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/08/13 14:00:02 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static void	check_complex(char *a, char *b);

void	check_input(int argc, char **argv, t_fractol *fractol)
{
	if (!ft_strcmp(argv[1], "mandelbrot"))
		fractol->flag = mandelbrot;
	else if (!ft_strcmp(argv[1], "julia"))
	{
		if (argc < 4)
			error_handler(COMPLEX_ARGUMENTS, NULL);
		check_complex(argv[2], argv[3]);
		fractol->flag = julia;
		fractol->z.real = ft_atod(argv[2]);
		fractol->z.imaginary = ft_atod(argv[3]);
	}
	else
		error_handler(AVAILABLE_SETS, NULL);
}

static void	check_complex(char *real_part, char *imaginary_part)
{
	while (*real_part)
	{
		if (!('0' <= *real_part && *real_part <= '9') 
			&& *real_part != '.' 
			&& *real_part != '+'
			&& *real_part != '-')
			error_handler(REAL_PART, NULL);
		real_part++;
	}
	while (*imaginary_part)
	{
		if (!('0' <= *imaginary_part && *imaginary_part <= '9') 
			&& *imaginary_part != '.' 
			&& *imaginary_part != '+'
			&& *imaginary_part != '-'
			&& *imaginary_part != 'i')
			error_handler(IMAGINARY_PART, NULL);
		imaginary_part++;
	}
}
