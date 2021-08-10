#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int binary_search(int arr[], int len, int element) {	// binary search를 쓰기 위해서는 배열이 정렬되어 있어야 한다.
	// initialization
	int l_index = 0;
	int r_index = len - 1;
	int m_index;

	while (l_index <= r_index) {
		m_index = r_index - (r_index - l_index) / 2;		// m_index = (r_index + l_index) / 2; 도 가능하지만 overflow 가능성 존재
		if (element < arr[m_index]) {
			r_index = m_index - 1;
		} 
		else if (element > arr[m_index]) {
			l_index = m_index + 1;
		}
		else {
			return m_index;
		}
	}

	return -1;	// error check
}

int binary_search_recursion(int arr[], int start, int end, int element) {
	// initialization
	int l_index = start;
	int r_index = end;
	int m_index = r_index - (r_index - l_index) / 2;

	if (l_index > r_index) {
		return -1;		// error check
	}
		
	if (element < arr[m_index]) {
		r_index = m_index - 1;
		binary_search_recursion(arr, l_index, r_index, element);
	}
	else if (element > arr[m_index]) {
		l_index = m_index + 1;
		binary_search_recursion(arr, l_index, r_index, element);
	}
	else {
		return m_index;
	}
}

int main() {
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int search;

	printf("Please input integer for searching : ");
	scanf("%d", &search);
	printf("result : %d\n", binary_search(arr, 10, search));
	printf("\n");


	printf("Please input integer for searching : ");
	scanf("%d", &search);
	printf("result : %d\n", binary_search_recursion(arr, 0, 9, search));
	printf("\n");

	return 0;
}