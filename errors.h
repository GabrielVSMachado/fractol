/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:03:21 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/08/13 13:42:26 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define AVAILABLE_SETS 1
# define COMPLEX_ARGUMENTS_WRONG 2

/* show errors message on code */
void	error_handler(int n_error, char **to_free);
#endif
