//P1152

#include<iostream>
#include<vector>
using namespace std;

int f(int a, int b);

int main(){
	int n;	cin >> n;
	int num[n];
	int list[n] = {0,};
	int tmp; 
	
	for(int i=0 ; i<n ; i++){
		cin >> num[i];
		if(i>0){
			tmp = f(num[i], num[i-1]);
			
			if(tmp<n){
				list[tmp] = 1;
			}
		}
	}

	for(int i=1 ; i<n ; i++){
		if(list[i]==0){
			cout << "Not jolly" << endl;
			break;
		}else if(i==n-1){
			cout << "Jolly" << endl; 
		}
	}
	
	return 0;
}

int f(int a, int b){
	int ret;
	if(a-b>0){
		ret = a-b;
	}else{
		ret = b-a;
	}
	return ret;
}
