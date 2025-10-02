//bubblesort

#include <iostream>

using namespace std;

int main(){
	int n; cin >> n;
	int num[100]={0};
	
	for(int i=0 ; i<n ; ++i){
		cin >> num[i];
	}
	
	for(int i=0 ; i<n-1 ; ++i){
		int t, tag=0;
		
		for(int j=0 ; j<n-i-1 ; ++j){
			if(num[j]>num[j+1]){
				tag=1;
				t=num[j];
				num[j]=num[j+1];
				num[j+1]=t;
			}
		}
		if(!tag) break;
	}
	
	for(int i=0 ; i<n ; ++i){
		cout << num[i] << ' ';
	}
} 
