//P1008

#include<iostream>

using namespace std;


int main(){
	
	int i;
	
	for(i=123 ; i<329 ; i++) {
		
		int judge[10]={0,};
		int sum=0;
		
		for(int j=1 ; j<=3 ; j++){ 
			judge[i*j%10] = 1, judge[i*j/100] = 1,	judge[i*j%100/10] = 1;
		}
		
		for(int i=1 ; i<=9 ; i++){
			sum += judge[i];
		}
		
		if(sum==9)	cout << i << " " << i*2 << " " << i*3 << endl;
	}
	
	return 0;
}
