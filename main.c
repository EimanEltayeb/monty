#include "monty.h"
stack_s **head;

/**
 * psh - pushes element to stack
 * @arr: arguments array
 * Return: 0 if error and 1 if success
 */

int psh(char **arr)
{
	int i, n;

	if (arr[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", *line_num);
		exit(EXIT_FAILURE);
	}
	while (arr[1][i] != NULL)
	{
		if (arr[1][i] <= 48 || arr[1][i] >= 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", *line_num);
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(arr[1]);
	

}



/**
 * first_function - first function
 * @f: file
 * @line_number: line number in the file
 * @opcode: opcode
 * Return: number indicating the error 
 */
int first_function(FILE *f, int *line_num, char *opcode)
{
	char *line[256], *token, **arr;
	int i = 0;

	*line_num = 1;
	while (fgets(line, sizeof(line), f) != NULL)
	{
		arr = malloc(sizeof(line));
		if (arr == NULL)
			return (-1)
		token = strtok(line, " \t\n");
		while (token != NULL)
		{
			arr[i++] = strdup(token);
			token = strtok(NULL, " \t\n");
			arr[i] = NULL;
			if (i == 0)
			{
				free(arr);
				return (-1);
			}
		}
		*opcode = arr[0];
		if (strcmp(arr[0], "push") == 0)
			psh(arr[1]);





		*line_num++;
	}

}

/**
 * main - main function
 * @argc: arguments Number
 * @argv: arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *f;
	char *name, *opcode;
	int *line_num;
       
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
		fprint(stderr, "L%d: unknown instruction %s\n" *line_num, *opcode);
		exit(EXIT_FAILURE);
	}
	if (check == -1)
	{
		fprint(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	fclose(f);
	return (0);
}
