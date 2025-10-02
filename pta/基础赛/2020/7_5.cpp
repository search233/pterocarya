//7_5

#include<stdio.h>
#include<string.h>

int main()
{
	char arr[11];
	
	scanf("%s", arr);
	
	int len = strlen(arr) - 1;
	
	printf("%c %c", arr[0], arr[len]);
	
	return 0;
}
