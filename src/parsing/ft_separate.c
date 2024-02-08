/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:47:23 by ael-qori          #+#    #+#             */
/*   Updated: 2024/02/08 09:54:28 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	filter_space(char	*s)
{
	int	i;
	int single_quote;
	int double_quote;
	i = 0;
	single_quote = 1;
	double_quote = 1;
	
	while (s[i])
	{
		if ((s[i] == ' ' || ft_is_redirections_char(s[i])) && single_quote == -1)
			s[i] *= -1;
		else if ((s[i] == ' ' || ft_is_redirections_char(s[i])) && double_quote == -1)
			s[i] *= -1;
		if (s[i] == '\'')
			single_quote *= -1;
		if (s[i] == '"')
			double_quote *= -1;
		i++;
	}	
}

void	ft_fix_spaces(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] < 0)
				arr[i][j] *= -1;
			j++;
		}		
		i++;
	}
}


char    **ft_separate(char *str)
{
    char	*cur;
	char	**arr;
	char	*tmp;
	cur = ft_strdup(str);
	filter_space(cur);
	tmp = ft_insert_space(cur);
	// printf("tmp :\t%s\n",tmp);
	arr = ft_split(tmp, ' ');
	free(cur);
	ft_fix_spaces(arr);
	return (arr);
}
