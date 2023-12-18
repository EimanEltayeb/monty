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
		check = pnt(head, line_num);
	else if (strcmp(arr[0], "nop") == 0)
		return (1);
	else if (strcmp(arr[0], "add") == 0)
		check = ad(head, line_num);
	else if (strcmp(arr[0], "pop") == 0)
		check = popp(head, line_num);
	else if (strcmp(arr[0], "swap") == 0)
		check = swaap(head, line_num);
	else if (strcmp(arr[0], "sub") == 0)
		check = subb(head, line_num);
	else if (strcmp(arr[0], "div") == 0)
		check = divv(head, line_num);
	else if (strcmp(arr[0], "mul") == 0)
		check = mult(head, line_num);
	else if (strcmp(arr[0], "mod") == 0)
		check = modd(head, line_num);
	else if (arr[0][0] == '#')
		check = 1;
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", *line_num, arr[0]);
		check = 0;
	}
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
	}
}



/**
 * popp - function to remove stacks top element
 * @head: head pointer
 * @line_num: line number
 * Return: exit status
*/
int popp(stack_t **head, int *line_num)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", *line_num);
		return (-2);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
	return (1);
}


/**
 * pnt - print the top element of the stack
 * @head: head pointer
 * @line_num: line number
 * Return: exit status
*/
int pnt(stack_t **head, int *line_num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", *line_num);
		return (-2);
	}
	printf("%d\n", (*head)->n);
	return (1);
}

/**
 * ad - adds the two top elements
 * @head: head pointer
 * @line_num: line number
 * Return: exit status
*/
int ad(stack_t **head, int *line_num)
{
	stack_t *temp;
	int x, count = 0;

	temp = *head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", *line_num);
		return (-2);
	}
	x = (*head)->n + (*head)->next->n;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next->prev = (*head);
	free(temp);
	(*head)->n = x;
	return (1);
}


/**
 * swaap - function to remove stacks top element
 * @head: head pointer
 * @line_num: line number
 * Return: exit status
*/
int swaap(stack_t **head, int *line_num)
{
	stack_t *temp, *temp2;
	int count = 0;

	temp = *head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", *line_num);
		return (-2);
	}
	temp = *head;
	*head = temp->next;
	temp2 = (*head)->next;
	if (temp2 != NULL)
		temp2->prev = temp;
	temp->next = temp2;
	(*head)->next = temp;
	(*head)->prev = NULL;
	temp->prev = *head;
	return (1);
}

/**
 * subb - function to subsstract top elementfrom the second top
 * @head: head pointer
 * @line_num: line number
 * Return: exit status
*/
int subb(stack_t **head, int *line_num)
{
	stack_t *temp;
	int x, count = 0;

	temp = *head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", *line_num);
		return (-2);
	}
	x = (*head)->next->n - (*head)->n;
	temp = (*head)->next;
	(*head)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = (*head);
	free(temp);
	(*head)->n = x;
	return (1);
}


/**
 * divv - function to divide top elementfrom the second top
 * @head: head pointer
 * @line_num: line number
 * Return: exit status
*/
int divv(stack_t **head, int *line_num)
{
	stack_t *temp;
	int x, count = 0;

	temp = *head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", *line_num);
		return (-2);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", *line_num);
		return (-2);
	}
	x = (*head)->next->n / (*head)->n;
	temp = (*head)->next;
	(*head)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = (*head);
	free(temp);
	(*head)->n = x;
	return (1);
}

/**
 * mult - function to product top elementfrom the second top
 * @head: head pointer
 * @line_num: line number
 * Return: exit status
*/
int mult(stack_t **head, int *line_num)
{
	stack_t *temp;
	int x, count = 0;

	temp = *head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", *line_num);
		return (-2);
	}
	
	x = (*head)->next->n * (*head)->n;
	temp = (*head)->next;
	(*head)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = (*head);
	free(temp);
	(*head)->n = x;
	return (1);
}

/**
 * modd - function to  top elementfrom the second top
 * @head: head pointer
 * @line_num: line number
 * Return: exit status
*/
int modd(stack_t **head, int *line_num)
{
	stack_t *temp;
	int x, count = 0;

	temp = *head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", *line_num);
		return (-2);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", *line_num);
		return (-2);
	}
	x = (*head)->next->n % (*head)->n;
	temp = (*head)->next;
	(*head)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = (*head);
	free(temp);
	(*head)->n = x;
	return (1);
}