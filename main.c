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
 * @head: pointer to the list
 * Return: number indicating success or failure.
 */
int psh2(int n)
{
	stack_t *new;
	stack_t *temp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		return (-1);
	}
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		new->prev = NULL;
		return (1);
	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	new->prev = temp;
	return (1);
}

/**
 * psh - pushes element to stack
 * @arr: arguments array
 * @line_num: line number in monty file
 * Return: 0 if error and 1 if success
 */

int psh(char **arr, int *line_num)
{
	int i = 0, n, check_push;

	if (arr[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", *line_num);
		exit(EXIT_FAILURE);
	}
	while (arr[1][i] != '\0')
	{
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
	check_push = psh2(n);
	free_array(arr);
	return (check_push);
}



/**
 * first_function - first function
 * @f: file
 * @line_number: line number in the file
 * @opcode: opcode
 * Return: number indicating the error 
 */
int first_function(FILE *f, int *line_num, char **opcode)
{
	char line[256], *token, **arr;
	int i = 0;

	*line_num = 1;
	while (fgets(line, sizeof(line), f) != NULL)
	{
		arr = malloc(sizeof(char *) * 2);
		if (arr == NULL)
			return (-1);
		token = strtok(line, " \t\n");
		for (i = 0; i < 2; i++)
		{
			arr[i] = malloc(sizeof(char) * (strlen(token) + 1));
			arr[i] = strcpy(arr[i], token);
			token = strtok(NULL, " \t\n");
		}
		arr[i] = NULL;
		if (i == 0)
		{
			free(arr);
			return (-1);
		}
		*opcode = arr[0];
		if (strcmp(arr[0], "push") == 0)
			psh(arr, line_num);





		(*line_num)++;
	}
	return (1);
}

/**
 * main - main function
 * @argc: arguments Number
 * @argv: arguments
 * Return: 0
 */
stack_t **head = NULL;
int main(int argc, char *argv[])
{
	FILE *f;
	char *name = NULL, **opcode = NULL;
	int *line_num = 0, check = 0;
       
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	name = argv[1];
	f =  fopen(name, "r");
	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}
	check = first_function(f, line_num, opcode);
	if (check == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", *line_num, *opcode);
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
