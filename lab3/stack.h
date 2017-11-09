#ifndef STEK
#define STEK

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node {   //стэк
	char data;
	struct node *next;
};

static bool is_open_bracked(char c) {
	return (c == '{' || c =='[' || c == '(');
}

static bool is_close_bracked(char c) {
	return (c == '}' || c ==']' || c == ')');
}

void clear_node(struct node *top) {
	struct node *tmp;
	while(top != NULL) {
		tmp = top->next;
		free(top);
		top = tmp;
	}
}

int push(struct node **top, char d) {
	struct node *tmp = malloc(sizeof(*tmp));
	if(tmp == NULL) {
		return EXIT_FAILURE;
	}
	tmp->data = d;
	tmp->next = *top;
	*top = tmp;
	return EXIT_SUCCESS;
}

char peek(struct node **top) {
	if (*top != NULL) {
		return (*top)->data;
	}
	return EXIT_SUCCESS;
}

struct node *pop(struct node **top) {
	struct node *cur_node;
	cur_node = *top;
	*top = (*top)->next;
	return cur_node;
}


#endif 
