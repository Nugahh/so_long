/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:59:13 by fwong             #+#    #+#             */
/*   Updated: 2022/09/18 16:18:42 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	while (*s)
// 	{
// 		if ((unsigned char)*s == (unsigned char)c)
// 		{
// 			return ((char *)(s));
// 		}
// 		s++;
// 	}
// 	if (*s == c)
// 		return ((char *)s);
// 	return (NULL);
// }
/* 
int main()
{
	char a[50] = "bonjour";	

	printf("%s", ft_strchr(a, 'j'));
} */