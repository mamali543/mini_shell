/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:53:44 by macbookpro        #+#    #+#             */
/*   Updated: 2021/10/24 13:03:20 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell"

// int    check_if_sq(char *str, int *j)
// {
//     int     i;

//     i = 0;
//     while (str[i] != '$')
//     {
//         if (str[i] == '\'')
//         {
//             while (str[i] != '$')
//                 (*j)++;
//         }
//         i++;
//     }
//     return (*j);
// }

// static int     is_in(char *line, int i, char c)
// {
//     int     j;
//     int     f;

//     j = i;
//     f = 0;
//     while (j-- >= 0)
//     {
//         if (line[j] == c)
//         {
//             if (real_character(line, j, '$'))
//             {
//                 f++;
//                 break;
//             }
//         }
//     }
//     j = i;
//     while (line[j])
//     {
//         if (line[j] == c)
//         {
//             if (real_character(line, j, '$'))
//             {
//                 f++;
//                 break;
//             }
//         }
//         j++;
//     }
//     if (line[i] == 36 && f == 0)
//         return (1);
//     if (f == 2)
//         return (1);
//     return (0);
// }

// static int     is_expandable(char *line, int i)
// {
//     int     a;
    
//     a = is_in(line, i, '\'');
//     return (a);
// }

// void    check_args(char *s)
// {
    
// }

// void    create_file(char *s, t_cmd *cmd)
// {
//     int fd;

//  	fd = open(s, O_WRONLY | O_CREAT | O_TRUNC , 0777);
//     cmd->out = fd; 
// }

// void    help_q(t_list **head, char c)
// {
// 	t_cl	*tmp;

// 	tmp = malloc(sizeof(t_cl));
// 	tmp->c = c;
// 	ft_lstadd_back(head, ft_lstnew(tmp));
// }