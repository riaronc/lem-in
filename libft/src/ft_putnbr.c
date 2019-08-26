/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:44:07 by odushko           #+#    #+#             */
/*   Updated: 2018/10/31 17:14:24 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putnbr(int n)
{
	char *num;

	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		num = ft_itoa(n);
		ft_putstr(num);
		free(num);
	}
}
