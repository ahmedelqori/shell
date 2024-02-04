/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:26:35 by ael-qori          #+#    #+#             */
/*   Updated: 2024/02/04 14:54:08 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


int main(int ac, char **av, char **env_list)
{
    (void)ac;
    (void)av;
    t_env *env;

    env = ft_env(env_list);
    (void)env;
    // char    *command;
    // char    *prompt;

    // while (1)
    // {
    //     prompt = ft_prompt();
    //     command = readline(prompt);
    //     free(prompt);
    //     free(command);        
    // }
    
    return 0;
}