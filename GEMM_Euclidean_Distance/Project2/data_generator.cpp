#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

#include "data_generator.h"
#include "config.h"

void matrix_brew_op(float* m, int w, int h)
{
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			m[i * w + j] = rand() / (float)(RAND_MAX);
		}
	}
}

void matrix_show(float* m, int w, int h, string name)
{
	cout << name << endl;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%f ", m[i * w + j]);
		}
		printf("\n");
	}
	printf("\n");
}

float** matrix_brew(config& c)
{
	float* m1 = (float*)malloc(sizeof(float) * c.M1_samples * c.dimensions);
	float* m2 = (float*)malloc(sizeof(float) * c.M2_samples * c.dimensions);

	matrix_brew_op(m1, c.dimensions, c.M1_samples);
	matrix_brew_op(m2, c.dimensions, c.M2_samples);
	if (c.data_show) {
		string m1_name("Matrix 1");
		string m2_name("Matrix 2");
		matrix_show(m1, c.dimensions, c.M1_samples, m1_name);
		matrix_show(m2, c.dimensions, c.M2_samples, m2_name);
	}

	float** matrixes = (float**)malloc(sizeof(float*) * 2);
	matrixes[0] = m1;
	matrixes[1] = m2;
	return matrixes;
}