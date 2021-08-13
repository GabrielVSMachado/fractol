/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:21:49 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/08/13 18:02:20 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static int	check_complex(char *b);

void	check_input(int argc, char **argv, t_fractol *fractol)
{
	if (!ft_strcmp(argv[1], "mandelbrot"))
		fractol->flag = mandelbrot;
	else if (!ft_strcmp(argv[1], "julia"))
	{
		if (argc < 4)
			error_handler(COMPLEX_ARGUMENTS, NULL);
		fractol->flag = julia;
		if (check_complex(argv[2]))
			error_handler(REAL_PART, NULL);
		fractol->z.real = ft_atod(argv[2]);
		if (!ft_strrchr(argv[3], 'i') && check_complex(argv[3]))
			error_handler(IMAGINARY_PART, NULL);
		if (*argv[3] == 'i' || (*argv[3] == '-' && *(argv[3] + 1) == 'i'))
			fractol->z.imaginary = *argv[3] == 'i'
				&& (*argv[3] == '-' && *(argv[3] + 1) == 'i') * (-1);
		else
			fractol->z.imaginary = ft_atod(argv[3]);
	}
	else
		error_handler(AVAILABLE_SETS, NULL);
}

static int	check_complex(char *part)
{
	if (*part == '-' || *part == '+')
		part++;
	while (*part)
	{
		if ((!('0' <= *part && *part <= '9') && *part != '.')
			|| (*part == 'i' && *(part + 1) != '\0'))
			return (ERROR);
		part++;
	}
	return (OK);
}
