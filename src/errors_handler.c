/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:27:35 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/08/13 14:02:17 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_handler(int n_error, char **to_free)
{
	if (*to_free == NULL)
	{
		if (n_error == AVAILABLE_SETS)
			printf("The available sets are:\n mandelbrot;\n julia.\n");
		else if (n_error == COMPLEX_ARGUMENTS)
			printf("THE COMPLEX NUMBER MUST BE GIVEN IN TWO\
					SEPARATE ARGUMENTS(2, 3). WHICH THE NUMBER 2 \
					ARE THE REAL PART (+0.0 OR -0.0) AND THE NEXT \
					ARE THE IMAGINARY PART(+0.0i OR -0.0i)\n");
		else if (n_error == IMAGINARY_PART)
			printf("IN FOURTH ARGUMENT USE ONE OF THIS \
					FORMATS: +0.0i OR -0.0i\n");
		else if (n_error == REAL_PART)
			printf("IN THIRD ARGUMENT USE ONE OF THIS FORMATS: +0.0 OR -0.0\n");
	}
	else
	{
		free(*to_free);
		printf("%s\n", strerror(ENOMEM));
	}
	exit (EXIT_FAILURE);
}
