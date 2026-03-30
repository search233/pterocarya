//P5736

#include <iostream>

using namespace std;

int judge(int x){
	if(x<2) return 0;
	for(int i=2 ; i<=x/i ; ++i){
		if(x%i==0) return 0;
	}
	return 1;
}

int main()
{
	int n; cin >> n;
	int arr[100], cnt=0;
	
	for(int i=0 ; i<n ; ++i){
		int num; cin >> num;
		if(judge(num)){
			arr[cnt++] = num;
		}
	}
	
	for(int i=0 ; i<cnt ; ++i){
		cout << arr[i] << ' ';
	}
	
	return 0;
} 
