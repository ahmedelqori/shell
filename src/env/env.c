/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:12:43 by ael-qori          #+#    #+#             */
/*   Updated: 2024/02/04 14:54:48 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env *ft_env(char **env_list)
{
    t_env *env;
    t_env *node;
    char    *key;
    char    *value;
    int i;

    i = 0;
    env = NULL;
    while (env_list[i])
    {
        key = ft_getkey_env(env_list[i]);
        value = ft_getvalue_env(env_list[i]);
        node = ft_lst_new_env(key, value);
        ft_lst_env_addback(&env, node);
        i++;
    }
    return env;
}
