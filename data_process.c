#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game.h"
#define EPSILON 1e-7

typedef struct point {
	int x;
	int y;
} Point;

typedef struct vector {
	Point start;
	Point end;
} Vector;

void perm(const int in_use[], int comb[], int slot, int location, int prev_i);
int cal_area(Point* a, Point* b);
int dot_product(const Vector* vector1, const Vector* vector2);
double absolute(const Vector* vector);
int maxi(int a, int b) { return a >= b ? a : b; }

static int sum = 0;

int cal_show_score(const int board[], int location) {
	int present_turn = turn();
	int sum_score = 0;
	int comb[2] = { 0 };
	int in_use[BOARD_SIZE] = { 0 };

	if (present_turn == 1) {
		for (int i = 0; i < BOARD_SIZE; i++) {
			if (board[i] == '#') {
				in_use[i] = 1;
			}
		}
	}
	else {
		for (int i = 0; i < BOARD_SIZE; i++) {
			if (board[i] == 'O') {

				in_use[i] = 1;
			}
		}
	}

	if (step() > 6) {
		perm(in_use, comb, 0, location, 0);
		sum_score = sum;
	}
	else {
		sum_score = 0;
	}
	sum = 0;
	return sum_score;
}

int dot_product(const Vector* vector1, const Vector* vector2) {
	int result;
	result = (vector1->start.x - vector1->end.x) * (vector2->start.x - vector2->end.x) + \
		(vector1->start.y - vector1->end.y) * (vector2->start.y - vector2->end.y);
	return result;
}

double absolute(const Vector* vector) {
	double result;
	result = sqrt(((double)vector->start.x - vector->end.x) * ((double)vector->start.x - vector->end.x) \
				  + ((double)vector->start.y - vector->end.y) * ((double)vector->start.y - vector->end.y));
	return result;
}

void perm(const int in_use[], int comb[], int slot, int location, int prev_i) {
	if (slot == 2) {
		Vector m, n;
		int possible;
		int new_score = 0;
		m.start.x = n.start.x = location / 10;
		m.start.y = n.start.y = location % 10;
		m.end.x = comb[0] / 10;
		m.end.y = comb[0] % 10;
		n.end.x = comb[1] / 10;
		n.end.y = comb[1] % 10;
		possible = (m.end.x + n.end.x - n.start.x) * 10 + (m.end.y + n.end.y - n.start.y);
		if (possible >= 11 && possible <= 88 && possible % 10 && dot_product(&m, &n) == 0 \
			&& fabs(absolute(&m) - absolute(&n)) < EPSILON && in_use[possible]) {
			new_score = cal_area(&m.end, &n.end);
			if (turn() == 1) {
				printf("Blue gain %d more points by forming square {%d, %d, %d, %d}!\n", \
					   new_score, possible, location, comb[0], comb[1]);
			}
			else {
				printf("Red gain %d more points by forming square {%d, %d, %d, %d}!\n", \
					   new_score, possible, location, comb[0], comb[1]);
			}
		}
		sum += new_score;
	}
	else {
		int i;
		for (i = prev_i; i < BOARD_SIZE; i++) {
			if (in_use[i]) {
				comb[slot] = i;
				perm(in_use, comb, slot + 1, location, i + 1);
			}
		}
	}
}

int cal_area(Point* a, Point* b) {
	int area;
	int maximum = maxi(abs(a->x - b->x), abs(a->y - b->y));
	area = (maximum + 1) * (maximum + 1);
	return area;
}
