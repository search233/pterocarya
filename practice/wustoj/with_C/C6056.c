//C6056

#include<stdio.h>

int main()
{
	char s[101][101];
	char ch;
	int n;
	
	scanf("%c %d", &ch, &n);
	getchar();
	
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			scanf("%c", &s[i][j]);
			if(s[i][j]=='@'){
				s[i][j] = ch;
			}
		}
		getchar();
	}
	
	for(int i=n-1 ; i>=0 ; i--)
	{
		for(int j=n-1 ; j>=0 ; j--)
		{
			if(s[i][j]!=s[n-1-i][n-1-j]){
				goto out;
			}
			if(i==0 && j==0){
				printf("bu yong dao le\n");
			}
		}
	}	
	
	out:
		
	
	for(int i=n-1 ; i>=0 ; i--)
	{
		for(int j=n-1 ; j>=0 ; j--){
			printf("%c", s[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
