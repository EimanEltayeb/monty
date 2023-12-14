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
	if (strcmp(arr[0], "push") == 0)
		psh(arr, line_num, head);
	else if (strcmp(arr[0], "pall") == 0)
		pll(head);
	else if (strcmp(arr[0], "pint") == 0)
		pnt(head);
		else if (strcmp(arr[0], "nop") == 0)
			return (0);
	return (0);
}

/**
 * free_list - free the linked list
 * @head: head pointer
*/
void free_list(stack_t **head)
{
	stack_t *temp1, *temp2;

/*	if (head != NULL)
	{
		temp = (*head)->next;
		if (temp == NULL)
			free(head);
		else
		{*/
		temp1 = *head;
			while (temp1 != NULL)
			{
				temp2 = temp1->next;
				free(temp1);
				temp1 = temp2;
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

