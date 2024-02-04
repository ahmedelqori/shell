/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:43:13 by ael-qori          #+#    #+#             */
/*   Updated: 2024/02/04 17:44:09 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char    *ft_get_oldpwd(t_env **env)
{
    char    path[1024];
    char    *tmp;
    t_env   *cur;


    getcwd(path, 1024);
    if (path == NULL)
        return (NULL);
    cur = (*env);
    while (cur)
    {
        if (ft_strlen(PWD) == ft_strlen(cur->key) &&
        ft_strncmp(PWD, cur->key, ft_strlen(PWD) ) == 0)
        {
            tmp =  cur->value;
            cur->value = ft_strdup(path);
            break;
        }
        cur = cur->next;
    }
    return (tmp);
}

void    ft_put_oldpwd(char *oldpath, t_env **env)
{
    t_env   *cur;

    (cur) = (*env);
    while (cur)
    {
        if (ft_strlen(OLDPWD) == ft_strlen(cur->key) &&
        ft_strncmp(OLDPWD, cur->key, ft_strlen(OLDPWD)) == 0)
        {
            free(cur->value);
            cur->value = oldpath;
            break;
        }
        cur = cur->next;
    }
}

void    ft_cd(t_env **env, char *path)
{
    char *oldpath;

    if (chdir(path) == -1)
        printf("cd: no such file or directory: %s\n",path);
    else
    {
        oldpath = ft_get_oldpwd(env);
        ft_put_oldpwd(oldpath,env);
    }
}