/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:11:34 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/08/12 20:28:11 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define TRUE 1
# define FALSE 0
# define AVAILABLE_SETS "The available sets are:\n mandelbrot;\n julia.\n"

# include <math.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include "mlx.h"
# include "libft.h"

typedef struct s_complex
{
	double	real;
	double	imaginary;
}				t_complex;

typedef struct s_fractol
{
	int			flag;
	t_complex	z;
}				t_fractol;

enum e_sets
{
	mandelbrot = 1,
	julia = 2
};
/** check inputs in argc and argv **/
void	check_input(int	argc, char **argv, t_fractol *fractol);
#endif
