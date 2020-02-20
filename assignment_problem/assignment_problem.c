#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef enum { NO, YES } BOOL;

#define MAX 10

int n;

int arr[MAX][MAX]; // Array

BOOL mass[MAX][MAX]; // Maximum assignment

int minvalue = INT_MAX;

void calculateCurrentCost (BOOL ass[MAX][MAX]) {
	int cost = 0;
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (ass[i][j]) {
				cost += arr[i][j];
			}
		}
	}
	if (cost < minvalue) {
		minvalue = cost;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				mass[i][j] = ass[i][j];
			}
		}
	}
}

void printass (BOOL ass[MAX][MAX]) {
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			printf(" %d", ass[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void assign (BOOL ass[MAX][MAX], int k) {
	if (k == n) {
		printass(ass);
		return;
	}
	int i, j;
	BOOL mask[MAX];
	for (i = 0; i <= k; ++i) {
		for (j = 0; j < n; ++j) {
			mask[i] = mask[i] || ass[i][j];
		}
		printf("%d ", mask[i]);
	}
	printf("\n");
	for (i = k; i < n; ++i) {
		if (!mask[i]) {
			ass[k][i] = YES;
			assign(ass, k+1);
			ass[k][i] = NO;
		}
	}
}

int main (int argc, const char *argv []) {

	BOOL ass[MAX][MAX];
	n = 3;

	assign(ass, 0);

}