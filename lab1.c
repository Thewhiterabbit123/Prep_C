//программа считает дисперсию вхождений слова в файл
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define MAX 128

struct lol {
	int mass[MAX];
	int N;
	int summ;
};

int check(int i) {
	if (i>MAX) {
		puts("error: value bigger than MAX");
		return EXIT_FAILURE;   //надо как-нибудь в мейне обрабоать значения
	}
	return 1;
} 

static bool is_word_separator(char c) {
	return isspace(c) || ispunct(c);
}

static bool is_sentence_separator(char c) {
	return (c == '!' || c == '?' || c == '.');
}

static double dispersion(struct lol *p) {
	int i = 0; 
	double a = 0;
	double b = p->summ/p->N;

	for(i = 0; i < p->N; i++) {
		a += p->mass[i] - b;
	}

	double D = sqrt(a / (p->N - 1));
	return D;
}

int main(int argc, char *argv[]) {
	if(argc != 3) {
		printf("Usage: program needs three arguments\n");
		return EXIT_FAILURE;
	}

	char *word_to_look = (char *) malloc(strlen(argv[1])+1); //ваще не надо

	if (word_to_look==NULL) {
		printf("Memory allocation error\n");
		return EXIT_FAILURE;
	}

	strcpy(word_to_look, argv[1]); //можно использовать аргв один, лол

	FILE *f;

	if((f = fopen(argv[2], "r")) == NULL)
	{
		printf("Usage: can't open the file\n");
		return EXIT_FAILURE;
	}

	struct lol word = {0};
	char buff[MAX]={0}; 
	int c, k = 0;
	int i = 0, j = 0;

	while ((c=fgetc(f))!=EOF) {	
		if(( is_sentence_separator(k) && is_sentence_separator(c) ) || ( is_word_separator(c) && is_word_separator(k) ))
			;
		else {
			if(!is_word_separator(c) && !is_sentence_separator(c)) {
				check(i);
				buff[i] = c;
				++i;  //все еще переполнение буфера
			}

			if(is_sentence_separator(c) || is_word_separator(c)) {
				if (!strcmp(buff, word_to_look)) {
					word.summ++;
					word.mass[j]++;
				}
				memset(buff,0,MAX*sizeof(char));
				i=0;				
			}
		
			if (is_sentence_separator(c)) {
				check(j);
				++j;
				word.N++;
			}
		} 
		k = c;
	}

	printf("Dispersion = %f\n",dispersion(&word));
	free(word_to_look);
	close(f);
}
