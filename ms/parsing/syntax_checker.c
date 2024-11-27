/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:09:41 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/29 13:40:13 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	check_newline(t_syntax *p)
{
	if ((p->c == 'a' && !p->next) || (p->c == 'h' && !p->next) || (p->c == 'i'
			&& !p->next) || (p->c == 'o' && !p->next) || (p->c == 'p'
			&& !p->next) || (p->c == 'h' && p->next->c == 'i') || (p->c == 'i'
			&& p->next->c == 'o' && !p->next->next) || (p->c == 'b'
			&& !p->next))
		return (0);
	return (1);
}

int	check_append(t_syntax *p)
{
	if ((p->c == 'a' && p->next->c == 'a') || (p->c == 'h' && p->next->c == 'a')
		|| (p->c == 'i' && p->next->c == 'o' && p->next->next->c == 'a'))
		return (0);
	return (1);
}

int	check_out(t_syntax *p)
{
	if ((p->c == 'a' && p->next->c == 'o') || (p->c == 'h' && p->next->c == 'o')
		|| (p->c == 'i' && p->next->c == 'a') || (p->c == 'i'
			&& p->next->c == 'o' && p->next->next->c == 'o'))
		return (0);
	return (1);
}

int	check_in(t_syntax *p)
{
	if ((p->c == 'a' && p->next->c == 'i') || (p->c == 'h' && p->next->c == 'h')
		|| (p->c == 'i' && p->next->c == 'o' && p->next->next->c == 'i'))
		return (0);
	return (1);
}

int	check_herdoc(t_syntax *p)
{
	if ((p->c == 'a' && p->next->c == 'h')
		|| (p->c == 'o' && p->next->c == 'h')
		|| (p->c == 'i' && p->next->c == 'o'
			&& p->next->next->c == 'h'))
		return (0);
	return (1);
}
