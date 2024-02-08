/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 08:42:21 by ael-qori          #+#    #+#             */
/*   Updated: 2024/02/08 09:54:17 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_redirections_char(char c)
{
	if (c == '|' || c == '>' || c == '<' || c == ';')
		return (1);
	return (0);
}

int	ft_count_new_buffer(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (i == 0 && ft_is_redirections_char(s[i]) && s[i + 1 ]&& s[i + 1] != 32 )
			count++;
		if (i != 0 && ft_is_redirections_char(s[i]) && s[i - 1] != 32)
			count++;
		if (i != 0 && ft_is_redirections_char(s[i]) && s[i + 1] && s[i + 1] != 32)
			count++;
		i++;
	}
	return (count);
}

char*	ft_insert_space(char *s)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	len = ft_count_new_buffer(s) + ft_strlen(s);
	if (ft_count_new_buffer(s) == 0)
		return (s);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (ft_is_redirections_char(s[i]) == 0)
			str[j] = s[i];
		else
		{
			if (i != 0 && s[i - 1] != 32)
			{
				str[j] = ' ';
				j++;
				str[j] = s[i];
			}
			if (s[i + 1] && s[i + 1] != 32)
			{
				str[j] = s[i];
				j++;
				str[j] = ' ';
			}
		}
		j++;
		i++;
	}
	str[len] =0; 
	return (str);
}