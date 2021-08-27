/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:11:34 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/08/27 17:54:42 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define TRUE 1
# define FALSE 0
# define MAX_ITER 80
# define WIDTH 600
# define HEIGHT 600
# define REAL_INIT -2
# define REAL_DISTANCE 4
# define IMG_INIT -2
# define IMG_DISTANCE 4

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
	double	re;
	double	im;
}				t_complex;

typedef struct s_fractol
{
	int			flag;
	t_complex	c;
	t_complex	z;
	t_data		img;
	void		*mlx;
	void		*mlx_win;
	int			(*iter)();
}				t_fractol;

enum e_sets
{
	mandelbrot = 1,
	julia = 2
};

/** check inputs in argc and argv **/
void	check_input(int	argc, char **argv, t_fractol *fractol);

/* initialize mlx */
void	init_mlx(t_fractol *fractol);

/* iteration to mandelbrot */
int		iteration_mandelbrot(t_complex c, t_complex z);

/* generate the image */
void	gen_img(t_fractol *fractol);

/* show errors message on code */
void	error_handler(int n_error, t_fractol **to_free);
#endif
