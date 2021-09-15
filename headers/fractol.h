/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:11:34 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/09/11 18:21:20 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define TRUE 1
# define FALSE 0
# define WIDTH 600
# define HEIGHT 600
# define REAL_INIT -2
# define DISTANCE 4
# define IMG_INIT -2
# define NO_VALID_KEY 1
# define MWHEEL_UP 4
# define MWHEEL_DOWN 5
# define MOTION_NOTIFY 06
# define ESCAPE 0xff1b
# define LEFT  0xff51
# define UP    0xff52
# define RIGHT 0xff53
# define DOWN  0xff54

# include <math.h>
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
}	t_data;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractol
{
	int			flag;
	t_complex	c;
	t_complex	z;
	double		zoom;
	double		offset_x;
	double		offset_y;
	t_data		img;
	void		*mlx;
	void		*mlx_win;
	int			(*iter)();
	double		scale_x;
	double		scale_y;
	int			max_iter;
	int			colors[500];
	int			motion_mouse;
}	t_fractol;

enum e_sets
{
	mandelbrot = 1,
	julia = 2,
	burnship = 3
};

/* check inputs in argc and argv */
void	check_input(int argc, char **argv, t_fractol *fractol);

/* initialize mlx */
void	init_mlx(t_fractol *fractol, char *name);

/* calculate colors */
void	calc_colors(int colors[], int max_iter);

/* calculate mandelbrot set */
int		mandelbrot_set(t_complex c, t_complex z, int max_iter);

/* calculate julia set */
int		julia_set(t_complex z, t_complex c, int max_iter);

/* newton sin set */
int		burnship_set(t_complex c, t_complex z, int max_iter);

/* generate the image */
int		gen_img(t_fractol *fractol);

/* show errors message on code */
void	error_handler(int n_error, t_fractol **to_free);

/* hooks */

/* initilize hooks */
void	init_hooks(t_fractol *fractol);

/* check which key is pressed and make the respectively actions*/
int		check_key(int key, t_fractol *fractol);

/* zooming the image */
int		get_zoom(int key, int x, int y, t_fractol *fractol);

/* mouse motion detect */
int		motion_mouse(int x, int y, t_fractol *fractol);
#endif
