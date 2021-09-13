/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:14:34 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/08/27 12:52:26 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	message_error(int n_error);

void	error_handler(int n_error, t_fractol **to_free)
{
	if (to_free == NULL)
	{
		if (n_error == AVAILABLE_SETS)
			printf("THE AVAILABLE SETS ARE:\n mandelbrot;\n julia;\n mandelbar.\n");
		else if (n_error == COMPLEX_ARGUMENTS)
			printf("THE COMPLEX NUMBER MUST BE GIVEN IN TWO \
SEPARATE ARGUMENTS(2, 3).\nWHICH THE NUMBER 2 \
ARE THE REAL PART (+0.0 OR -0.0) AND THE NEXT \
ARE THE IMAGINARY PART(+0.0i OR -0.0i).\n");
		else if (n_error == IMAGINARY_PART)
			printf("IN FOURTH ARGUMENT USE ONE OF THIS \
FORMATS: +0.0i OR -0.0i\n");
		else if (n_error == REAL_PART)
			printf("IN THIRD ARGUMENT USE ONE OF THIS FORMATS: +0.0 OR -0.0\n");
	}
	else
	{
		if ((*to_free)->img.img)
			mlx_destroy_image((*to_free)->mlx, (*to_free)->img.img);
		if ((*to_free)->mlx_win)
			mlx_destroy_window((*to_free)->mlx, (*to_free)->mlx_win);
		if ((*to_free)->mlx)
			mlx_destroy_display((*to_free)->mlx);
		message_error(n_error);
		printf("%s\n", strerror(ENOMEM));
	}
	exit (EXIT_FAILURE);
}

static void	message_error(int n_error)
{
	if (n_error == MLX_NULL)
		perror("Mlx not initiate");
	else if (n_error == MLX_IMG_NULL)
		perror("Window not Initialized");
	else if (n_error == MLX_IMG_NULL)
		perror("Image is Null");
}
