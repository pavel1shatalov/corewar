/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:26:33 by ggerhold          #+#    #+#             */
/*   Updated: 2019/10/30 16:26:33 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

static void	update_placeholder(t_placeholder *ph, wchar_t symbol)
{
	if (ph->flags & MINUS)
		ph->flags &= ~ZERO;
	ph->width = FT_MAX(ph->width, wchar_size(symbol));
	ph->padding = ph->width - wchar_size(symbol);
	if (wchar_size(symbol) > MB_CUR_MAX || wchar_size(symbol) == 0)
		ph->width = -1;
}

char		*handle_wc(t_placeholder *ph, va_list args)
{
	char	*str;
	wchar_t	symbol;
	char	c;

	str = NULL;
	update_placeholder(ph, (symbol = (wchar_t)va_arg(args, wint_t)));
	if (ph->width == -1)
		return (str);
	if (!(str = ft_strnew(ph->width)))
		exit(1);
	c = ((ph->flags & ZERO) ? '0' : ' ');
	if (!(ph->flags & MINUS))
		while (ph->padding > 0 && ph->padding--)
			*str++ = c;
	strcatwchar_ptr(&str, symbol);
	while (ph->padding > 0 && ph->padding--)
		*str++ = c;
	return (str - ph->width);
}
