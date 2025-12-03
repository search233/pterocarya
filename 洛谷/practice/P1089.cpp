//P1089

#include<iostream>
using namespace std;

int main(){
	int bank=0, budget;
	const int cash=300;
	int in_hand=0, tmp;
	
	for(int i=0 ; i<12 ; i++){
		cin >> budget;
		in_hand += cash;
		
		if(in_hand<budget){
			cout << "-" << i+1 << endl;
			return 0;
		} 
		
		in_hand -= budget;
		if(in_hand>100){
			tmp = in_hand / 100;
			in_hand %= 100;
			bank += tmp * 100;
		}
		
	}
	
	cout << bank * 1.2 + in_hand << endl;
	
	return 0;
}
