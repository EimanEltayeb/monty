#include "monty.h"
/**
 * pll - prints all values of stack
 * @head: header pointer
*/
void pll(stack_t **head)
{
	stack_t *temp;


	temp = *head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * check_opcode - function to check for opcode
 * @arr: array
 * @line_num: line number
 * @head: head pointer
 * Return: int
*/
int check_opcode(char **arr, int *line_num, stack_t **head)
{
	int check = 1;

	if (strcmp(arr[0], "push") == 0)
		check = psh(arr, line_num, head);
	else if (strcmp(arr[0], "pall") == 0)
		pll(head);
	else if (strcmp(arr[0], "pint") == 0)
		pnt(head);
	else if (strcmp(arr[0], "nop") == 0)
		return (1);
	else if (strcmp(arr[0], "add") == 0)
		ad(head);
	else
		check = 0;
	return (check);
}

/**
 * free_list - free the linked list
 * @head: head pointer
*/
void free_list(stack_t **head)
{
	stack_t *temp1, *temp2;

	if (*head != NULL)
	{
		temp1 = *head;
		while (temp1 != NULL)
		{
			temp2 = temp1->next;
			free(temp1);
			temp1 = temp2;
		}
		*head = NULL;
	}
}

/**
 * pnt - print the top element of the stack
 * @head: head pointer
*/
void pnt(stack_t **head)
{
	printf("%d\n", (*head)->n);
}

/**
 * ad - adds the two top elements
 * @head: head pointer
*/
void ad(stack_t **head)
{
	stack_t *temp;
	int x;

	x = (*head)->n + (*head)->next->n;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next->prev = (*head);
	free(temp);
	(*head)->n = x;
}
