//P1106

#include<iostream>
#include<string>
using namespace std;

int main(){
	string arr;
	cin >> arr;
	
	int k;	cin >> k;
	int len = arr.size();
	
	int temp;
	while(k){
		for(int i=0 ; i<len ; ++i){
			temp = i;
			if(arr[i] > arr[i+1]) break;
		}
		
		arr.erase(temp, 1);
		--k;
		--len;
	}
	
	while(arr[0]=='0' && len>1) 	arr.erase(0, 1);
		 
	cout << arr;
	
	return 0;
}

/*
1 3 3 5 6
1356
1335

1 6 2 3 5

*/
