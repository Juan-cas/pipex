/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:41:51 by juan-cas          #+#    #+#             */
/*   Updated: 2024/05/10 20:00:06 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

//static int 	ft_countword(char const *s, char c)
//{
//	int	count;
//
//	count = 0;
//	while (*s)
//	{
//		while (*s == c)
//			s++;
//		if (*s != '\0')
//			count++;
//		while (*s && *s != c)
//			s++;
//	}
//	return (count + 1);
//}
//
//static char	**filler(const char *s, char **lst, char c)
//{
//	size_t	word_len;
//	int		i;
//
//	i = 0;
//	while (*s)
//	{
//		while (*s == c)
//			s++;
//		if (*s != '\0')
//		{
//			word_len = 0;
//			while (s[word_len] != '\0' && s[word_len] != c)
//				word_len++;
//			lst[i] = (char *)malloc(sizeof(char) * (word_len + 1));
//				malloc_error_check(lst[i]);
//			ft_strlcpy(lst[i], s, word_len + 1);
//			i++;
//			s += word_len;
//		}
//	}
//	lst[i++] = ft_substr(file, 0, ft_strlen(file));
//	malloc_error_check(lst[i]);
//	lst[i] = NULL;
//	return (lst);
//}

//char	**split_w_file(char const *s, char c)
//{
//	char	**lst;
//	int		wordcount;
//
//	if (!s)
//		return (NULL);
//	wordcount = ft_countword(s, c);
//	lst = (char **)malloc((wordcount + 1) * sizeof(char **));
//	if (!lst)
//		return (NULL);
//	filler(s, lst, c);
//	return (lst);
//}