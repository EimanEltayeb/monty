#include "monty.h"

/**
 * free_array - a function to free the line array
 * @arr: the array to be freed
 */
void free_array(char **arr)
{
	int i;

	for (i = 0; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr);
}


/**
 * psh2 - continue push function
 * @n: data to be added to the list
 * @head: head pointer
 * Return: number indicating success or failure.
 */
int psh2(int n, stack_t **head)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		return (-1);
	}
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head == NULL)
	{
		*head = new;
		return (1);
	}
	else
	{
		(*head)->prev = new;
		*head = new;
		return (1);
	}
}

/**
 * psh - pushes element to stack
 * @arr: arguments array
 * @line_num: line number in monty file
 * @head: head pointer
 * Return: 0 if error and 1 if success
 */

int psh(char **arr, int *line_num, stack_t **head)
{
	int i = 0, n, check_push;

	if (arr[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", *line_num);
		exit(EXIT_FAILURE);
	}
	while (arr[1][i] != '\0')
	{
		if (arr[1][0] == '-')
		{
			i++;
			continue;
		}
		if (arr[1][i] <= '0' || arr[1][i] >= '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", *line_num);
			free_array(arr);
			exit(EXIT_FAILURE);
		}
		else
			i++;
	}
	n = atoi(arr[1]);
	check_push = psh2(n, head);
	free_array(arr);
	return (check_push);
}



/**
 * first_function - first function
 * @f: file
 * @line_num: line number in the file
 * @opcode_p: opcode
 * Return: number indicating the error
 */
int first_function(FILE *f, int *line_num, char **opcode_p)
{
	char *line = NULL, *token, **arr;
	int i = 0, j = 2;
	size_t n = 0;
	stack_t *head = NULL;

	*line_num = 1;
	while (getline(&line, &n, f) != -1)
	{
		arr = malloc(sizeof(char *) * 3);
		if (arr == NULL)
			return (-1);
		token = strtok(line, " \n\t");
		for (i = 0; i < j; i++)
		{
			arr[i] = malloc(strlen(token) + 1);
			if (arr[i] == NULL)
			{
				free_array(arr);
				return (-1);
			}
			strcpy(arr[i], token);
			token = strtok(NULL, " \t\n");
			if (strcmp(arr[0], "push") == 0)
				j = 2;
			else
				j = 1;
		}
		arr[i] = NULL;
		*opcode_p = arr[0];
		check_opcode(arr, line_num, &head);

		*line_num += 1;
		}
	free_array(arr);
	free(line);
	free_list(&head);
	return (1); }

/**
 * main - main function
 * @argc: arguments Number
 * @argv: arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *f;
	char **opcode_p, *opcode;
	int *line_num_p, line_num = 0, check = 0;

	line_num_p = &line_num;
	opcode_p = &opcode;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f =  fopen(argv[1], "r");
	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	check = first_function(f, line_num_p, opcode_p);
	if (check == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
		exit(EXIT_FAILURE);
	}
	if (check == -1)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	fclose(f);
	return (0);
}
