//программа проверяет баланс открывающих и закрывающих скобочек

#include "stek.h"

int main(int argc, char *argv[]) {
	if(argc != 2) { 												//проверка аргументов командной строки
		fprintf(stderr, "Usage: programm needs two arguments\n");
		return EXIT_FAILURE;
	}

	FILE *f = fopen(argv[1], "r");
	if(f == NULL) { 												//открытие файла
		fprintf(stderr, "Usage: can't open the file\n");
		return EXIT_FAILURE;
	}

	struct node *top = NULL;
	char c = 0;

	while((c = fgetc(f)) != EOF) {
		if (is_open_bracked(c)) {
			int er = push(&top, c);
			if (er) {
				fprintf(stderr, "Usage: Trouble with memory\n");
				goto UNBALANCED;
				return EXIT_FAILURE;
			}
		}
		if (is_close_bracked(c)) {
			if( (peek(&top) == '{' && c == '}') ||
				(peek(&top) == '[' && c == ']') || 
				(peek(&top) == '(' && c == ')') ) {
				struct node *data = pop(&top);
				free(data);
			} else {
				goto UNBALANCED;
			}
		}
	}

	if (!top) {
		printf("your bracked is ok\n");
	} else {
UNBALANCED:		
		printf("Not ok\n");
		clear_node(top);
	}
	return EXIT_SUCCESS;
}
