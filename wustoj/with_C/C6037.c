//C6037

#include<stdio.h>

int main() {
	int Ra, Rb, Ca, Cb;

	scanf("%d %d", &Ra, &Ca);

	int A[Ra][Ca];

	for (int i = 0 ; i < Ra ; i++) {
		for (int j = 0 ; j < Ca ; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	scanf("%d %d", &Rb, &Cb);

	int B[Rb][Cb];

	for (int i = 0 ; i < Rb ; i++) {
		for (int j = 0 ; j < Cb ; j++) {
			scanf("%d", &B[i][j]);
		}
	}

	if (Ca != Rb) {
		printf("Error: %d != %d", Ca, Rb);
		return 0;
	}

	int AB[Ra][Cb];

	for (int i = 0 ; i < Ra ; i++) {
		for (int j = 0 ; j < Cb ; j++) {
			AB[i][j] = 0;
			for (int k = 0 ; k < Ca ; k++) {
				AB[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	printf("%d %d\n", Ra, Cb);

	for (int i = 0 ; i < Ra ; i++) {
		for (int j = 0 ; j < Cb ; j++) {
			if (j == 0) {
				printf("%d", AB[i][j]);
			} else {
				printf(" %d", AB[i][j]);
			}
		}
		printf("\n");
	}

	return 0;
}
