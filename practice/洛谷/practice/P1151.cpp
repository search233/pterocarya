//P1151

#include<iostream>
using namespace std;

int main(){
	int k;	cin >> k;
	int sub1, sub2, sub3;
	int a[5];
	bool flag = 0;
	
	for(int i=10000 ; i<=30000 ; i++){
		
		int temp=i;
		for(int j=0 ; j<5 ; j++){
			a[j] = temp % 10;
			temp /= 10;
		}

		sub3 = a[2] *100 + a[1] *10 + a[0];
		sub2 = a[3] *100 + a[2] *10 + a[1];
		sub1 = a[4] *100 + a[3] *10 + a[2];
		if(sub1%k==0 && sub2%k==0 && sub3%k==0){
			cout << i << endl;
			flag = 1;
		} 
	}
	
	if(!flag){
		cout << "No" << endl;
	}
	
	return 0;	 
}
