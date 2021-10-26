/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 00:19:25 by macbookpro        #+#    #+#             */
/*   Updated: 2021/10/26 00:42:06 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*make_string(char *str, char c)
{
	size_t		i;
	char	*p;
	i = 0;
	
	if (str == NULL)
	{
		p = strdup("");
		return (make_string(p, c));
	}
	p = malloc(sizeof(str) * (strlen(str) + 2));
	while (i < strlen(str))
	{
		p[i] = str[i];
		i++;
	}
	p[i] = c;
	p[++i] = '\0';
	return (p);
}

void	add_string(t_list **head, char *str)
{
	t_cl	*tmp;
	int		i;

	i = 0;
	while (str[i])
	{
		tmp = malloc(sizeof(t_cl));
		tmp->c = str[i];
		ft_lstadd_back(head, ft_lstnew(tmp));
		i++;
	}
}

void	add_tab_to_ll(t_type **head, char *str, int type, int a)
{
	char **tab;
	int	i;

	i = 0;
	tab = ft_split(str, ' ');
	while (tab[i])
	{
		ft_lstadd_back_type(head, ft_lstnew_type2(tab[i], type, a));
		i++;
	}
}

void	free_nodes_types(t_type	**tmp)
{
	t_type	*tmp2;
	tmp2 = *tmp;
	while (*tmp)
	{
		tmp2 = *tmp;
		if (tmp2->word != NULL)
			free(tmp2->word);
		free(tmp2);
		*tmp = (*tmp)->next;
	}
}

