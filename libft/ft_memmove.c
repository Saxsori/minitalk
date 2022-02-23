/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:13:45 by aaljaber          #+#    #+#             */
/*   Updated: 2021/10/13 15:14:01 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*src1;
	char	*dst1;
	size_t	i;

	src1 = (char *) src;
	dst1 = (char *) dst;
	i = 0;
	if (dst == src)
		return (dst);
	else if (src1 < dst1)
	{
		while (n--)
			*(&dst1[n]) = *(&src1[n]);
		return (dst);
	}
	else
	{
		while (n)
		{
			n--;
			*(dst1++) = *(src1++);
		}
		return (dst);
	}
}
