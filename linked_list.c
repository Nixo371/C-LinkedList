#include "linked_list.h"

// Initializes the linked list and returns the head node
// @param data The data that will be in the head node
// @return The head node of the linked list
t_node *init(void *data) {
	t_node *head = (t_node *)malloc(sizeof(t_node));
	head->data = data;
	head->next = NULL;

	return (head);
}

// Clears the linked list, freeing all data associated with it (including the data pointers)
// @param head The head node of an existing linked list
void clear(const t_node *head) {
	t_node *current = head;
	t_node *prev = NULL;

	while (current->next) {
		prev = current;
		current = current->next;

		free(prev->data);
		free(prev);
	}
	free(current->data);
	free(current);
}

// Adds an element to the end of the list
// @param head The head node of an existing linked list
// @param data The data to add to the new node
void push_back(const t_node *head, void *data) {
	if (head == NULL)
		return;

	t_node *new_node = (t_node *)malloc(sizeof(t_node));

	new_node->data = data;

	t_node *current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = new_node;
}

// Adds an element to the front of the list
// @param head The head node of an existing linked list
// @param data The data to add to the new node
// @return The new head of the linked list
t_node *push_front(const t_node *head, void *data) {
	if (head == NULL)
		return (NULL);

	t_node *new_node = (t_node *)malloc(sizeof(t_node));

	new_node->next = head;
	new_node->data = data;

	return (new_node);
}

// Removes the last element of the list
// @param head The head of an existing linked list
// @return The data contained in the node that was removed
void *pop_back(const t_node *head) {
	if (head == NULL)
		return (NULL);

	t_node *current = head;
	t_node *prev = NULL;
	void *data;

	while (current->next != NULL) {
		prev = current;
		current = current->next;
	}

	data = current->data;
	free(current);
	prev->next = NULL;

	return (data);
}

// Removes the last element of the list
// @param head The head of an existing linked list
// @return The new head of the linked list
t_node *pop_front(const t_node *head) {
	if (head == NULL)
		return (NULL);

	t_node *prev_head = head;
	t_node *new_head = head->next;

	free(prev_head);

	return (new_head);
}

// Gets the data at the specified index of the linked list
// @param head The head of an existing linked list
// @param index The position of the requested element in the list
// @return The data at the specified position in the linked list or NULL if not a valid position
void *get(const t_node *head, size_t index) {
	if (head == NULL)
		return (NULL);

	t_node *current = head;
	while (index--) {
		if (current->next == NULL) {
			return (NULL);
		}
		current = current->next;
	}
	return (current->data);
}

// Finds the first element in the list with a specified integer data
// @param head The head of an existing linked list
// @param data An integer type value that will be searched for in the list
// @return The index of the first node containing the integer value specified or -1 if the head node is null or the value is not present in the list.
int find_int(const t_node *head, int data) {
	if (head == NULL)
		return (-1);

	t_node *current = head;
	int i = 0;
	while (current != NULL) {
		if (*(int *)(current->data) == data) {
			return (i);
		}
		current = current->next;
		i++;
	}
	return (-1);
}

// Finds the first element in the list with a specified character data
// @param head The head of an existing linked list
// @param data A character type value that will be searched for in the list
// @return The index of the first node containing the character value specified or -1 if the head node is null or the value is not present in the list.
int find_char(const t_node *head, char data) {
	if (head == NULL)
		return (-1);

	t_node *current = head;
	int i = 0;
	while (current != NULL) {
		if (*(char *)(current->data) == data) {
			return (i);
		}
		current = current->next;
		i++;
	}
	return (-1);
}

// Prints the linked list out to the terminal
// @param head The head of an existing linked list
void print(const t_node *head) {
	if (head == NULL)
		return (NULL);

	t_node *current = head;
	while (current->next) {
		printf("[ %d ] -> ", (int)current->data);
	}
	printf("[ %d ]", (int)current->data);
}