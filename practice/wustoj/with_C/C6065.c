//C6065

#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int A[n + 1], temp, cnt = 0, tag;

	for (int i = 0 ; i < n ; i++) {
		scanf("%d", &A[i]);
	}
	
	if(n==1){
		printf("%d", A[0]);
		return 0;
	}

	while (cnt < n-1) {
		for (int i = cnt; i < n ; i++) {

			if (i == cnt) {
				temp = A[i];
				tag = i;
			} else if (A[i] < temp) {
				temp = A[i];
				tag = i;
			}
		}
		
		A[tag] = A[cnt];
		A[cnt++] = temp;

		for (int i = 0 ; i < n ; i++) {
			if (i == 0) {
				printf("%d", A[i]);
			} else {
				printf(" %d", A[i]);
			}
		}
		printf("\n");
	}

	return 0;
}
