//selectsort

#include<iostream>
#include<vector>

using namespace	std;

int main(){
	vector<int> num;
	int n;	cin >> n;
	num.reserve(n);
	
	for(int i=0 ; i<n ; i++){
		cin >> num[i];
	}
	
	int tmp=0, min, t;
	
	for(int i=0 ; i<n ; i++){
		
		min = num[i];
		tmp = i;
		for(int j=i ; j<n ; j++){
			if(num[j]<min){
				min = num[j];
				tmp = j;
			}
			if(j==n-1){
				t = num[i];
				num[i] = num[tmp];
				num[tmp] = t;
			}
		}
	}
	
	for(int i=0 ; i<n ; i++){
		cout << num[i];
	}
	
	return 0;
}
