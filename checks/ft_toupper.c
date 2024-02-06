/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:50:21 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/01 20:57:32 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/*#include<stdio.h>
int	main(void) {
    char input = 'w';
    char result = ft_toupper(input);

    printf("Original character: %c\n", input);
    printf("Uppercase character: %c\n", result);

    return (0);
}*/