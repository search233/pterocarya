//qsort

#include <iostream>
#include <cstdlib>

using namespace std;

int comp(const void *a, const void *b);

int main(){
	int n; cin >> n;
	int num[100]={0};
	
	for(int i=0 ; i<n ; ++i){
		cin >> num[i];
	}
	
	qsort(num, n, sizeof(int), comp);
	
	for(int i=0 ; i<n ; ++i){
		cout << num[i] << ' ';
	}
	
	return 0;
} 

int comp(const void *a, const void *b){
	
	const int* int_a = (const int*) a;
	const int* int_b = (const int*) b;
	
	return *int_a - *int_b;				//小到大->前减后 
}
