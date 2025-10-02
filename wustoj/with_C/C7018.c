//C7018

#include<stdio.h>
int Fun(char[]);
int main()
{
    char str[8];
    int ans;
    scanf("%s",str);
    ans=Fun(str);
    printf("%d\n",ans);
    return 0;
}
int Fun(char str[])
{
	int number = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			number = number * 16 + str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			number = number * 16 + str[i] - 'a' + 10;
		else
			number = number * 16 + str[i] - 'A' + 10;
	}
	return number;
}
