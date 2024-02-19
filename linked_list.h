#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	void *data;
	t_node *next;
} t_node;

t_node	*init(void *data);
void	clear(const t_node *head);

void	push_back(const t_node *head, void *data);
t_node	*push_front(const t_node *head, void *data);

void	*pop_back(const t_node *head);
t_node	*pop_front(const t_node *head);

void	*get(const t_node *head, size_t index);
int		find_int(const t_node *head, int data);
int		find_char(const t_node *head, char data);

void	print(const t_node *head);

#endif