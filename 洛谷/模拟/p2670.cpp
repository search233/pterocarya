//P2670

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	char ch;
	int m, n;	cin >> m >> n;
	char **arr = new char*[m+2];
	for(int i=0 ; i<=m+1 ; ++i)
		arr[i] = new char[n+2]; 
	
	for(int i=1 ; i<=m ; ++i){
		for(int j=1 ; j<=n ; ++j){
			ch = getchar();
			if(ch=='\n'){
				j--;
				continue;
			} 
			if(ch=='*'){
				arr[i][j] = '*';
			}else arr[i][j] = '0';
		}
	}
	
	for(int i=1 ; i<=m ; ++i){
		for(int j=1 ; j<=n ; ++j){
			if(arr[i][j]=='*'){
				if(arr[i-1][j-1]!='*')	arr[i-1][j-1]++;  
				if(arr[i-1][j]!='*') 	arr[i-1][j]++;
				if(arr[i-1][j+1]!='*') 	arr[i-1][j+1]++;
				if(arr[i][j+1]!='*') 	arr[i][j+1]++;
				if(arr[i+1][j+1]!='*') 	arr[i+1][j+1]++;
				if(arr[i+1][j]!='*') 	arr[i+1][j]++;
				if(arr[i+1][j-1]!='*') 	arr[i+1][j-1]++;
				if(arr[i][j-1]!='*') 	arr[i][j-1]++;
			}
		}
	}	
	
	for(int i=1 ; i<=m ; ++i){
		for(int j=1 ; j<=n ; ++j){
			cout << arr[i][j];
		}
		cout << '\n';
	}	
	
	return 0;
}
