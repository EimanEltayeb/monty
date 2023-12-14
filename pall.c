#include "monty.h"
/**
 * pll - prints all values of stack
 * @head: header pointer
*/
void pll(stack_t **head)
{
	stack_t *temp;

	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
	printf("this is head %d", (*head)->n);
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
	if (strcmp(arr[0], "push") == 0)
		psh(arr, line_num, head);
	else if (strcmp(arr[0], "pall") == 0)
		pll(head);
	return (0);
}

/**
 * free_list - free the linked list
 * @head: head pointer
*/
void free_list(stack_t **head)
{
	stack_t *temp;

	if (head != NULL)
	{
		temp = (*head)->next;
		if (temp == NULL)
			free(head);
		else
		{
			while (temp->next != NULL)
			{
				free(temp->prev);
				temp = temp->next;
			}
			free(temp->prev);
			free(temp);
		}

	}
}
