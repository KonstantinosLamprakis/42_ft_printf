/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:26:55 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/11 08:13:14 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	<stdarg.h>: va_start, va_arg, va_copy, va_end
*/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
#endif
