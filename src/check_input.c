/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:21:49 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/08/12 20:17:42 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static void	check_complex(char *a, char *b);

void	check_input(int argc, char **argv, t_fractol *fractol)
{
	if (argc == 1)
	{
		printf(AVAILABLE_SETS);
		exit(EXIT_FAILURE);
	}
	if (!ft_strcmp(argv[1], "mandelbrot"))
		fractol->flag = mandelbrot;
	else if (!ft_strcmp(argv[1], "julia"))
	{
		check_complex(argv[2], argv[3]);
		fractol->flag = julia;
		fractol->z.real = ft_atod(argv[2]);
		fractol->z.imaginary = ft_atod(argv[3]);
	}
	else
	{
		printf(AVAILABLE_SETS);
		exit(EXIT_FAILURE);
	}
}

static void	check_complex(char *real_part, char *imaginary_part)
{
	while (*real_part)
	{
		if (!('0' <= *real_part && *real_part <= '9') 
			&& *real_part != '.' 
			&& *real_part != '+'
			&& *real_part != '-')
		{
			printf("%s\n USE ONE OF THIS FORMATS: +0.0 OR -0.0", ERROR_IN_REAL_PART);
			exit(EXIT_FAILURE);
		}
		real_part++;
	}
	while (*imaginary_part)
	{
		if (!('0' <= *real_part && *real_part <= '9') 
			&& *real_part != '.' 
			&& *real_part != '+'
			&& *real_part != '-')
		{
			printf("%s\n USE ONE OF THIS FORMATS: +0.0i OR -0.0i\n", ERROR_IN_IMG_PART);
			exit(EXIT_FAILURE);
		}
		imaginary_part++;
	}
}
