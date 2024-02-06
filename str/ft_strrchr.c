/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:14:56 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/16 22:15:00 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	tofind;
	const char		*last;

	tofind = (unsigned char)c;
	last = NULL;
	while (*s)
	{
		if (*s == tofind)
			last = s;
		s++;
	}
	if (tofind == '\0')
		return ((char *)s);
	return ((char *)last);
}

/*int	main(void)
{
	const char *str = "Brotherhood";
	int search_char = '\0';

	char *result = ft_strrchr(str, search_char);

	if (result)
		printf("last occurrence of '%c' found at index: %ld.\n", search_char,
				result - str);
	else
		printf("'%c' not found in the string.\n", search_char);

	return (0);
}*/