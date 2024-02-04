/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:22:12 by ael-qori          #+#    #+#             */
/*   Updated: 2024/02/04 14:52:54 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINISHELL
#define MINISHELL

#include "../libft/libft.h"
#include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <errno.h>
# include <signal.h>


#define MINISHELL_PROMPT "MiniShell $> "
#define HOME "HOME"
#define PWD "PWD"

// struct 

// env

typedef struct s_env
{
    char    *key;
    char    *value;
    struct s_env *next;
}t_env;

t_env *ft_lst_new_env(char *key, char *value);
char    *ft_getkey_env(char *str);
void    ft_lst_env_addback(t_env **env, t_env *node);
char    *ft_getvalue_env(char *str);
void    ft_lst_inert(t_env **env, t_env *node);
t_env *ft_env(char **env);
// parsing

char    *ft_prompt(void);


#endif