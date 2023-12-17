#ifndef MONTY_H_
#define MONTY_H_
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;




int check_opcode(char **arr, int *line_num, stack_t **head);
void pll(stack_t **head);
int psh(char **arr, int *line_num, stack_t **head);
void free_list(stack_t **head);
void pnt(stack_t **head);
int ad(stack_t **head, int *line_num);







#endif
