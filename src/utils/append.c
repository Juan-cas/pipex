/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 21:07:10 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/10 21:07:35 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	*append(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	s3 = ft_calloc((ft_strlen(s1) + 1 + ft_strlen(s2)), sizeof(char *));
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	s3[i++] = '/';
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	return (s3);
}