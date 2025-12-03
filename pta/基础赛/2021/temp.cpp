#include <stdio.h>
 int main() {
    int n;
    scanf("%d", &n);
    // Upper part
    for (int i = 0; i < 3 * n; i++) {
        printf("*");
    }
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
    for (int i = 0; i < 3 * n; i++) {
        printf("*");
    }
    printf("\n");
    // Middle part
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%s", i == j ? "*" : " ");
        }
        for (int j = n + 1; j <= 3 * n; j++) {
            printf(" ");
        }
        for (int j = 3 * n + 1; j <= 3 * n + n / 2 - 1; j++) {
            printf("%s", j - i == 3 * n - 1 ? "*" : " ");
        }
        printf("  ");
        for (int j = 4 * n + 1 - n / 2 + 1; j <= 4 * n; j++) {
            printf("%s", i + j == 4 * n + 2 ? "*" : " ");
        }
        for (int j = 4 * n + 1; j <= 7 * n; j++) {
            printf("%s", i + j == 7 * n + 1 ? "*" : " ");
        }
        printf("\n");
    }
    // Lower part
    for (int i = n + 1; i <= 2 * n - 2; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%s", i + j == 2 * n ? "*" : " ");
        }
 
        for (int j = n + 1; j <= 3 * n; j++) {
            printf(" ");
        }
        for (int j = 3 * n + 1; j <= 3 * n + n / 2 - 1; j++) {
            printf("%s", i + j == 5 * n - 1 ? "*" : " ");
        }
        printf("  ");
        for (int j = 4 * n + 1 - n / 2 + 1; j <= 4 * n; j++) {
            printf("%s", j - i == 2 * n + 2 ? "*" : " ");
        }
        for (int j = 4 * n + 1; j <= 7 * n; j++) {
            printf("%s", j - i == 5 * n + 1 ? "*" : " ");
        }
        printf("\n");
    }
    // Bottom part
    for (int i = 0; i < 3 * n; i++) {
        printf("*");
    }
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
    for (int i = 0; i < 3 * n; i++) {
        printf("*");
    }
    printf("\n");
    return 0;
 }
