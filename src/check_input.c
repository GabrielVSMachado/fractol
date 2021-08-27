/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:21:49 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/08/27 18:16:29 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_imaginary(char *b);
static int	check_real(char *b);

void	check_input(int argc, char **argv, t_fractol *fractol)
{
	if (!ft_strcmp(argv[1], "mandelbrot"))
		fractol->flag = mandelbrot;
	else if (!ft_strcmp(argv[1], "julia"))
	{
		if (argc < 4)
			error_handler(COMPLEX_ARGUMENTS, NULL);
		fractol->flag = julia;
		if (check_real(argv[2]))
			error_handler(REAL_PART, NULL);
		fractol->c.re = ft_atod(argv[2]);
		if (!ft_strrchr(argv[3], 'i') || check_imaginary(argv[3]))
			error_handler(IMAGINARY_PART, NULL);
		if (*argv[3] == 'i' || (*argv[3] == '-' && *(argv[3] + 1) == 'i'))
			fractol->c.im = (*argv[3] == 'i') + ((*argv[3] == '-'
						&& *(argv[3] + 1) == 'i') * (-1.0));
		else
			fractol->c.im = ft_atod(argv[3]);
	}
	else
		error_handler(AVAILABLE_SETS, NULL);
}

static int	check_imaginary(char *part)
{
	if (*part == '-' || *part == '+')
		part++;
	else
		return (ERROR);
	while (*part && *part != 'i')
	{
		if ((!ft_isdigit(*part) && *part != '.')
			|| (*part == '.' && !ft_isdigit(*(part + 1)))
			|| (*part == '.' && !ft_isdigit(*(part - 1))))
			return (ERROR);
		part++;
	}
	if (*part == 'i' && *(part + 1) != '\0')
		return (ERROR);
	return (OK);
}

static int	check_real(char *part)
{
	if (*part == '-' || *part == '+')
		part++;
	while (*part)
	{
		if ((!ft_isdigit(*part) && *part != '.')
			|| (*part == '.' && !ft_isdigit(*(part + 1)))
			|| (*part == '.' && !ft_isdigit(*(part - 1))))
			return (ERROR);
		part++;
	}
	return (OK);
}
