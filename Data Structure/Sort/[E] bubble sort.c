#include <stdio.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

void bubble_sort(int list[], int n) {
	int i, j, temp;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
			}
		}
	}

	return;
}

int main() {
	int test[5] = { 3, 1, 0, 7, 5 };

	printf("======== Before sort ========\n");
	for (int i = 0; i < 5; i++) {
		printf("%d ", test[i]);
	}

	bubble_sort(test, 5);

	printf("\n\n======== After sort ========\n");
	for (int i = 0; i < 5; i++) {
		printf("%d ", test[i]);
	}

	return 0;
}