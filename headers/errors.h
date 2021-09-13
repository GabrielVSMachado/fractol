/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:03:21 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/08/27 12:57:14 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H
# define ERROR -1
# define OK 0

enum	e_errors
{
	AVAILABLE_SETS = 1,
	COMPLEX_ARGUMENTS = 2,
	REAL_PART = 3,
	IMAGINARY_PART = 4,
	GEN_IMG = 5,
	MLX_NULL = 6,
	MLX_WIN_NULL = 7,
	MLX_IMG_NULL = 8,
};

#endif
