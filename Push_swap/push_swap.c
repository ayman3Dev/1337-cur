#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct stack{
	int data;
	struct stack *next;
} stack;

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

static int	ft_countword(char const *s, char c)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			size++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (size);
}

static void	ft_free(char **array, int i)
{
	while (i)
	{
		free(array[--i]);
	}
	free(array);
}

static char	*allocate_string(const char *s, int start, int end)
{
	char	*array;
	int		i;

	i = 0;
	array = (char *)malloc(sizeof(char) * (end - start + 1));
	if (array == NULL)
		return (NULL);
	while (start < end && s[start])
	{
		array[i] = s[start];
		start++;
		i++;
	}
	array[start] = 0;
	return (array);
}

static int	len_worlds(char const *s, char c)
{
	int	j;

	j = 0;
	while (s[j] && s[j] != c)
		j++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		size;
	int		i;

	if (s == NULL) 
		return (NULL);
	size = ft_countword(s, c);
	array = (char **)malloc(sizeof(char *) * (size + 1));
	if (array == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		while (*s && *s == c)
			s++;
		array[i] = allocate_string(s, 0, len_worlds(s, c));
		if (array[i] == NULL)
		{
			ft_free(array, i);
			return (0);
		}
		s = s + len_worlds(s, c);
	}
	array[i] = NULL;
	return (array);
}

static int	ft_overf(unsigned long r, int s)
{
	int	n;

	n = 0;
	if (r > 9223372036854775807)
	{
		if (s % 2 == 0)
			n = -1;
		else
			n = 0; 
	}
	return (n);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				s;
	unsigned long	r;

	i = 0;
	s = 0;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + str[i] - '0';
		str++;
		if (r > 9223372036854775807)
			return (ft_overf(r, s));
	}
	if (s % 2 == 0)
		return ((int)r);
	return ((int)-r);
}

stack *ft_lstnew(int data)
{
	stack	*newnode = (stack*)malloc(sizeof(stack));
	if (newnode == NULL)
		return (NULL);
	newnode->data=data;
	newnode->next=NULL;
	return (newnode);
} 
void affiche_lst(stack *lst)
{
	if (!lst)
		return ;
	stack *poi = lst;
	while (poi)
	{
		printf("%d", poi->data);
		poi = poi->next;
	}
}
stack *ft_lstlast(stack *lst)
{
	if (!lst)
		return NULL;
	stack *last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

void ft_lstadd_front(stack *lst, stack *new)
{
	if (!lst)
		return ;
	stack *head = lst;
	new->next = head;
	head = new;
}
// int main (int argc, char **argv)
// {
// 	stack *stack_a = NULL;
// 	stack *stack_b = NULL;
// 	int i = 0;
// 	int j = 1;
// 	int num = 0;
// 	int x = 0;
// 	if (argc >= 2)
// 	{
// 		while (j < argc)
// 		{
// 			i = 0;
// 			x = 0;
// 			char **temp = ft_split(argv[j], ' ');
// 			if(!temp)
// 				return (-1);
// 			while (temp[x])
// 			{
// 				num = ft_atoi(temp[x]);
// 				stack *new = ft_lstnew(num);
// 				if(!new)
// 					return (-1);
				
				
// 				printf("{%d}", stack_a->data);
			
// 				// else{
// 				// 	stack* tempnode = stack_a;
// 				// 	while (tempnode->next != NULL){
// 				// 		tempnode = tempnode->next;
// 				// 	}
// 				// 	tempnode->next = newnode;
// 				// }
// 				x++;
// 			}
// 			free(temp);
// 			while (argv[j][i] != '\0')
// 			{
// 				if (argv[j][i] != ' ' && ft_isdigit(argv[j][i]) == 0)
// 				{
// 					printf("erreur, %c", argv[j][i]);
// 					return 0;
// 				}
// 				i++;
// 			}
// 			j++;
// 		}
// 	}
// }

int main()
{
	stack *node1 = ft_lstnew(4);
	stack *node2 = ft_lstnew(3);
	stack *node3 = ft_lstnew(2);
	stack *node4 = ft_lstnew(5);

	stack *head = node1;
	ft_lstadd_front(head, node1);
	ft_lstadd_front(head, node3);
	ft_lstadd_front(head, node4);
	// ft_lstadd_front(st, node2);
	// ft_lstadd_front(stack_a, node3);
	// ft_lstadd_front(stack_a, node4);


	affiche_lst(head);


	return (0);
}