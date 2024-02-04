/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:26:35 by ael-qori          #+#    #+#             */
/*   Updated: 2024/02/04 15:45:24 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


int main(int ac, char **av, char **env_list)
{
    t_env *env;

    env = ft_env(env_list);
    char    *command;
    char    *prompt;

    while (1)
    {
        ft_signals();
        prompt = ft_prompt(env);
        command = readline(prompt);
        if (command == NULL)
            exit(1);
        add_history(command);   
        free(prompt);
        free(command);     
    }
    rl_clear_history();
    (void)ac;
    (void)av;
    return 0;
}