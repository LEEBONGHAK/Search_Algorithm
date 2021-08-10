#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int linear_search(int arr[], int len, int element) {
	for (int index = 0; index < len; index++) {
		if (arr[index] == element) {
			return index;
		}
	}

	return -1;
}

int main() {
	int arr[10] = { 2, 1, 3, 4, 8, 5, 9, 0, 7, 6 };
	int search;

	printf("Please input integer for searching : ");
	scanf("%d", &search);

	printf("result : %d\n", linear_search(arr, 10, search));
	
	return 0;
}