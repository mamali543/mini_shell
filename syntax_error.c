/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:10:02 by mamali            #+#    #+#             */
/*   Updated: 2021/11/02 23:27:09 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    log_error(char *s)
{
    ft_putstr(s);
}

int     is_redirection(int i)
{
    if (i == 4 || i == 5 || i == 6 || i == 3)
        return (1);
    return (0);
}

void    check_words(t_type *tmp)
{
    t_type  *tmp2;
    int     i;

    tmp2 = tmp;
    i = 0;
    if (tmp2->word[0] == '|')
        log_error("syntax_error\n");
    while (tmp2)
    {
        if (tmp2->word[0] == '\'' || tmp2->word[0] == '"')
        {
            if (ft_strlen(tmp2->word) == 1)
                log_error("syntax_error\n");
            i = ft_strlen(tmp2->word);
            if (tmp2->word[i - 1] != '\'')
                log_error("syntax_error\n");
        }
        if (is_redirection(tmp2->type))
            if (!(tmp2->next))
                log_error("syntax_error\n");
        tmp2 = tmp2->next;
    }
}

void    syntax_error(t_list *types)
{
    t_type  *tmp;
    char    *str;
    int     i;

    while (types)
    {
        tmp = types->content;
        check_words(tmp);
        types = types->next;
    }
    
    str = g_data->line;
    i = 0;
    if (str[i] == '|')
        log_error("syntax_error\n");
}