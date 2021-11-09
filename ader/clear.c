/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 03:23:05 by macbook           #+#    #+#             */
/*   Updated: 2021/11/09 20:32:47 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env(void *content)
{
	t_env	*tmp;

	tmp = (t_env *)content;
	free(tmp->content);
	free(tmp->name);
	free(tmp);
}

void	free_table(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
	table = NULL;
}

void	free_type(void *content)
{
	t_type	*tmp;

	tmp = (t_type *)content;
	free_nodes_types(&tmp);
}

void	free_cmd(void *content)
{
	t_cmd	*tmp;
	t_list	*tmp1;
	//t_cmd  	*help;
	//char *str;

	system("leaks minishell");
	tmp = (t_cmd *)content;
	//help = tmp;
	// //str = (char	*)tmp->args_list->content;
	// //free (str);
	while(tmp->args_list)
	{
		tmp1 = tmp->args_list;
		printf("ppppp %s \n", (char *)tmp1->content);
		//if (tmp1->content)
		//	free(tmp1->content);
		tmp->args_list = tmp->args_list->next;
		free(tmp1);	
	}
	system("leaks minishell");
	//free(help->args_list);
	free(tmp->cmd);
	free_table(tmp->str);
	free(tmp);
}

void	free_char(void *content)
{
	free(content);
}
