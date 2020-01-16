#include <visualiser.h>

void fifo_push(t_fifo **stack, t_room *room)
{
	t_fifo *element;

	element = malloc(sizeof(t_fifo));
	element->room = room;
	element->next = NULL;
	if (*stack)
		element->next = *stack;
	*stack = element;
}

t_room *fifo_pop(t_fifo **stack)
{
	t_fifo *head;
	t_room *room;
	
	head = *stack;
	room = NULL;
	if (!head)
		return room;
	while (head->next && head->next->next)
		head = head->next;
	if (!head->next)
	{
		*stack = NULL;
		room = head->room;
		free(head);
	}
	else
	{
		room = head->next->room;
		free(head->next);
		head->next = NULL;
	}
	return (room);
}