/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:11:34 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/08/14 16:45:07 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define TRUE 1
# define FALSE 0

# include <math.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include "mlx.h"
# include "libft.h"
# include "errors.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_p_pix;
	int		line_lenght;
	int		endian;
}				t_data;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}				t_complex;

typedef struct s_fractol
{
	int			flag;
	void		*mlx;
	t_data		img;
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
