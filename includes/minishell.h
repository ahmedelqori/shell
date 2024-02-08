/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:22:12 by ael-qori          #+#    #+#             */
/*   Updated: 2024/02/08 10:43:24 by ael-qori         ###   ########.fr       */
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

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLDBLACK "\033[1m\033[30m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDYELLOW "\033[1m\033[33m"
#define BOLDBLUE "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN "\033[1m\033[36m"
#define BOLDWHITE "\033[1m\033[37m"


#define MINISHELL_PROMPT "MiniShell $> "
#define HOME "HOME"
#define PWD "PWD"
#define OLDPWD "OLDPWD"

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


// built in

void    ft_cd(t_env **env, char *path);


// signals

void    ft_signals(void);


// parsing
char*	ft_insert_space(char *s);
int	ft_is_redirections_char(char c);
char    **ft_separate(char *str);

char    *ft_prompt(t_env *env);

typedef struct s_tree
{
    char    *command;
    struct s_tree *left;
    struct s_tree *right;
} t_tree;

t_tree *create_tree(char **arr);
#endif