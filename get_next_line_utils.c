 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchotel <jchotel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:06:10 by jchotel           #+#    #+#             */
/*   Updated: 2020/01/21 16:06:14 by jchotel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		fnr(void *mem, int code)
{
	free(mem);
	return (code);
}

void	*ft_calloc(unsigned int n, int size)
{
	void	*mem;
	int		total;

	total = n * size;
	if (!(mem = malloc(total)))
		return (NULL);
	while (total-- > 0)
		*(unsigned char *)mem++ = 0;
	return (mem - size * n);
}

int		get_next_char(char *str, char c)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	if (str[index] == c)
		return (index);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*joined;

	i = 0;
	j = 0;
	if (!(joined = (char *)malloc(sizeof(char) *
			(get_next_char(s1, '\0') + get_next_char(s2, '\0')) + 1)))
		return (NULL);
	while (s1[j])
	{
		joined[i] = s1[j];
		j++;
		i++;
	}
	free(s1);
	j = 0;
	while (s2[j])
	{
		joined[i] = s2[j];
		j++;
		i++;
	}
	joined[i] = 0;
	return (joined);
}

char	*ft_substr(char *str, unsigned int start, int len)
{
	int		index;
	char	*new_str;

	index = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (str[start] && len)
	{
		new_str[index] = str[start];
		len--;
		start++;
		index++;
	}
	new_str[index] = 0;
	return (new_str);
}
