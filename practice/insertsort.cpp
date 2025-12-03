//insertsort

#include<iostream>

using namespace std;

int main(){
	
	int n;	cin >> n;
	int num[100]={0};
	for(int k=1 ; k<=n ; k++){
		cin >> num[k];
	}

	int j, i; 
	
	for(i=2 ; i<=n ; i++){
		num[0] = num[i];					//num[0]ÓÃÓÚÔİ´æ 
		
		for(j=i ; num[j-1]>num[0] ; j--){
			num[j] = num[j-1];
		}
		num[j] = num[0];
	}

	
	for(int k=1 ; k<=n ; k++){
		cout << num[k] << ' ';
	}
	
	return 0;
} 

