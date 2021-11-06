#include <stdio.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

void selection_sort(int list[], int n) {
	int i, j, temp, least;

	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {
			if (list[least] > list[j]) {
				least = j;
			}
		}
		SWAP(list[i], list[least], temp);
	}
	return;
}

int main() {
	int test[5] = { 3, 1, 0, 7, 5 };

	printf("======== Before sort ========\n");
	for (int i = 0; i < 5; i++) {
		printf("%d ", test[i]);
	}

	selection_sort(test, 5);

	printf("\n\n======== After sort ========\n");
	for (int i = 0; i < 5; i++) {
		printf("%d ", test[i]);
	}

	return 0;
}