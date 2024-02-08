/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:14:14 by ael-qori          #+#    #+#             */
/*   Updated: 2024/02/08 10:59:56 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tree *ft_new_tree(char *s)
{
	t_tree *node;

	node = malloc(sizeof(t_tree));
	if (node == NULL)	
		return (node);
	node->command = ft_strdup(s);
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	ft_tree_insert(t_tree **root, t_tree *node)
{
	t_tree *cur;

	cur = (*root);
	if (node == NULL)
		return;
	if (cur == NULL )
		(*root) = node;
	else if ((cur)->left == NULL || cur->right == NULL)
	{
		
		if (cur->left == NULL)
			cur->left = node;
		else if (cur->right == NULL)
			cur->right = node;
	}
	else
		ft_tree_insert(&cur->right , node);
}

t_tree *create_tree(char **arr)
{
	t_tree	*root;
	t_tree *node;
	int		i;

	i = 0;
	root = NULL;
	while (arr[i])
	{
		node = ft_new_tree(arr[i]);
		ft_tree_insert(&root, node);
		i++;
	}
	return (root);
}