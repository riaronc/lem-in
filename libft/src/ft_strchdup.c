/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 19:08:16 by odushko           #+#    #+#             */
/*   Updated: 2019/06/29 19:08:18 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchdup(const char *str, char ch)
{
	char	*ret;
	int		i;
	int		len;

	len = 0;
	if (str)
	{
		while (str[len] != ch && str[len] != '\0')
			len++;
		if (!(ret = (char *)malloc(len + 1)))
			return (NULL);
		i = -1;
		while (++i < len)
			ret[i] = str[i];
		ret[i] = 0;
		return (ret);
	}
	return (NULL);
}
