//C6079

#include <iostream>

using namespace std;

char list[1000][1000];

int main(){
	int n; cin >> n;
	char ch='a';
	
	for(int i=0 ; i<n ; ++i){

		if(i%2==0){
			for(int j=0 ; j<n ; ++j){
				list[i][j] = ch++;
				if(ch>'z') ch='a';
			}
		}else{
			for(int j=n-1 ; j>=0 ; --j){
				list[i][j] = ch++;
				if(ch>'z') ch='a';				
			}
		}  
	}
	
	for(int i=0 ; i<n ; ++i){
		for(int j=n-1 ; j>=0 ; --j){
			if(j==n-1) cout << list[j][i];
			else cout << ' ' << list[j][i];
		}
		cout << '\n';
	}
	
	return 0;
}
