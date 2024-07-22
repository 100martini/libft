/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+ +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:11:27 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/16 22:11:56 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	words_count(char const *s);
static char		**mini_split(char const *s, char **tab,
					size_t words_count);

char	**ft_split(char const *s)
{
	char	**tab;
	size_t	words;

	if (!s)
		return (NULL);
	words = words_count(s);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	tab = mini_split(s, tab, words);
	return (tab);
}

static size_t	words_count(char const *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			count++;
			while (*s && *s != ' ' && *s != '\t')
				s++;
		}
		else
			s++;
	}
	return (count);
}

static size_t	word_length(char const *s)
{
	size_t	len;

	len = 0;
	while (*s && *s != ' ' && *s != '\t')
	{
		len++;
		s++;
	}
	return (len);
}

static void	freetab(size_t len, char **tab)
{
	size_t	i;

	i = -1;
	while (++i < len)
		free(tab[i]);
	free(tab);
}

static char	**mini_split(char const *s, char **tab, size_t words_count)
{
	size_t	i;

	i = 0;
	while (i < words_count)
	{
		while (*s == ' ' || *s == '\t')
			s++;
		tab[i] = ft_substr(s, 0, word_length(s));
		if (!tab[i])
			return (freetab(i, tab), NULL);
		s += word_length(s);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

/*int main()
{
    const char *str = ",,,,K,K,,K,,,";
    char **result = ft_split(str, ',');

    if (result)
        for (size_t i = 0; result[i]; i++)
            printf("Token %zu: %s\n", i + 1, result[i]);

    return (0);
}*/