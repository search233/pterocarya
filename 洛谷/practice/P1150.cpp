//P1150

#include<iostream>
using namespace std;

int main(){
	
	int n, k;	cin >> n >> k;
	int change=n, cnt=0; 
	
	while(change>=k){
		change -= k-1;
		cnt++;
	}
	
	cout << cnt + n << endl;
	
	return 0;
}
