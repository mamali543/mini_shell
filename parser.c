/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:48:20 by mamali            #+#    #+#             */
/*   Updated: 2021/10/25 02:40:04 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_type	*function(int dblq, int single, size_t i)
{
	t_type	*type;

	type = NULL;
	while (1)
	{
		if (g_data->line[i] == '\'' && single == 0 && dblq == 0)
			single = add_sq(&i, '\'', &type);
		else if (g_data->line[i] == '\''  && single == 1 && dblq == 0)
			single = 0;
		else if (g_data->line[i] == '"' && single == 0 && dblq == 0)
			dblq = add_sq(&i, '"', &type);
		else if (g_data->line[i] == '"' && single == 0 && dblq == 1)
			dblq = 0;
		else if (g_data->line[i] == '|' && single == 0 && dblq == 0)
		{
			ft_lstadd_back(&g_data->tokkens, ft_lstnew(type));
			type = NULL;
		}
		else if (g_data->line[i] == '>' && single == 0 && dblq == 0)
			add_out(&i, '>', &type);
		else if (g_data->line[i] == '<' && single == 0 && dblq == 0)
			add_in(&i, '<', &type);
		else if (g_data->line[i] != ' ')
			adds(&i, &type);
		if (i >= ft_strlen(g_data->line) - 1)
			break;
		i++;
	}
	return (type);
}

t_type	*parser()
{
	t_type	*tmp;

	tmp = function(0, 0, 0);
	if (tmp)
	{
		ft_lstadd_back(&g_data->tokkens, ft_lstnew(tmp));
		tmp = NULL;
	}
	return (tmp);
}