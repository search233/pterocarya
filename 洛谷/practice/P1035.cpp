//P1035

#include<iostream>
using namespace std;

int main(){
	
	double k;	cin >> k;
	double S=0;
	double i;
	
	for( i=1 ; S<=k ; i++){
		S += (1/i);
	}
	
	cout << --i << endl;
	return 0;
}
