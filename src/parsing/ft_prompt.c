/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:33:37 by ael-qori          #+#    #+#             */
/*   Updated: 2024/02/04 14:09:49 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char    *current_path(void)
{
    char    *home;
    char    *current_dir;
    char    *path;

    home = getenv(HOME);
    if (home == NULL)
        return (NULL);
    current_dir = getenv(PWD);
    if (ft_strnstr(home,current_dir, ft_strlen(home)))
        path = ft_strjoin("~/", current_dir + ft_strlen(home));
    else
        path = ft_strdup(current_dir);
    return (path);
}

char    *ft_prompt(void)
{
    char    *current_dir;
    char    *prompt;

    current_dir = current_path();
    prompt = ft_strjoin(MINISHELL_PROMPT, current_dir); 
    free(current_dir);
    return (prompt);
}