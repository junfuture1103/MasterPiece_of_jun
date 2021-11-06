#include <stdio.h>

void insertion_sort(int list[], int n) {
	int i, j, key;

	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}
	return;
}

int main() {
	int test[5] = { 3, 1, 0, 7, 5 };

	printf("======== Before sort ========\n");
	for (int i = 0; i < 5; i++) {
		printf("%d ", test[i]);
	}

	insertion_sort(test, 5);

	printf("\n\n======== After sort ========\n");
	for (int i = 0; i < 5; i++) {
		printf("%d ", test[i]);
	}

	return 0;
}