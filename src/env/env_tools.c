/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:13:32 by ael-qori          #+#    #+#             */
/*   Updated: 2024/02/04 15:19:22 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env *ft_lst_new_env(char *key, char *value)
{
    t_env *node = malloc(sizeof(t_env));
    if (node == NULL)
        return (NULL);
    node->key = key;
    node->value = value;
    node->next = NULL;
    return (node);
}

void    ft_lst_inert(t_env **env, t_env *node)
{
    t_env *cur;
    t_env *tmp;

    cur = (*env);
    if (node == NULL)
        return ;
    while (cur)
    {
        if (cur->next && ft_strncmp(node->key , cur->next->key,ft_strlen(node->key)) < 0)
        {
            tmp = cur->next;
            cur->next = node;
            node->next =tmp;
            return ;
        }
        else
        {
            cur->next = node;
            return ;
        }
    }
    cur = node;
}

void    ft_lst_env_addback(t_env **env, t_env *node)
{
    t_env *cur;

    cur = (*env);
    if (node == NULL)
        return ;
    if (*env == NULL)
        *env = node;
    else
    {
        while (cur->next)
            cur = cur->next;
        cur->next = node;
    }
}

char    *ft_getkey_env(char *str)
{
    int     i;
    int     j;
    char    *key;

    i = -1;
    while (str[++i])
        if (str[i] == '=')
            break;
    key = malloc(sizeof(char) * (i + 1));
    if (key == NULL)
        return (NULL);
    j = 0;
    while (j < i)
    {
        key[j] = str[j];
        j++;
    }
    key[j] = 0;
    return (key);
}

char    *ft_getvalue_env(char *str)
{
    int     i;
    char    *value;
    i = -1;
    while (str[++i])
        if (str[i] == '=')
            break;
    value = ft_strdup(str + i + 1);
    return (value);
}