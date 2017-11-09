//программа считает L-норму матрицы

#include <stdio.h>
#include <stdlib.h>
//чистить память после каждого ехит фаилюр. можно го ту, либо отдельной функцией
double get_elem(double** matrix, int row, int col) {
	return(matrix[row][col]);
}

void set_elem(double** matrix, int row, int col, double val) {
	matrix[row][col]=val;
}

double L_norm(double** matrix, int rows_n, int cols_n) {
	double  norm = 0;

	for (int i = 0; i < rows_n; i++) {
		double temp = 0;

		for (int j = 0; j < cols_n; j++) {
			temp += get_elem(matrix, j, i);
		}

		if (temp > norm) {
			norm = temp;
		}
	}

	return norm;
}

int main(int argc, char* argv[]) {

	if(argc != 2) { //проверка аргументов командной строки
		fprintf(stderr, "Usage: programm needs two arguments\n");
		return EXIT_FAILURE;
	}

	FILE *f;

	if((f=fopen(argv[1], "r")) == NULL) { //открытие файла
		fprintf(stderr, "Usage: can't open the file\n");
		return EXIT_FAILURE;
	}

	int rows_n = 0, cols_n = 0;
	int col = 0,
		rows_m = 0, cols_m = 0;
	double num = 0;

	if(fscanf(f, "%d%d%d", &rows_n, &cols_n, &col) != 3) { 
		fprintf(stderr, "Not enought values\n");
		return EXIT_FAILURE;
	}

	double **matrix = calloc(rows_n, sizeof(double*)*rows_n); //выделение памяти

	if (!matrix) {
		fprintf(stderr, "Not enought memory");
		return EXIT_FAILURE;
	}

	for(int i = 0; i < rows_n; ++i) {
		matrix[i] = calloc(cols_n, sizeof(double)*cols_n);

		if (!matrix[i]) {
			fprintf(stderr, "Not enought memory");
			return EXIT_FAILURE;
		}
	}

	for(int i = 0; i < col; i++) {	
		if(fscanf(f, "%d %d %lf", &rows_m, &cols_m, &num) != 3) {
			fprintf(stderr, "Not enought values\n");
			return EXIT_FAILURE;
		}

		if((rows_m >= rows_n || cols_m >= cols_n)||(rows_m < 0)||(cols_m < 0)) {
			fprintf(stderr, "The index of elements bigger, then size of matrix\n");
			return EXIT_FAILURE;
		}
		set_elem(matrix, rows_m, cols_m, num);
	}

	fclose(f);

	for(int i = 0; i < rows_n; ++i) {
		for(int j = 0; j < cols_n; ++j) {
			printf("%.2f  ", matrix[i][j]);
		}
		printf("\n");
	}

	printf("%.2f\n", L_norm(matrix, rows_n, cols_n));

	for(int i = 0; i < rows_n; ++i) {
		free(matrix[i]);
	}
	free(matrix);
	return EXIT_SUCCESS;
	//id software стайлгайд
}
