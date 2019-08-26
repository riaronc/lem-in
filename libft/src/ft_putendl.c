/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:48:04 by odushko           #+#    #+#             */
/*   Updated: 2018/10/31 15:52:02 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		ft_putendl(char const *s)
{
	if (s)
	{
		ft_putstr(s);
		ft_putchar_fd('\n', 1);
		return (1);
	}
	return (0);
}