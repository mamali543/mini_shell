#include "minishell.h"

void	add_to_lk(char *s, int a, t_cl *tmp, t_list **list_keys)
{
	tmp = malloc(sizeof(t_cl));
	tmp->c = s[a];
	ft_lstadd_back(list_keys, ft_lstnew(tmp));
}

// kanhez env variable f list o kancovrtiha l string
void		to_skip(char *s, size_t *a, t_list **head, size_t i)
{
	t_cl	*tmp;
	t_list	*list_keys;
	char	*key;

	list_keys = NULL;
	tmp = NULL;
	if (s[i + 1] == '\'')
	{
		add_to_lk(s, *a, tmp, &list_keys);
		key = ll_to_string(list_keys);
		add_string(head, key);
		return ;
	}
	(*a)++;
	while (((s[(*a)] != '$') && (s[(*a)] != '\'') && (s[(*a)] != ' ') \
		&& (s[(*a)] != '"') && (s[(*a)] != '-')) && s[(*a)])
			add_to_lk(s, (*a)++, tmp, &list_keys);
	key = ll_to_string(list_keys);
	key = return_env_value(key);
	add_string(head, key);
	(*a)--;
}
// ila kan khasso yt2expanda kanb6a n2ajouter f les charactres f wahd list
// hta kanl6a $ HHHHH
void	expand_word(char *str, t_list **head, int a, size_t i)
{
	t_cl	*tmp;
	size_t	f;
    while (1)
    {
		tmp = malloc(sizeof(t_cl));
		tmp->c = str[i];
        if (str[i] ==  '$')
		{
			f = i;
			to_skip(str , &i, head, f);
		}
		else if (str[i] == ' ' && a == 0)
		{
			ft_lstadd_back(head, ft_lstnew(tmp));
			while (str[i] == ' ')
				i++;
			i--;
		}
		else
			ft_lstadd_back(head, ft_lstnew(tmp));
		if (i >= ft_strlen(str) - 1)
			break;
		i++;
    }
	// p = ll_to_string(*head);
	//docker was here
}

t_type	*ft_lstnew_type2(char *content, int i, int a)
{
	t_type *new;

	new = (t_type *)malloc(sizeof(t_type) * 1);
    new->word = content;
    new->type = i;
	new->a = a;
	new->next = NULL;
	return (new);
}

//loup eela list type kandistingui fiha type dyal l words li eendi f list
// o kanreturni had list me2expandia
t_type	*expander(t_type *tmp)
{
    t_type  *tmp2;
    t_type  *new;
	t_list	*head;
	char	*str;


    tmp2 = tmp;
	new = NULL;
    while (tmp2)
    {
		head = NULL;
        if (tmp2->type == 2 || tmp2->type == 0)
           expand_word(tmp2->word, &head, tmp2->type, 0);
		else
			add_string(&head, tmp2->word);
		str = ll_to_string(head);
		if (tmp2->type == 0)
			add_tab_to_ll(&new, str, tmp2->type, tmp2->a);
		else
 			ft_lstadd_back_type(&new, ft_lstnew_type2(str, tmp2->type, tmp2->a));
        tmp2 = tmp2->next;
    }
    return (new);
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
char	*return_env_value(char *key)
{
	t_list	*env;
	t_env	*tmp;
	size_t		i;

	env = g_data->env;
	i = 0;
	while (env)
	{
		tmp = (t_env *)env->content;
		i = ft_strlen(tmp->name);
		if (i == ft_strlen(key))
		{
			if (ft_strcmp(tmp->name, key) == 0)
				return (tmp->content);
		}
		env = env->next;
	}
	return (ft_strdup(""));
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
		// printf("%c\n", tmp->c);
		ft_lstadd_back(head, ft_lstnew(tmp));
		i++;
	}
	// printlist_cl(*head);
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