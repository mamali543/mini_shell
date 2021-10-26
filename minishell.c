#include "minishell.h"

t_list	*get_args(t_list **args ,t_type	*types)
{
	t_type	*tmp;
	t_type	*prev;
	t_list	*list_files;
	
	tmp = types;
	list_files = NULL;
	while (tmp)
	{
		prev = tmp->prev;
		if (tmp->type == 4)
			ft_lstadd_back(&list_files, ft_lstnew(tmp->next->word));
		if (tmp->type != 4)
		{
			if (tmp->prev != NULL)
			{
				if (tmp->prev->type != 4)
					help_args(tmp, args);
			}
			else
				ft_lstadd_back(args, ft_lstnew(tmp->word));
		}
		tmp = tmp->next;
	}
	return (list_files);
}

void	get_out(int *i, t_list *list_files)
{
	char	*s;
	size_t	a;
	size_t	j;
	if (list_files)
	{
		s = ft_lstlast(list_files)->content;
		printf("file_out is = %s\n", s);
		a = ft_strlen(list_files->content);
		j = ft_strlen(s);
		*i = open(s, O_WRONLY | O_CREAT | O_TRUNC , 0777);
		while (list_files)
		{
			if (ft_strcmp(s, list_files->content) != 0 || a != j)
				open(list_files->content, O_WRONLY | O_CREAT | O_TRUNC , 0777);
			if (list_files->next)
				a = ft_strlen(list_files->next->content);
			list_files = list_files->next;
		}
	}
}
// > file echo sdsd > file2
// echo "$PATH"dfgd
void	first_round(t_type *tmp2, char *str, t_cmd **cmd, t_type **expanded_types)
{
	if (tmp2->type == 4)
	{
		if (ft_lstsize_type(tmp2) == 3)
		{
			str = get_node(tmp2)->word;
			(*cmd)->cmd = get_cmd_path(str, g_data->env);
		}
		else
		{
			str = get_node(tmp2)->word;
			(*cmd)->cmd = get_cmd_path(str, g_data->env);
		}
	}
	else if (tmp2->type == 0)
		(*cmd)->cmd = get_cmd_path((*expanded_types)->word, g_data->env);
}

void	expand_cmdlist(int i, t_list *tmp, char *str)
{
	t_cmd	*cmd;
	t_type	*expanded_types;
	t_list	*list_files;
	t_type	*tmp2;

	while (tmp)
	{
		tmp2 = tmp->content;
		expanded_types = expander(tmp->content);
		cmd = malloc(sizeof(t_cmd));
		if (i++ == 0)
			first_round(tmp2, str, &cmd, &expanded_types);
		else
			cmd->cmd = get_cmd_path(expanded_types->word, g_data->env);
		cmd->args_list = NULL;
		list_files = get_args(&(cmd->args_list), expanded_types);
		get_out(&(cmd->out), list_files);
		cmd->in = 1;
		ft_lstadd_back(&g_data->cmd_list, ft_lstnew(cmd));
		tmp = tmp->next;
		printf("--------------------\n");
	}
}

int		main(int argc, char **argv, char **env)
{
	t_list *tmp;
	char *str;

	g_data = malloc(sizeof(t_data));
	init_env_list(env);
	argc = 0;
	argv = NULL;
	str = NULL;
	while (1)
	{
		g_data->tokkens = NULL;
		g_data->cmd_list = NULL;
		if (!(g_data->line = readline("ader🤡$>")))
	    	return (1);
		parser();
		tmp = g_data->tokkens;
		expand_cmdlist(0, tmp, str);
		print_cmd();
		// excute_cmd();
		print_tokkens();
		add_history(g_data->line);
		// check_words(tmp);
	}
	return (0);
}


